/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:58:37 by lchapren          #+#    #+#             */
/*   Updated: 2020/08/21 11:09:18 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

float	*rotate_direction(float direction_x, float direction_y, float angle)
{
	float *new_direction;

	if (!(new_direction = ft_calloc(sizeof(float), 2)))
		calloc_error();
	new_direction[0] = (direction_x * cos((angle * PI) / 180.0)) -
		(direction_y * sin((angle * PI) / 180.0));
	new_direction[1] = (direction_x * sin((angle * PI) / 180.0)) +
		(direction_y * cos((angle * PI) / 180.0));
	return (new_direction);
}

double	get_distance(t_ray ray, t_player player)
{
	double distance;

	if (ray.hit_side == 0)
		distance = (double)fabs(((double)ray.map_x - player.pos_x + \
					(1.0 - (double)ray.step_x) / 2.0) / ray.raydir_x);
	else
		distance = (double)fabs(((double)ray.map_y - player.pos_y + \
					(1.0 - (double)ray.step_y) / 2.0) / ray.raydir_y);
	return (distance);
}

void	get_sprite(t_ray *ray, t_player player, t_map map)
{
	int i;

	i = get_sprite_index(ray->sp_list, map, ray->map_x, ray->map_y);
	if (ray->sp_list[i].on_screen == 0)
	{
		ray->sp_list[i].distance = get_distance(*ray, player);
		ray->sp_list[i].on_screen = 1;
	}
}
