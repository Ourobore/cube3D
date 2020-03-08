/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 09:51:49 by lchapren          #+#    #+#             */
/*   Updated: 2020/03/08 12:14:23 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

t_data raycasting(t_data data)
{
	int i;
	float angle;
	float distance;
	float *direction;

	int bpp;
	int line_length;
	int endian;
	void *image;
	int *image_data;

	//Declaration de bpp endian et line_length supprimees
	//data.mlx.image = mlx_new_image(data.mlx.mlx_ptr, data.map.resolution[0], data.map.resolution[1]);
	//data.mlx.image_data = (int*)mlx_get_data_addr(image, &bpp, &line_length, &endian);
	if (data.mlx.image)
		mlx_destroy_image (data.mlx.mlx_ptr, data.mlx.image);
	data.mlx.image = mlx_new_image(data.mlx.mlx_ptr, data.map.resolution[0], data.map.resolution[1]);
	data.mlx.image_data = (int*)mlx_get_data_addr(data.mlx.image, &bpp, &line_length, &endian);
	//direction = new_direction(data, data.player.direction_x, data.player.direction_y, angle);
	distance = get_distance(&data, direction, i, angle);
	/*i = 0;
	angle = -1 * FOV / 2;
	if (!(direction = ft_calloc(sizeof(int), 2)))
		calloc_error();
	while (i < data.map.resolution[0])
	{
		printf("ANGLE: %f\t", angle);
		direction = new_direction(data, data.player.direction_x,
								  data.player.direction_y, angle);
		printf("DIRECTION: [%f][%f]\n", direction[0], direction[1]);
		distance = get_distance(data, direction, i, angle);
		//distance = distance * cos(angle);
		//rendering(data, distance);
		angle += FOV / (float)data.map.resolution[0];
		i++;
	}*/
	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.window_ptr, data.mlx.image, 0, 0);
	mlx_hook(data.mlx.window_ptr, KEYPRESS, KEYPRESSMASK, key_hook, &data);
	mlx_loop(data.mlx.mlx_ptr);
	//mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.window_ptr, data.mlx.image, 0, 0);
	return (data);
}

float get_distance(t_data *data, float *direction, int x, float angle)
{
	int a = 0;
	float camera_x;
	float raydir_x;
	float raydir_y;
	int hit;
	int side;
	int step_x;
	int step_y;
	float delta_x;
	float delta_y;
	float side_x;
	float side_y;
	float distance;
	int line_length;
	int draw_start;
	int draw_end;
	int i;
	float *plane;

	while (a < data->map.resolution[0])
	{
		camera_x = 2 * a / (float)(data->map.resolution[0]) - 1;
		plane = new_direction(*data, data->player.direction_x, data->player.direction_y, 90);
		raydir_x = data->player.direction_x + plane[0] * camera_x;
		raydir_y = data->player.direction_y + plane[1] * camera_x;
		//printf("X: %f\tY: %f\n", raydir_x, raydir_y);

		hit = 0;
		//delta_x = (direction[1] == 0) ? 0.0 : ((direction[0] == 0) ? 1.0 : fabs(1 / direction[0]));
		//delta_y = (direction[0] == 0) ? 0.0 : ((direction[1] == 0) ? 1.0 : fabs(1 / direction[1]));
		delta_x = sqrt(1 + (pow(raydir_y, 2) / (pow(raydir_x, 2))));
		delta_y = sqrt(1 + (pow(raydir_x, 2) / (pow(raydir_y, 2))));
		data->player.dda_x = (int)data->player.position_x;
		data->player.dda_y = (int)data->player.position_y;

		if (raydir_x < 0.0)
		{
			step_x = -1.0;
			side_x = (data->player.position_x - data->player.dda_x) * delta_x;
		}
		else
		{
			step_x = 1.0;
			side_x = (data->player.dda_x + 1.0 - data->player.position_x) * delta_x;
		}
		if (raydir_y < 0.0)
		{
			step_y = -1.0;
			side_y = (data->player.position_y - data->player.dda_y) * delta_y;
		}
		else
		{
			step_y = 1.0;
			side_y = (data->player.dda_y + 1.0 - data->player.position_y) * delta_y;
		}

		while (hit == 0)
		{
			if (side_x < side_y)
			{
				side_x += delta_x;			 // agrandis le rayon
				data->player.dda_x += step_x; // prochaine case ou case précédente sur X
				side = 0;					 // orientation du mur
			}
			else
			{
				side_y += delta_y;			 // agrandis le rayon
				data->player.dda_y += step_y; // prochaine case ou case précédente sur Y
				side = 1;					 // orientation du mur
			}
			// si le rayon rencontre un mur
			if (data->map.map[data->player.dda_x][data->player.dda_y] != '0')
				hit = 1; // stoppe la boucle
		}
		//distance = sqrt(pow(data.player.position_x - data.player.dda_x, 2) + pow(data.player.position_y - data.player.dda_y, 2));
		//printf("DISTANCE: %f\n", distance);

		if (side == 0)
			distance = fabs((data->player.dda_x - data->player.position_x + (1.0 - step_x) / 2.0) / raydir_x);
		else
			distance = fabs((data->player.dda_y - data->player.position_y + (1.0 - step_y) / 2.0) / raydir_y);

		//distance *= cos((angle * 2 * PI) / 180);

		printf("X: %f\tY: %f\tDISTANCE: %f\n", raydir_x, raydir_y, distance);
		line_length = (int)(data->map.resolution[1] / distance);
		//printf("LINE_LENGTH: %d\n", line_length);
		draw_start = (int)(-line_length / 2.0 + data->map.resolution[1] / 2.0);
		draw_end = (int)(line_length / 2.0 + data->map.resolution[1] / 2.0);
		if (draw_start < 0)
			draw_start = 0;
		if (draw_end >= data->map.resolution[1])
			draw_end = data->map.resolution[1] - 1;

		i = 0;
		/*
		while (i < data->map.resolution[1])
		{
			mlx_pixel_put(data->mlx.mlx_ptr, data->mlx.window_ptr, a, i, 0);
			i++;
		}*/
		//i = draw_start;
		while (i < data->map.resolution[1])
		{
			if (i > draw_start && i < draw_end && side == 0)
			{
				data->mlx.image_data[a + (i * data->map.resolution[0])] = 16777215;
				//mlx_pixel_put(data->mlx.mlx_ptr, data->mlx.window_ptr, a, i, 16777215);
				i++;
			}
			else if (i > draw_start && i < draw_end && side == 1)
			{
				data->mlx.image_data[a + (i * data->map.resolution[0])] = 13158600;
				//mlx_pixel_put(data->mlx.mlx_ptr, data->mlx.window_ptr, a, i, 13158600);
				i++;
			}
			else
			{
				data->mlx.image_data[a + (i * data->map.resolution[0])] = 0;
				//mlx_pixel_put(data->mlx.mlx_ptr, data->mlx.window_ptr, a, i, 0);
				i++;
			}
		}
		a++;
	}
	return (distance);
	/*
	//data.player.dda_x = data.player.position_x;
	//data.player.dda_y = data.player.position_y;
	printf("PLAYER: X [%f]  Y [%f]\n", data.player.position_x, data.player.position_y);
	while (distance == -1)
	{

		
		if (fabs(direction[0]) >= fabs(direction[1]))
		{
			if ((distance = horizontal_wall(&data, direction)) != -1)
				return (distance);
			if ((distance = vertical_wall(&data, direction)) != -1)
				return (distance);
		}
		else
		{
			if ((distance = vertical_wall(&data, direction)) != -1)
				return (distance);
			if ((distance = horizontal_wall(&data, direction)) != -1)
				return (distance);
		}
		
	}
	return (-1);
	*/
}

void rendering(t_data data, float distance)
{
	int i;
	int bpp;
	int line_length;
	int endian;

	i = 0;
	data.mlx.image = mlx_new_image(data.mlx.mlx_ptr, data.map.resolution[0], data.map.resolution[1]);
	data.mlx.image_data = (int *)mlx_get_data_addr(data.mlx.image, &bpp, &line_length, &endian);
	while (i < data.map.resolution[1])
	{
		if (i >= (data.map.resolution[1] / 2) - (1 / distance / 2) &&
			i <= (data.map.resolution[1] / 2) + (1 / distance / 2))
			data.mlx.image_data[i] = 16777215;
		i++;
	}
	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.window_ptr, data.mlx.image, 0, 0);
}

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

float *new_direction(t_data data, float direction_x, float direction_y, int angle)
{
	float *new_direction;

	if (!(new_direction = ft_calloc(sizeof(float), 2)))
		calloc_error();
	new_direction[0] = (direction_x * cos((angle * PI) / 180.0) -
						(direction_y * sin((angle * PI) / 180.0)));
	new_direction[1] = (direction_x * sin((angle * PI) / 180.0)) +
					   (direction_y * cos((angle * PI) / 180.0));
	return (new_direction);
}
