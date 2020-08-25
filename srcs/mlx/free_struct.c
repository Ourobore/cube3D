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

void    clean_exit(t_data *data, int exit_code)
{
	clean_map(data);
	if (data->ray.camera_plane != NULL)
		free(data->ray.camera_plane);
	if (data->ray.sp_list != NULL)
		free(data->ray.sp_list);
	if (data->ray.buff_dist != NULL)
		free(data->ray.buff_dist);
	clean_texture(data);
	/*if (data->mlx.window_ptr != NULL)
		free(data->mlx.window_ptr);
	if (data->mlx.image != NULL)
		free(data->mlx.image);
	if (data->mlx.image_data != NULL)
		free(data->mlx.image_data);*/
	system("leaks Cube3D");
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
	//if (data->ray.texture != NULL)
	//	free(data->ray.texture);
	/*if (data->ray.tex_north != NULL)
		free(data->ray.tex_north);
	if (data->ray.tex_south != NULL)
		free(data->ray.tex_south);
	if (data->ray.tex_west != NULL)
		free(data->ray.tex_west);
	if (data->ray.tex_east != NULL)
		free(data->ray.tex_east);
	if (data->ray.tex_sprite != NULL)
		free(data->ray.tex_sprite);
	if (data->ray.ptr_north != NULL)
		free(data->ray.ptr_north);
	if (data->ray.ptr_south != NULL)
		free(data->ray.ptr_south);
	if (data->ray.ptr_west != NULL)
		free(data->ray.ptr_west);
	if (data->ray.ptr_east != NULL)
		free(data->ray.ptr_east);
	if (data->ray.ptr_sprite != NULL)
		free(data->ray.ptr_sprite);*/
}

void    free_double_array(char **double_array)
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
