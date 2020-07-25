/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:23:51 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/25 15:04:19 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	get_sprite_list(t_ray *ray, t_player, t_map_map)
{
	int	a;
	int	i;
	int	j;

	a = 0;
	i = 0;
	ray->sp_list = ft_calloc(sizeof(*t_sp), map.sprites_count);
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == '2')
			{
				ray->sp_list[a].x = i + 0.5;
				ray->sp_list[a].y = j + 0.5;
				ray->sp_list[a].distance = sqrt(pow(player.position_x - \
				sp_list[a].x, 2) + pow(player.position_y - ray->sp_list[a].y, 2);
				a++;
			}
			j++;
		}
		i++;
	}
}

void	sort_sprite_list(t_ray *ray, t_map map)
{
	int		i;
	int		j;
	int		a;
	int		i_max;
	t_sp	*copy;

	i = 0;
	a = 0;
	copy = ft_calloc(sizeof(*t_sp), map.sprites_count)
	while (i < map.sprites_count)
	{
		j = 0;
		max = 0.0;
		while (j < map.sprites_count)
		{
			if (ray->sp_list[j].distance > max)
				max = ray->sp_list[j].distance;
			j++;
		}
		copy[a]

	}
}

