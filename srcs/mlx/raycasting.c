/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 09:51:49 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/20 09:48:14 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void raycasting(t_data *data)
{
	int column;
	float *camera_plane;
	float camera_x;

	column = 0;
	*data = new_image(*data);
	printf("=========ray_loop=======\n");
	while (column < data->map.resolution[0])
	{
		camera_x = 2 * column / (float)(data->map.resolution[0]) - 1;
		data->ray.camera_plane = rotate_direction(data->player.direction_x, data->player.direction_y, 90);
		data->ray.raydir_x = data->player.direction_x + data->ray.camera_plane[0] * camera_x;
		data->ray.raydir_y = data->player.direction_y + data->ray.camera_plane[1] * camera_x;
		free(data->ray.camera_plane);
		data->ray.delta_x = fabs(1 / data->ray.raydir_x);
		data->ray.delta_y = fabs(1 / data->ray.raydir_y);
		data->ray.map_x = (int)data->player.position_x;
		data->ray.map_y = (int)data->player.position_y;
		side_calculus(data, column);
		column++;
	}
	data->player.last_pos_x = data->player.position_x;
	data->player.last_pos_y = data->player.position_y;
	data->player.last_dir_x = data->player.direction_x;
	data->player.last_dir_y = data->player.direction_y;
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.window_ptr, data->mlx.image, 0, 0);
}

void side_calculus(t_data *data, int column)
{
	if (data->ray.raydir_x < 0.0)
	{
		STEP_X = -1.0;
		SIDE_X = (PLAYER_X - MAP_X) * DELTA_X;
	}
	else
	{
		STEP_X = 1.0;
		SIDE_X = (MAP_X + 1.0 - PLAYER_X) * DELTA_X;
	}
	if (data->ray.raydir_y < 0.0)
	{
		STEP_Y = -1.0;
		SIDE_Y = (PLAYER_Y - MAP_Y) * DELTA_Y;
	}
	else
	{
		STEP_Y = 1.0;
		SIDE_Y = (MAP_Y + 1.0 - PLAYER_Y) * DELTA_Y;
	}
	wall_hit_calculus(data, column);
}

void wall_hit_calculus(t_data *data, int column)
{
	int side;

	while (1)
	{
		if (SIDE_X < SIDE_Y)
		{
			SIDE_X += DELTA_X; // agrandis le rayon
			MAP_X += STEP_X;   // prochaine case ou case précédente sur X
			side = 0;		   // orientation du mur
		}
		else
		{
			SIDE_Y += DELTA_Y; // agrandis le rayon
			MAP_Y += STEP_Y;   // prochaine case ou case précédente sur Y
			side = 1;		   // orientation du mur
		}
		// si le rayon rencontre un mur
		if (data->map.map[(int)MAP_X][(int)MAP_Y] == '1')
			break;
	}
	if (side == 0)
		DISTANCE = fabs((MAP_X - PLAYER_X + (1.0 - STEP_X) / 2.0) / data->ray.raydir_x);
	else
		DISTANCE = fabs((MAP_Y - PLAYER_Y + (1.0 - STEP_Y) / 2.0) / data->ray.raydir_y);
	draw_wall(data, side, column);
}

void draw_wall(t_data *data, int side, int column)
		int i;
	int draw_length;
	int draw_start;
	int draw_end;

	draw_length = (int)(data->map.resolution[1] / DISTANCE);
	draw_start = (int)(-draw_length / 2.0 + data->map.resolution[1] / 2.0);
	draw_end = (int)(draw_length / 2.0 + data->map.resolution[1] / 2.0);
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= data->map.resolution[1])
		draw_end = data->map.resolution[1] - 1;
	i = 0;
	while (i < data->map.resolution[1])
	{
		if (i > draw_start && i < draw_end && side == 0)
			data->mlx.image_data[column + (i * data->map.resolution[0])] = 16777215;
		else if (i > draw_start && i < draw_end && side == 1)
			data->mlx.image_data[column + (i * data->map.resolution[0])] = 13158600;
		else
		{
			if (i < data->map.resolution[1] / 2)
				data->mlx.image_data[column + (i * data->map.resolution[0])] = (data->map.ceiling_color[2] * 65536) + (data->map.ceiling_color[1] * 256) + data->map.ceiling_color[0];
			else
				data->mlx.image_data[column + (i * data->map.resolution[0])] = (data->map.floor_color[2] * 65536) + (data->map.floor_color[1] * 256) + data->map.floor_color[0];
		}
		i++;
	}
}

/*
float vertical_wall(t_data *data, float *direction)
{
	float x;
	float y;

	x = (int)(data->player.dda_x + (direction[0] >= 0 ? 1 : -1));
	y = (data->player.dda_y + (direction[1] / direction[0]));
	printf("VERTICAL: X [%d]  Y [%d]\n", (int)x, (int)y);
	printf("CARAC: |%c|\n", data->map.map[(int)y][(int)x]);
	printf("RETURN: {%f}\n", sqrt(pow(data->player.position_x - (int)x, 2) + pow(data->player.position_y - (int)y, 2)));
	if (data->map.map[(int)x][(int)y] == '1')
		return (sqrt(pow(data->player.dda_x - (int)x, 2) +
					 pow(data->player.dda_y - (int)y, 2)));
	else
	{
		data->player.dda_x = x;
		data->player.dda_y = y;
		return (-1);
	}
}

float horizontal_wall(t_data *data, float *direction)
{
	float x;
	float y;

	y = (int)(data->player.dda_y + (direction[1] >= 0 ? 1 : -1));
	x = (data->player.dda_x + (direction[0] / direction[1]));
	printf("HORIZONTAL: X [%d]  Y [%d]\n", (int)x, (int)y);
	printf("CARAC: |%c|\n", data->map.map[(int)y][(int)x]);
	printf("RETURN: {%f}\n", sqrt(pow(data->player.position_x - (int)x, 2) + pow(data->player.position_y - (int)y, 2)));
	if (data->map.map[(int)x][(int)y] == '1')
		return (sqrt(pow(data->player.position_x - (int)x, 2) +
					 pow(data->player.position_y - (int)y, 2)));
	else
	{
		data->player.dda_x = x;
		data->player.dda_y = y;
		return (-1);
	}
}
*/
