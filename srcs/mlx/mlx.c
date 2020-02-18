/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:05:37 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/18 16:41:34 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mymlx.h"

t_mlx	main_mlx_loop(t_mlx window, t_map map)
{
	int i = 0;
	int j = 0;
	void *test;
	void *w;

	fill_new_image(window, map);
	mlx_hook(window.window_ptr, KEYPRESS, KEYPRESSMASK, key_hook, &window);
	mlx_loop(window.mlx_ptr);
	return (window);
}

t_mlx	start_mlx(t_map map)
{
	t_mlx window;
	window.mlx_ptr = mlx_init();
	window.window_ptr = mlx_new_window(window.mlx_ptr, map.resolution[0], map.resolution[1], "Cube3D");
	return (window);
}

int		key_hook(int key, t_mlx *param)
{
	//ft_putnbr_fd(key, 1);
	if (key == 53)
	{
		mlx_destroy_window(param->mlx_ptr, param->window_ptr);
		write(1, "Clean exit (escape button)\n", 27);
		exit(0);
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