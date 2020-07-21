/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:05:37 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/21 11:14:39 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

t_mlx	start_mlx(t_map map)
{
	t_mlx w;

	w.mlx_ptr = mlx_init();
	w.test = 1;
	w.window_ptr = \
	mlx_new_window(w.mlx_ptr, map.resolution[0], map.resolution[1], "Cube3D");
	return (w);
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
