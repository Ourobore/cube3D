/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:40:57 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/18 16:45:17 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

char *fill_new_image(t_mlx window, t_map map)
{
	int		bpp;
	int		line_length;
	int		endian;
	void	*image;
	int		*data;

	bpp = 32;
	endian = 0;
	line_length = map.resolution[0] * 4;
	image = mlx_new_image(window.mlx_ptr, map.resolution[0], map.resolution[1]);
	data = (int*)mlx_get_data_addr(image, &bpp, &line_length, &endian);
	
	int i = 0;
	while (i < map.resolution[0] * map.resolution[1])
	{
		data[i] = 220;
		i++;
	}
	mlx_put_image_to_window(window.mlx_ptr, window.window_ptr, image, 0, 0);
	return (image);
}