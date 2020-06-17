/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 09:34:40 by lchapren          #+#    #+#             */
/*   Updated: 2020/06/17 12:58:46 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

t_data *my_raycasting(t_data *data)
{
	int		column;
	float	raydir[2];

	column = 0;
	raydir[0] = data->player.direction_x;
	raydir[1] = data->player.direction_y;
	data->ray.hor_x = data->player
	raydir = rotate_direction(raydir, -1 * (float)FOV / 2);
	while (column < data->map.resolution[0])
	{
		data->ray.hor_x = data->player.position_x;
		data->ray.hor_y = data->player.position_y;
		data->ray.ver_x = data->player.position_x;
		data->ray.ver_y = data->player.position_y;
		while (!data->ray.wall_hit)
		{
			horizontal_hit(data, raydir);
			vertical_hit(data, raydir);
		}
		raydir = rotate_direction(raydir, (float)FOV/data->map.resolution[0]);
		column++;
	}
}

t_data horizontal_hit(t_data *data, float raydir[])
{
	data->ray.hor_x *= fabs(raydir[1] / raydir[0]);
	data->ray.hor_y *= fabs(raydir)
	data->ray.hor_y = (data->ray.hor_y == data->player.position_y ? int()
}

/*
void	my_raycasting(t_data *data)
{
	float	*ray_dir;

	data->ray.column = 0;
	*data = new_image(*data);
	data->ray.distance = 0;
	ray_dir = rotate_direction(data->player.direction_x, data->player.direction_y, -1 * (float)FOV / 2);
	//printf("FOV: %f	x: %f y: %f\n", (float)(FOV) / data.map.resolution[0], ray_dir[0], ray_dir[1]);
	while (data->ray.column < data->map.resolution[0])
	{
		data->ray.raydir_x = ray_dir[0];
		data->ray.raydir_y = ray_dir[1];
		data->ray.map_x = data->player.position_x;
		data->ray.map_y = data->player.position_y;
		data->ray.delta_x = fabs(1 / ray_dir[0]);
		data->ray.delta_y = fabs(1 / ray_dir[1]);
		data->ray.distance = get_distance(data, ray_dir);
		draw_column(*data);
		free(ray_dir);
		//printf("x: %f	y:%f\n", data.ray.raydir_x, data.ray.raydir_y);
		ray_dir = rotate_direction(data->ray.raydir_x, data->ray.raydir_y, (float)(FOV) / data->map.resolution[0]);
		data->ray.column++;
	}
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.window_ptr, data->mlx.image, 0, 0);
	data->mlx.rendered = 1;
}

float	get_distance(t_data *data, float *ray_dir)
{
	float	distance;
	float	side_x;
	float	side_y;

	if (ray_dir[0] < 0.0)
	{
		side_x = (data->player.position_x - data->ray.map_x) * data->ray.delta_x;
		data->ray.step_x = -1.0;
	}	
	else
	{
		side_x = (data->ray.map_x + 1.0 - data->player.position_x) * data->ray.delta_x;
		data->ray.step_x = 1.0;
	}
	if (ray_dir[1] < 0.0)
	{
		side_y = (data->player.position_y - data->ray.map_y) * data->ray.delta_y;
		data->ray.step_y = -1.0;
	}	
	else
	{
		side_y = (data->ray.map_y + 1.0 - data->player.position_y) * data->ray.delta_y;
		data->ray.step_y = 1.0;
	}
	distance = wall_hit(data, distance, side_x, side_y);
	return (distance);
}

float	wall_hit(t_data *data, float distance, float side_x, float side_y)
{
	while (!is_solid_cell(*data, data->ray.map_x, data->ray.map_y))
	{
		//printf("in\n");
		if (side_x < side_y)
		{
			side_x += data->ray.delta_x;
			data->ray.map_x += data->ray.step_x;
			data->ray.hit_side = 0;
		}
		else
		{
			side_y += data->ray.delta_y;
			data->ray.map_y += data->ray.step_y;
			data->ray.hit_side = 1;
		}
	}
	if (data->ray.hit_side == 0)
		distance = fabs(data->ray.map_x - data->player.position_x + \
		(1.0 - data->ray.step_x) / 2.0) / data->ray.raydir_x;
	else
		distance = fabs(data->ray.map_y - data->player.position_y + \
		(1.0 - data->ray.step_y) / 2.0) / data->ray.raydir_y;
	//printf("DISTANCE: %f\n", distance);
	return (distance);
}

void	draw_column(t_data data)
{
	int i;
    int draw_length;
    int draw_start;
    int draw_end;

	printf("distance: %f\n", data.ray.distance);
    draw_length = (int)(data.map.resolution[1] / data.ray.distance);
    draw_start = (int)(-draw_length / 2.0 + data.map.resolution[1] / 2.0);
    draw_end = (int)(draw_length / 2.0 + data.map.resolution[1] / 2.0);
    if (draw_start < 0)
        draw_start = 0;
    if (draw_end >= data.map.resolution[1])
        draw_end = data.map.resolution[1] - 1;
    i = 0;
    while (i < data.map.resolution[1])
    {
        if (i > draw_start && i < draw_end && data.ray.hit_side == 0)
            data.mlx.image_data[data.ray.column + (i * data.map.resolution[0])] = 16777215;
        else if (i > draw_start && i < draw_end && data.ray.hit_side == 1)
            data.mlx.image_data[data.ray.column + (i * data.map.resolution[0])] = 13158600;
        else
        {
            if (i < data.map.resolution[1] / 2)
                data.mlx.image_data[data.ray.column + (i * data.map.resolution[0])] = (data.map.ceiling_color[2] * 65536) + (data.map.ceiling_color[1] * 256) + data.map.ceiling_color[0];
            else
                data.mlx.image_data[data.ray.column + (i * data.map.resolution[0])] = (data.map.floor_color[2] * 65536) + (data.map.floor_color[1] * 256) + data.map.floor_color[0];
        }
        i++;
    }
}
*/
