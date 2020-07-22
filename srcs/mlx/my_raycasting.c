/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 09:34:40 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/22 12:55:11 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	raycasting(t_data *data, t_player *player, t_ray *ray, t_map map)
{
	int column;
	float camera_x;

	column = 0; // est present dans t_ray sous le nom de wall_x;
	*data = new_image(*data);
	while (column < map.resolution[0])
	{
		camera_x = (2.0 * column / (float)map.resolution[0]) - 1.0; //puis je enlever la -> sur player?
		ray->raydir_x = player->direction_x + /*0.0*/player->plane_x * camera_x;
		ray->raydir_y = player->direction_y + /*0.66*/player->plane_y * camera_x;
		ray->delta_x = fabs(1 / ray->raydir_x);
		ray->delta_y = fabs(1 / ray->raydir_y);
		ray->map_x = (int)player->position_x;
		ray->map_y = (int)player->position_y;
		get_steps(player, ray);
		get_wall(ray, map, *player);
		if (!ray->textures && data->bonus)
			draw_untextured(&(data->mlx), *ray, *player, map, column);
		else
			printf("YAPASDEPANNEAUX!!!\n");
			//draw_textured(ray);
		//draw_sprites();
		column++;
	}
	player->last_pos_x = player->position_x; // faire une fonction qui actualise la position
    player->last_pos_y = player->position_y;
    player->last_dir_x = player->direction_x;
    player->last_dir_y = player->direction_y;
    mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.window_ptr, \
							data->mlx.image, 0, 0);
}

void	get_steps(t_player *player, t_ray *ray)
{
	if (ray->raydir_x < 0.0)
	{
		ray->step_x = -1;
		ray->side_x = (player->position_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - player->position_x) * ray->delta_x;
	}
	if (ray->raydir_y < 0.0)
	{
		ray->step_y = -1;
		ray->side_y = (player->position_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - player->position_y) * ray->delta_y;
	}
}

void	get_wall(t_ray *ray, t_map map, t_player player)
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
		if (map.map[ray->map_x][ray->map_y] == '1')
			break;
	}
	if (ray->hit_side == 0)
		ray->wall_distance = fabs((ray->map_x - player.position_x + \
						(1.0 - ray->step_x) / 2.0) / ray->raydir_x);
	else
		ray->wall_distance = fabs((ray->map_y - player.position_y + \
						(1.0 - ray->step_y) / 2.0) / ray->raydir_y);
	ray->wall_height = (int)(map.resolution[1] / ray->wall_distance);
}

void	draw_untextured(t_mlx *mlx, t_ray ray, t_player player, t_map map, int column)
{
	int		i;
	int 	draw_start;
	int		draw_end;

	if ((draw_start = -ray.wall_height / player.height + map.resolution[1] / player.height) < 0)
		draw_start = 0;
	if ((draw_end = ray.wall_height / player.height + map.resolution[1] / player.height) < 0)
		draw_end = map.resolution[1] - 1;
	i = 0;
	while (i < map.resolution[1])
    {
        if (i > draw_start && i < draw_end && ray.hit_side == 0)
            mlx->image_data[column + (i * map.resolution[0])] = 16777215;
        else if (i > draw_start && i < draw_end && ray.hit_side == 1)
            mlx->image_data[column + (i * map.resolution[0])] = 13158600;
        else
        {
            if (i > map.resolution[1] / 2)
                mlx->image_data[column + (i * map.resolution[0])] = (map.ceiling_color[2] * 65536) + (map.ceiling_color[1] * 256) + map.ceiling_color[0];
            else
                mlx->image_data[column + (i * map.resolution[0])] = (map.floor_color[2] * 65536) + (map.floor_color[1] * 256) + map.floor_color[0];
		}
        i++;
    }
}
