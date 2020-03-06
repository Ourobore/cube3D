/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:40:57 by lchapren          #+#    #+#             */
/*   Updated: 2020/03/05 10:58:45 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

char *fill_new_image(t_data data)
{
	int		bpp;
	int		line_length;
	int		endian;
	void	*image;
	int		*image_data;

	//Declaration de bpp endian et line_length supprimees
	image = mlx_new_image(data.mlx.mlx_ptr, data.map.resolution[0], data.map.resolution[1]);
	image_data = (int*)mlx_get_data_addr(image, &bpp, &line_length, &endian);
	
	int i = 0;
	while (i < data.map.resolution[0] * data.map.resolution[1])
	{
		image_data[i] = rand() % 16777215;
		i++;
	}
	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.window_ptr, image, 0, 0);
	return (image);
}
