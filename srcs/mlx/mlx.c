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
	mlx.window_ptr = mlx_new_window(mlx.mlx_ptr, \
						map.res[0], map.res[1], "Cube3D");
	return (mlx);
}

void	new_image(t_data *data)
{
	data->mlx.image = mlx_new_image(data->mlx.mlx_ptr, \
						data->map.res[0], data->map.res[1]);
	data->mlx.image_data = get_img_addr(data->mlx.image);
}

int		destroy_window(t_data *data)
{
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.window_ptr);
	data->mlx.window_ptr = NULL;
	write(1, "Clean exit (escape button)\n", 27);
	clean_exit(data, 0);
	return (0);
}
