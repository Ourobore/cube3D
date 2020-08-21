/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:58:37 by lchapren          #+#    #+#             */
/*   Updated: 2020/08/21 15:36:20 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

float	*rotate_direction(float direction_x, float direction_y, float angle)
{
	float *new_direction;

	if (!(new_direction = ft_calloc(sizeof(float), 2)))
		calloc_error();
	new_direction[0] = (direction_x * cos((angle * PI) / 180.0)) -
		(direction_y * sin((angle * PI) / 180.0));
	new_direction[1] = (direction_x * sin((angle * PI) / 180.0)) +
		(direction_y * cos((angle * PI) / 180.0));
	return (new_direction);
}

double	get_distance(t_ray ray, t_player player)
{
	double distance;

	if (ray.hit_side == 0)
		distance = (double)fabs(((double)ray.map_x - player.pos_x + \
					(1.0 - (double)ray.step_x) / 2.0) / ray.raydir_x);
	else
		distance = (double)fabs(((double)ray.map_y - player.pos_y + \
					(1.0 - (double)ray.step_y) / 2.0) / ray.raydir_y);
	return (distance);
}

void	get_sprite(t_ray *ray, t_player player, t_map map)
{
	int i;

	i = get_sprite_index(ray->sp_list, map, ray->map_x, ray->map_y);
	if (ray->sp_list[i].on_screen == 0)
	{
		ray->sp_list[i].distance = get_distance(*ray, player);
		ray->sp_list[i].on_screen = 1;
	}
}

void	clean_exit(t_data *data, int exit_code)
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
	if (data->ray.camera_plane != NULL)
		free(data->ray.camera_plane);
	if (data->ray.sp_list != NULL)
		free(data->ray.sp_list);
	if (data->ray.buff_dist != NULL)
		free(data->ray.buff_dist);
	if (data->ray.texture != NULL)
		free(data->ray.texture);
	if (data->ray.tex_north != NULL)
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
		free(data->ray.ptr_sprite);
	if (data->mlx.mlx_ptr != NULL)
		free(data->mlx.mlx_ptr);
	if (data->mlx.window_ptr != NULL)
		free(data->mlx.window_ptr);
	if (data->mlx.image != NULL)
		free(data->mlx.image);
	if (data->mlx.image_data != NULL)
		free(data->mlx.image_data);
	exit(exit_code);
}
