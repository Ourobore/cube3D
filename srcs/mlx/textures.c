/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 12:55:54 by lchapren          #+#    #+#             */
/*   Updated: 2020/08/25 10:48:51 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	get_textures(t_data *data, t_ray *ray, t_map map)
{
	if (!(ray->ptr_north = mlx_xpm_file_to_image(data->mlx.mlx_ptr, \
					map.north_texture, &ray->tex_width, &ray->tex_height)))
		texture_error(data, ray);
	ray->tex_north = get_img_addr(ray->ptr_north);
	if (!(ray->ptr_south = mlx_xpm_file_to_image(data->mlx.mlx_ptr, \
					map.south_texture, &ray->tex_width, &ray->tex_height)))
		texture_error(data, ray);
	ray->tex_south = get_img_addr(ray->ptr_south);
	if (!(ray->ptr_west = mlx_xpm_file_to_image(data->mlx.mlx_ptr, \
					map.west_texture, &ray->tex_width, &ray->tex_height)))
		texture_error(data, ray);
	ray->tex_west = get_img_addr(ray->ptr_west);
	if (!(ray->ptr_east = mlx_xpm_file_to_image(data->mlx.mlx_ptr, \
					map.east_texture, &ray->tex_width, &ray->tex_height)))
		texture_error(data, ray);
	ray->tex_east = get_img_addr(ray->ptr_east);
	if (!(ray->ptr_sprite = mlx_xpm_file_to_image(data->mlx.mlx_ptr, \
					map.sprite_texture, &ray->tex_width, &ray->tex_height)))
		texture_error(data, ray);
	ray->tex_sprite = get_img_addr(ray->ptr_sprite);
}

void	texture_error(t_data *data, t_ray *ray)
{
	if (ray->ptr_north)
		mlx_destroy_image(data->mlx.mlx_ptr, ray->ptr_north);
	if (ray->ptr_south)
		mlx_destroy_image(data->mlx.mlx_ptr, ray->ptr_south);
	if (ray->ptr_west)
		mlx_destroy_image(data->mlx.mlx_ptr, ray->ptr_west);
	if (ray->ptr_east)
		mlx_destroy_image(data->mlx.mlx_ptr, ray->ptr_east);
	if (ray->ptr_sprite)
		mlx_destroy_image(data->mlx.mlx_ptr, ray->ptr_sprite);
	clean_exit(data, -1);
}

void	select_texture(t_ray *ray, t_player player)
{
	if (ray->hit_side == 0)
	{
		if (ray->map_x < player.pos_x)
			ray->texture = ray->tex_north;
		else
			ray->texture = ray->tex_south;
	}
	else
	{
		if (ray->map_y < player.pos_y)
			ray->texture = ray->tex_west;
		else
			ray->texture = ray->tex_east;
	}
}

void	textured_loop(t_mlx *mlx, t_ray ray, t_player player, t_map map)
{
	int i;

	i = 0;
	while (i < map.res[1])
	{
		if (i < ray.start_y || i > ray.end_y)
		{
			if (i < map.res[1] / player.height)
				mlx->image_data[ray.column + (i * map.res[0])] = \
(map.ceil_color[0] << 16) + (map.ceil_color[1] << 8) + map.ceil_color[2];
			else
				mlx->image_data[ray.column + (i * map.res[0])] = \
(map.floor_color[0] << 16) + (map.floor_color[1] << 8) + map.floor_color[2];
		}
		else
		{
			ray.tex_y = (int)ray.tex_pos & (ray.tex_height - 1);
			ray.tex_pos += ray.tex_step;
			mlx->image_data[i * map.res[0] + ray.column] = \
				ray.texture[ray.tex_height * ray.tex_y + ray.tex_x];
		}
		i++;
	}
}

int		*get_img_addr(void *ptr)
{
	int bpp;
	int	line_length;
	int	endian;

	return ((int *)mlx_get_data_addr(ptr, &bpp, &line_length, &endian));
}
