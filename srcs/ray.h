/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:57:51 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/23 14:05:51 by lchapren         ###   ########.fr       */
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
	float	delta_x;
	float	delta_y;
	float	side_x;
	float	side_y;

	int		wall_x;

	float	tex_x;
	float	tex_y;
	int		tex_width;
	int		tex_height;
	int		*texture;
	int		*tex_north;
	int		*tex_south;
	int		*tex_west;
	int		*tex_east;
	int		*tex_sprite;
	void	*ptr_north;
	void	*ptr_south;
	void	*ptr_west;
	void	*ptr_east;
	void	*ptr_sprite;

	float	wall_distance;
	int		wall_height;
	int		wall_hit;
	int		hit_side;
	int		column; // a enlever remplacer par wall_x
	int 	textures;
}				t_ray;

#endif
