/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:58:37 by lchapren          #+#    #+#             */
/*   Updated: 2020/08/12 14:28:41 by lchapren         ###   ########.fr       */
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

int		player_moved(t_data *data)
{
	if (data->player.last_pos_x == data->player.pos_x && \
			data->player.last_pos_y == data->player.pos_y && \
			data->player.last_dir_x == data->player.dir_x && \
			data->player.last_dir_y == data->player.dir_y)
		return (0);
	else
		return (1);
}

float	get_distance(t_ray ray, t_player player)
{
	float distance;

	if (ray.hit_side == 0)
		distance = fabs((ray.map_x - player.pos_x + \
					(1.0 - ray.step_x) / 2.0) / ray.raydir_x);
	else
		distance = fabs((ray.map_y - player.pos_y + \
					(1.0 - ray.step_y) / 2.0) / ray.raydir_y);
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

void	draw_ceiling_floor(t_mlx *mlx, t_ray ray, t_player player, t_map map, int i)
{//this function makes me lag really hard
	if (i < map.res[1] / player.height)
		mlx->image_data[ray.column + (i * map.res[0])] = \
		(map.ceil_color[0] << 16) + (map.ceil_color[1] << 8) + map.ceil_color[2];
	else
		mlx->image_data[ray.column + (i * map.res[0])] = \
		(map.floor_color[0] << 16) + (map.floor_color[1] << 8) + map.floor_color[2];
}
