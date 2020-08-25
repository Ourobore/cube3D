/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:23:51 by lchapren          #+#    #+#             */
/*   Updated: 2020/08/25 12:09:08 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	get_sprite_list(t_ray *ray, t_player player, t_map map)
{
	int	a;
	int	i;
	int	j;

	a = 0;
	i = 0;
	if (!(ray->sp_list = ft_calloc(sizeof(*ray->sp_list), map.sprite_count)))
		calloc_error();
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == '2')
			{
				ray->sp_list[a].map_x = i + 0.5;
				ray->sp_list[a].map_y = j + 0.5;
				ray->sp_list[a].on_screen = 0;
				a++;
			}
			j++;
		}
		i++;
	}
}

int		get_sprite_index(t_sp *list, t_map map, int map_x, int map_y)
{
	int index;

	index = 0;
	while (index < map.sprite_count)
	{
		if ((int)list[index].map_x == map_x && (int)list[index].map_y == map_y)
			return (index);
		index++;
	}
	return (-1);
}

int		get_farest_visible_sprite(t_sp *list, t_map map)
{
	int		i;
	int		index;
	float	max;

	i = 0;
	index = -1;
	max = 0.0;
	while (i < map.sprite_count)
	{
		if (list[i].on_screen && list[i].distance >= max)
		{
			max = list[i].distance;
			index = i;
		}
		i++;
	}
	return (index);
}

void	get_sprite_position(t_ray *ray, t_map map, t_player player, int i)
{
	ray->invdet = 1.0 / (player.plane_x * player.dir_y - \
					player.dir_x * player.plane_y);
	ray->sp_list[i].x = ray->sp_list[i].map_x - player.pos_x;
	ray->sp_list[i].y = ray->sp_list[i].map_y - player.pos_y;
	ray->real_x = ray->invdet * (player.dir_y * ray->sp_list[i].x - \
					player.dir_x * ray->sp_list[i].y);
	ray->real_y = ray->invdet * (-player.plane_y * ray->sp_list[i].x + \
					player.plane_x * ray->sp_list[i].y);
	ray->sp_list[i].height = fabs((map.res[1] / ray->real_y) / 2);
	ray->sprite_screen_x = (map.res[0] / 2) * (1 + ray->real_x / ray->real_y);
	ray->move_sprite = (ray->tex_height / 110.0) * map.res[1] / ray->real_y;
	ray->start_y = -ray->sp_list[i].height / 2 + map.res[1] / player.height + \
					ray->move_sprite;
	if (ray->start_y < 0)
		ray->start_y = 0;
	ray->end_y = ray->sp_list[i].height / 2 + map.res[1] / player.height + \
					ray->move_sprite;
	if (ray->end_y >= map.res[1])
		ray->end_y = map.res[1];
	ray->start_x = -ray->sp_list[i].height / 2 + ray->sprite_screen_x;
	if (ray->start_x < 0)
		ray->start_x = 0;
	ray->end_x = ray->sp_list[i].height / 2 + ray->sprite_screen_x;
	if (ray->end_x >= map.res[0])
		ray->end_x = map.res[0];
}

void	draw_sprite(t_mlx *mlx, t_ray *ray, t_player player, t_map map)
{
	int		i;

	while ((i = get_farest_visible_sprite(ray->sp_list, map)) != -1)
	{
		get_sprite_position(ray, map, player, i);
		ray->x = ray->start_x - 1;
		while (++ray->x < ray->end_x)
		{
			ray->tex_x = (ray->x - (-ray->sp_list[i].height / 2 + \
ray->sprite_screen_x)) * ray->tex_width / ray->sp_list[i].height;
			if (ray->real_y > 0 && ray->x >= 0 && ray->x < map.res[0] && \
ray->real_y < ray->buff_dist[ray->x] && (ray->y = ray->start_y - 1))
				while (++ray->y < ray->end_y)
				{
					ray->tex_y = (((int)((ray->y - ray->move_sprite) * 256 - \
map.res[1] * (2 / player.height) * 128 + ray->sp_list[i].height * 128) * \
ray->tex_height) / ray->sp_list[i].height) / 256;
					if (ray->tex_sprite[(int)(ray->tex_width * \
ray->tex_y + ray->tex_x)] != 0x000001)
						mlx->image_data[ray->y * map.res[0] + ray->x] = \
ray->tex_sprite[(int)(ray->tex_width * ray->tex_y + ray->tex_x)];
				}
		}
		ray->sp_list[i].on_screen = 0;
	}
}
