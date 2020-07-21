/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:57:51 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/21 10:23:42 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

typedef struct	s_ray
{
	float	*camera_plane;
	float	raydir_x;
	float	raydir_y;

	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		wall_hit;
	int		hit_side;
	int		column;

	float	delta_x;
	float	delta_y;
	float	side_x;
	float	side_y;
	float	tex_x;
	float	tex_y;
	float	wall_distance;
	int		wall_height;
	int 	textures;
}				t_ray;

# define DELTA_X data->ray.delta_x
# define DELTA_Y data->ray.delta_y
# define MAP_X data->ray.map_x
# define MAP_Y data->ray.map_y
# define STEP_X data->ray.step_x
# define STEP_Y data->ray.step_y
# define SIDE_X data->ray.side_x
# define SIDE_Y data->ray.side_y
# define DISTANCE data->ray.distance

#endif
