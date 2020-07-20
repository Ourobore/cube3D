/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 09:34:40 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/20 13:01:02 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

t_data	raycasting(t_data *data, t_player player, t_ray ray, t_map map)
{
	int column;
	float camera_x;

	column = 0;
	while (column < map.resolution[0])
	{
		camera_x = 2 * column / (float)map.resolution[0] - 1;
		ray.raydir_x = player.direction_x + player.plane_x * camera_x;
		ray.raydir_y = player.direction_y + player.plane_y * camera_x;
		ray.delta_x = fabs(1 / ray.raydir_x);
		ray.delta_y = fabs(1 / ray.raydir_y);
		ray.map_x = (int)player.position_x;
		ray.map_y = (int)player.position_y;
		get_steps(*player, *ray);
		get_wall(*ray, map, player);
		if (!ray.textures && data->bonus)
			draw_untextured(ray);
		else
			draw_textured(ray);
		draw_sprites();
		column++;
	}
	player.last_pos_x = player.position_x; // faire une fonction qui actualise la position
    player.last_pos_y = player.position_y;
    player.last_dir_x = player.direction_x;
    player.last_dir_y = player.direction_y;
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

int		get_wall(t_ray *ray, t_map map, t_player player,  int side_hit)
{
	while (map.map[ray->map_x][ray->map_y] == '1') // si probleme peut etre ici
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
		if (side_hit == 0)
			ray->wall_distance = fabs((ray->map_x - player.position_x + \
							(1.0 - ray->step_x) / 2.0) / ray->raydir_x);
		else
			ray->wall_distance = fabs((ray->map_y - player.position_y + \
							(1.0 - ray->step_y) / 2.0) / ray->raydir_y);
		ray->wall_height = (int)(map->resolution[1] / 2);
	}
}

void	draw_wall(t_mlx *mlx, t_ray ray, t_map map)
{
	
}
