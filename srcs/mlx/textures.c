/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 12:55:54 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/23 14:14:28 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	get_textures(t_data *data, t_ray *ray, t_map map)
{
	if (!(ray->ptr_north = mlx_xpm_file_to_image(data->mlx.mlx_ptr, map.north_texture, &ray->tex_width, &ray->tex_height)))
		texture_error(data, ray);
	ray->tex_north = get_img_addr(ray->ptr_north);
	if (!(ray->ptr_south = mlx_xpm_file_to_image(data->mlx.mlx_ptr, map.south_texture, &ray->tex_width, &ray->tex_height)))
		texture_error(data, ray);
	ray->tex_south = get_img_addr(ray->ptr_south);
	if (!(ray->ptr_west = mlx_xpm_file_to_image(data->mlx.mlx_ptr, map.west_texture, &ray->tex_width, &ray->tex_height)))
		texture_error(data, ray);
	ray->tex_west = get_img_addr(ray->ptr_west);
	if (!(ray->ptr_east = mlx_xpm_file_to_image(data->mlx.mlx_ptr, map.east_texture, &ray->tex_width, &ray->tex_height)))
		texture_error(data, ray);
	ray->tex_east = get_img_addr(ray->ptr_east);
	if (!(ray->ptr_sprite = mlx_xpm_file_to_image(data->mlx.mlx_ptr, map.sprite_texture, &ray->tex_width, &ray->tex_height)))
		texture_error(data, ray);
	ray->tex_sprite = get_img_addr(ray->ptr_sprite);
}

void	texture_error(t_data *data, t_ray *ray)
{
	if (ray->tex_north)
		mlx_destroy_image(data->mlx.mlx_ptr, ray->tex_north);
	if (ray->tex_south)
		mlx_destroy_image(data->mlx.mlx_ptr, ray->tex_south);
	if (ray->tex_west)
		mlx_destroy_image(data->mlx.mlx_ptr, ray->tex_west);
	if (ray->tex_east)
		mlx_destroy_image(data->mlx.mlx_ptr, ray->tex_east);
	if (ray->tex_sprite)
		mlx_destroy_image(data->mlx.mlx_ptr, ray->tex_sprite);
	// +free ray all modules and data
}

int		*get_img_addr(void *ptr)
{
	int bpp;
	int	line_length;
	int	endian;

	return ((int *)mlx_get_data_addr(ptr, &bpp, &line_length, &endian));
}
