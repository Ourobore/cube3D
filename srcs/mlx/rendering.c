/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:10:53 by lchapren          #+#    #+#             */
/*   Updated: 2020/03/01 13:10:57 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	rendering(t_data data, float distance)
{
	int i;
	int		bpp;
	int		line_length;
	int		endian;

	i = 0;
	data.mlx.image = mlx_new_image(data.mlx.mlx_ptr, data.map.resolution[0], data.map.resolution[1]);
	data.mlx.image_data = (int*)mlx_get_data_addr(data.mlx.image, &bpp, &line_length, &endian);
	while (i < data.map.resolution[1])
	{
		if (i >= (data.map.resolution[1] / 2) - (1 / distance / 2) && \
			i <= (data.map.resolution[1] / 2) + (1 / distance / 2))
			data.mlx.image_data[i] = 16777215;
		i++;
	}
	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.window_ptr, data.mlx.image, 0, 0);
}