/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 09:34:40 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/24 14:57:00 by lchapren         ###   ########.fr       */
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
		get_wall(*data, ray, map, *player);
		if (ray->textures < 0)
			draw_untextured(&(data->mlx), *ray, *player, map, column);
		else
			draw_textured(&(data->mlx), *ray, *player, map, column);
		draw_sprite(&(data->mlx), *ray, *player, map, column);
		ft_bzero(ray->sprite_list, map.sprites_count);
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

void	get_wall(t_data data, t_ray *ray, t_map map, t_player player)
{
	int	i;

	i = 0;
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
		//faire une fonction qui donne la distance a la variable qu'on lui donne en entree
		if (map.map[ray->map_x][ray->map_y] == '2') //get sprite list
		{
			if (ray->hit_side == 0)
				ray->sprite_list[i] = fabs((ray->map_x - player.position_x + \
						(1.0 - ray->step_x) / 2.0) / ray->raydir_x);
			else
				ray->sprite_list[i] = fabs((ray->map_y - player.position_y + \
						(1.0 - ray->step_y) / 2.0) / ray->raydir_y);
			printf("SPRITE DETECTED: %f	I:%d\n", ray->sprite_list[i], i);
			i++;
		}
		if (map.map[ray->map_x][ray->map_y] == '1' || (map.map[ray->map_x][ray->map_y] == '3' && data.bonus)) //get real wall or fake wall
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

	if ((draw_start = -ray.wall_height / 2 + map.resolution[1] / player.height) < 0)
		draw_start = 0;
	if ((draw_end = ray.wall_height / 2 + map.resolution[1] / player.height) < 0)
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
            if (i > map.resolution[1] / player.height)
                mlx->image_data[column + (i * map.resolution[0])] = (map.ceiling_color[2] * 65536) + (map.ceiling_color[1] * 256) + map.ceiling_color[0];
            else
                mlx->image_data[column + (i * map.resolution[0])] = (map.floor_color[2] * 65536) + (map.floor_color[1] * 256) + map.floor_color[0];
		}
        i++;
    }
}

void	draw_textured(t_mlx *mlx, t_ray ray, t_player player, t_map map, int column)
{
	float	wall_x;
	float	step;
	float	tex_pos;
	int		draw_start;
	int		draw_end;
	int		i;

	if (ray.hit_side == 0)	//calcul wall_x
		wall_x = player.position_y + ray.wall_distance * ray.raydir_y;
	else
		wall_x = player.position_x + ray.wall_distance * ray.raydir_x;
	wall_x -= floor(wall_x);
	ray.tex_x = (int)(wall_x * (float)(ray.tex_width));
	if (ray.hit_side == 0 && ray.raydir_x > 0)	//calcul tex_x
		ray.tex_x = ray.tex_width - ray.tex_x - 1;
	if (ray.hit_side == 1 && ray.raydir_y < 0)
		ray.tex_x = ray.tex_width - ray.tex_x - 1;
	//calcul draw_start draw_end
	if ((draw_start = -ray.wall_height / 2 + map.resolution[1] / player.height) < 0)
		draw_start = 0;
	if ((draw_end = ray.wall_height / 2 + map.resolution[1] / player.height) < 0)
		draw_end = map.resolution[1] - 1;
	//calcul step pour tex_y
	step = 1.0 * ray.tex_height / ray.wall_height;
	tex_pos = (draw_start - map.resolution[1] / player.height + ray.wall_height / 2) * step;
	//prendre la bonne texture
	if (ray.hit_side == 0)
	{
		if (ray.map_x < player.position_x)
			ray.texture = ray.tex_north;
		else
			ray.texture = ray.tex_south;
	}
	else
	{
		if (ray.map_y < player.position_y)
			ray.texture = ray.tex_west;
		else
			ray.texture = ray.tex_east;
	}
	i = 0;
	//boucle draw
	while (i < map.resolution[1] - 1)
	{
		if (i < draw_start || i >= draw_end)	//sol plafond
		{
			if (i < map.resolution[1] / player.height)
				mlx->image_data[column + (i * map.resolution[0])] = (map.ceiling_color[2] * 65536) + (map.ceiling_color[1] * 256) + map.ceiling_color[0];
            else
				mlx->image_data[column + (i * map.resolution[0])] = (map.floor_color[2] * 65536) + (map.floor_color[1] * 256) + map.floor_color[0];
		}
		else	//texture
		{
			ray.tex_y = (int)tex_pos & (ray.tex_height - 1);
			tex_pos += step;
			mlx->image_data[i * map.resolution[0] + column] = ray.texture[(int)(ray.tex_height * ray.tex_y + ray.tex_x)];
		}	
		i++;
	}
}

void	draw_sprite(t_mlx *mlx, t_ray ray, t_player player, t_map map, int column)
{
	int		i;
	int		j;
	int		step;
	int		draw_start;
	int		draw_end;
	float	wall_x;
	float	sprite_pos;

	i = 0;
	while (ray.sprite_list[i] != 0)
	{
		printf("SPRITE LIST: %f		I: %d\n", ray.sprite_list[i], i);
		i++;
	}
	while (i >= 0)
	{
		if (ray.hit_side == 0)	//calcul wall_x
			wall_x = player.position_y + ray.sprite_list[i] * ray.raydir_y;
		else
			wall_x = player.position_x + ray.sprite_list[i] * ray.raydir_x;
		wall_x -= floor(wall_x);
		ray.sprite_x = (int)(wall_x * (float)(ray.tex_width));	
		ray.sprite_height = (int)(map.resolution[1] / ray.sprite_list[i]);
		if (ray.hit_side == 0 && ray.raydir_x > 0)	//calcul tex_x
			ray.sprite_x = ray.tex_width - ray.sprite_x - 1;
		if (ray.hit_side == 1 && ray.raydir_y < 0)
			ray.sprite_x = ray.tex_width - ray.sprite_x - 1;
		//calcul draw_start draw_end
		if ((draw_start = -ray.sprite_height / 2 + map.resolution[1] / player.height) < 0)
			draw_start = 0;
		if ((draw_end = ray.sprite_height / 2 + map.resolution[1] / player.height) < 0)
			draw_end = map.resolution[1] - 1;
		printf("start: %d	end:%d\n", draw_start, draw_end);
		printf("before\n");
		//calcul step pour tex_y
		step = 1.0 * ray.tex_height / ray.sprite_height;
		sprite_pos = (draw_start - map.resolution[1] / player.height + ray.sprite_height / 2) * step;
		j = draw_start;
		//printf("draw_start: %d	draw_end: %d\n", draw_start, draw_end);
		ray.texture = ray.tex_sprite;
		printf("after\n");
		while (j < map.resolution[1] - 1)
		{
			if (j >= draw_start && j < draw_end)
			{
				ray.sprite_y = (int)sprite_pos & (ray.sprite_height - 1);
				sprite_pos +=step;
				mlx->image_data[j * map.resolution[0] + column] = ray.texture[(int)(ray.tex_height * ray.sprite_y + ray.sprite_x)];
			}
			j++;
		}
		i--;
	}
}

