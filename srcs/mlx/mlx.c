/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:05:37 by lchapren          #+#    #+#             */
/*   Updated: 2020/08/25 11:32:58 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

t_mlx	start_mlx(t_map map)
{
	t_mlx mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.window_ptr = mlx_new_window(mlx.mlx_ptr, map.res[0], \
					map.res[1], "Cube3D");
	return (mlx);
}

t_data	new_image(t_data data)
{
	int bpp;
	int line_length;
	int endian;

	data.mlx.image = mlx_new_image(data.mlx.mlx_ptr, \
						data.map.res[0], data.map.res[1]);
	data.mlx.image_data = (int*)mlx_get_data_addr(data.mlx.image, &bpp, \
							&line_length, &endian);
	return (data);
}
