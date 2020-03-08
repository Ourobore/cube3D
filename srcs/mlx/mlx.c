/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:05:37 by lchapren          #+#    #+#             */
/*   Updated: 2020/03/08 16:39:46 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

t_mlx	start_mlx(t_map map)
{
	t_mlx w;

	w.mlx_ptr = mlx_init();
	w.window_ptr = \
	mlx_new_window(w.mlx_ptr, map.resolution[0], map.resolution[1], "Cube3D");
	return (w);
}

int		key_hook(int key, t_data *data)
{
	float	angle;
	float	*new_dir;
	
	ft_putnbr_fd(key, 1);
	if (key == 53)
	{
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.window_ptr);
		write(1, "Clean exit (escape button)\n", 27);
		//system("leaks Cube3D");
		exit(0);
	}
	if (key == 13 || key == 0 || key == 1 || key == 2)
	{
		if (key == 13)
			angle = 0;
		if (key == 0)
			angle = -90;
		if (key == 1)
			angle = 180;
		if (key == 2)
			angle = 90;
		*data = move_player(*data, angle);
		raycasting(*data);
	}
	if (key == 123)
	{
		new_dir = rotate_direction(data->player.direction_x, data->player.direction_y, -3);
		data->player.direction_x = new_dir[0];
		data->player.direction_y = new_dir[1];
		//mlx_destroy_image (data.mlx.mlx_ptr, data.mlx.image);
		raycasting(*data);
	}
	if (key == 124)
	{
		new_dir = rotate_direction(data->player.direction_x, data->player.direction_y, 3);
		data->player.direction_x = new_dir[0];
		data->player.direction_y = new_dir[1];
		//mlx_destroy_image (data.mlx.mlx_ptr, data.mlx.image);
		raycasting(*data);
	}
	if (key == 257)
	{
		data->player.speed = 3;
		raycasting(*data);
	}
	if (key == 46)
		write(1, "Toogle map\n", 11);
	write(1, "Key\n", 4);
	return (1);
}

int		deal_mouse(int key, t_mlx *param)
{
	ft_putnbr_fd(key, 1);
	write(1, "Mouse\n", 6);
	return (1);
}

void	free_mlx(t_mlx window)
{
	free(window.mlx_ptr);
	free(window.mlx_ptr);
}
