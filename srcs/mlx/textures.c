/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 12:55:54 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/23 11:26:34 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	get_textures(t_data *data, t_ray *ray, t_map map)
{
	if (!(ray->tex_north = mlx_xpm_file_to_image(data->mlx.mlx_ptr, map.north_texture, &ray->tex_width, &ray->tex_height)))
		texture_error(data, ray);
	if (!(ray->tex_south = mlx_xpm_file_to_image(data->mlx.mlx_ptr, map.south_texture, &ray->tex_width, &ray->tex_height)))
		texture_error(data, ray);
	if (!(ray->tex_west = mlx_xpm_file_to_image(data->mlx.mlx_ptr, map.west_texture, &ray->tex_width, &ray->tex_height)))
		texture_error(data, ray);
	if (!(ray->tex_east = mlx_xpm_file_to_image(data->mlx.mlx_ptr, map.east_texture, &ray->tex_width, &ray->tex_height)))
		texture_error(data, ray);
	if (!(ray->tex_sprite = mlx_xpm_file_to_image(data->mlx.mlx_ptr, map.sprite_texture, &ray->tex_width, &ray->tex_height)))
		texture_error(data, ray);
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
