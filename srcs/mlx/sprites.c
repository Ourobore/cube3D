/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:23:51 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/27 15:07:51 by lchapren         ###   ########.fr       */
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
	ray->sp_list = ft_calloc(sizeof(*ray->sp_list), map.sprite_count);
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

void	draw_sprite(t_mlx *mlx, t_ray *ray, t_player player, t_map map)
{
	int	i;
	int	x;
	int	y;
	int d;
	int	draw_start_x;
	int	draw_start_y;
	int	draw_end_x;
	int	draw_end_y;
	int	sprite_screen_x;
	float	invdet;
	float	transform_x;
	float	transform_y;

	invdet = 1.0 / (player.plane_x * player.direction_y - player.direction_x * player.plane_y);
	while ((i = get_farest_visible_sprite(ray->sp_list, map)) != -1)
	{
		//printf("SPRITE I: %d DISTANCE: %f X: %f Y: %f\n", i, ray->sp_list[i].distance, ray->sp_list[i].map_x, ray->sp_list[i].map_y);
		ray->sp_list[i].x = ray->sp_list[i].map_x - player.position_x;
		ray->sp_list[i].y = ray->sp_list[i].map_y - player.position_y;
		transform_x = invdet * (player.direction_y * ray->sp_list[i].x - player.direction_x * ray->sp_list[i].y);
		transform_y = invdet * (-player.plane_y * ray->sp_list[i].x + player.plane_x * ray->sp_list[i].y);
		sprite_screen_x = (int)((map.resolution[0] / 2) * (1 + transform_x / transform_y));
		
		ray->sp_list[i].height = abs((int)(map.resolution[1] / transform_y)) / 2 ;// derniere divivion par deux pour changer la taille
		draw_start_y = -ray->sp_list[i].height / 2 + map.resolution[1] / 2;
		if (draw_start_y < 0)
			draw_start_y = 0;
		draw_end_y = ray->sp_list[i].height / 2 + map.resolution[1] / 2;
		if (draw_end_y >= map.resolution[1])
			draw_end_y = map.resolution[1] - 1;
		draw_start_x = -ray->sp_list[i].height / 2 + sprite_screen_x;
		if (draw_start_x < 0)
			draw_start_x = 0;
		draw_end_x = ray->sp_list[i].height / 2 + sprite_screen_x;
		if (draw_end_x >= map.resolution[0])
			draw_end_x = map.resolution[0] - 1;

		x = draw_start_x;
		while (x < draw_end_x)
		{
			ray->tex_x = (int)(256 * (x - (-ray->sp_list[i].height / 2 + sprite_screen_x)) * ray->tex_width / ray->sp_list[i].height) / 256;
			if (transform_y > 0 && x > 0 && x < map.resolution[0] && transform_y < ray->buff_dist[x])
			{
				y = draw_start_y;
				while (y < draw_end_y)
				{
					d = y * 256 - map.resolution[1] * 128 + ray->sp_list[i].height * 128;
					ray->tex_y = ((d * ray->tex_height) / ray->sp_list[i].height) / 256;
					if (ray->tex_sprite[(int)(ray->tex_width * ray->tex_y + ray->tex_x)] != 0x000001)
						mlx->image_data[y * map.resolution[0] + x] = ray->tex_sprite[(int)(ray->tex_width * ray->tex_y + ray->tex_x)];
					y++;
				}
			}
			x++;
		}
		ray->sp_list[i].on_screen = 0;
	}
}
