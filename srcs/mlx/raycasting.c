/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:57:58 by lchapren          #+#    #+#             */
/*   Updated: 2020/08/21 15:36:14 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	raycasting(t_data *data, t_player *player, t_ray *ray, t_map map)
{
	float	camera_x;

	ray->column = 0;
	*data = new_image(*data);
	ray->buff_dist = ft_calloc(sizeof(ray->buff_dist), map.res[0]);
	while (ray->column < map.res[0])
	{
		camera_x = (2.0 * (double)ray->column / map.res[0]) - 1.0;
		ray->raydir_x = player->dir_x + player->plane_x * camera_x;
		ray->raydir_y = player->dir_y + player->plane_y * camera_x;
		get_steps(player, ray);
		get_wall(*data, ray, map, *player);
		ray->buff_dist[ray->column] = ray->wall_distance;
		if (ray->textures < 0)
			draw_untextured(&(data->mlx), *ray, *player, map);
		else
			draw_textured(&(data->mlx), *ray, *player, map);
		ray->column++;
	}
	draw_sprite(&(data->mlx), ray, *player, map);
	free(ray->buff_dist);
	ray->buff_dist = NULL;
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.window_ptr, \
							data->mlx.image, 0, 0);
}

void	get_steps(t_player *player, t_ray *ray)
{
	ray->delta_x = fabs(1 / ray->raydir_x);
	ray->delta_y = fabs(1 / ray->raydir_y);
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (player->pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - player->pos_x) * ray->delta_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (player->pos_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_y;
	}
}

void	get_wall(t_data data, t_ray *ray, t_map map, t_player player)
{
	while (1)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->hit_side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->hit_side = 1;
		}
		if (map.map[ray->map_x][ray->map_y] == '2')
			get_sprite(ray, player, map);
		if (map.map[ray->map_x][ray->map_y] == '1' || \
			(map.map[ray->map_x][ray->map_y] == '3' && data.bonus))
			break ;
	}
	ray->wall_distance = get_distance(*ray, player);
	ray->wall_height = (double)fabs((double)map.res[1] / ray->wall_distance);
}

void	draw_untextured(t_mlx *mlx, t_ray ray, t_player player, t_map map)
{
	int		i;
	int		start;
	int		end;

	if ((start = -ray.wall_height / 2 + map.res[1] / player.height) < 0)
		start = 0;
	if ((end = ray.wall_height / 2 + map.res[1] / player.height) > map.res[1])
		end = map.res[1] - 1;
	i = -1;
	while (++i < map.res[1])
	{
		if (i > start && i < end && ray.hit_side == 0)
			mlx->image_data[ray.column + (i * map.res[0])] = 16777215;
		else if (i > start && i < end && ray.hit_side == 1)
			mlx->image_data[ray.column + (i * map.res[0])] = 13158600;
		else
		{
			if (i < map.res[1] / player.height)
				mlx->image_data[ray.column + (i * map.res[0])] = \
(map.ceil_color[0] << 16) + (map.ceil_color[1] << 8) + map.ceil_color[2];
			else
				mlx->image_data[ray.column + (i * map.res[0])] = \
(map.floor_color[0] << 16) + (map.floor_color[1] << 8) + map.floor_color[2];
		}
	}
}

void	draw_textured(t_mlx *mlx, t_ray ray, t_player player, t_map map)
{
	double	wall_x;

	if (ray.hit_side == 0)
		wall_x = player.pos_y + ray.wall_distance * ray.raydir_y;
	else
		wall_x = player.pos_x + ray.wall_distance * ray.raydir_x;
	wall_x -= floor(wall_x);
	ray.tex_x = (int)(wall_x * (double)(ray.tex_width));
	if ((ray.hit_side == 0 && ray.raydir_x > 0) || \
		(ray.hit_side == 1 && ray.raydir_y < 0))
		ray.tex_x = ray.tex_width - ray.tex_x - 1;
	if ((ray.start_y = -ray.wall_height / 2.0 + map.res[1] / player.height) < 0)
		ray.start_y = 0;
	if ((ray.end_y = ray.wall_height / 2.0 + map.res[1] / player.height) \
															>= map.res[1])
		ray.end_y = map.res[1] - 1;
	ray.tex_step = 1.0 * (double)ray.tex_height / ray.wall_height;
	ray.tex_pos = (ray.start_y - map.res[1] / player.height + \
					ray.wall_height / 2.0) * ray.tex_step;
	select_texture(&ray, player);
	textured_loop(mlx, ray, player, map);
}
