/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 11:26:12 by lchapren          #+#    #+#             */
/*   Updated: 2020/08/25 11:35:06 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	clean_exit(t_data *data, int exit_code)
{
	clean_map(data);
	if (data->ray.sp_list != NULL)
		free(data->ray.sp_list);
	clean_texture(data);
	free(data->mlx.mlx_ptr);
	exit(exit_code);
}

void	clean_map(t_data *data)
{
	if (data->map.res != NULL)
		free(data->map.res);
	if (data->map.floor_color != NULL)
		free(data->map.floor_color);
	if (data->map.ceil_color != NULL)
		free(data->map.ceil_color);
	if (data->map.sprite_texture != NULL)
		free(data->map.sprite_texture);
	if (data->map.north_texture != NULL)
		free(data->map.north_texture);
	if (data->map.south_texture != NULL)
		free(data->map.south_texture);
	if (data->map.west_texture != NULL)
		free(data->map.west_texture);
	if (data->map.east_texture != NULL)
		free(data->map.east_texture);
	if (data->map.map != NULL)
		free_double_array(data->map.map);
}

void	clean_texture(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx_ptr, data->ray.ptr_north);
	mlx_destroy_image(data->mlx.mlx_ptr, data->ray.ptr_south);
	mlx_destroy_image(data->mlx.mlx_ptr, data->ray.ptr_west);
	mlx_destroy_image(data->mlx.mlx_ptr, data->ray.ptr_east);
	mlx_destroy_image(data->mlx.mlx_ptr, data->ray.ptr_sprite);
}

void	free_double_array(char **double_array)
{
	int i;

	i = 0;
	while (double_array[i])
	{
		free(double_array[i]);
		i++;
	}
	free(double_array);
}
