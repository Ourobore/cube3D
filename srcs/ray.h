/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:57:51 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/23 11:39:01 by lchapren         ###   ########.fr       */
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
	void	*texture;
	void	*tex_north;
	void	*tex_south;
	void	*tex_west;
	void	*tex_east;
	void	*tex_sprite;

	float	wall_distance;
	int		wall_height;
	int		wall_hit;
	int		hit_side;
	int		column; // a enlever remplacer par wall_x
	int 	textures;
}				t_ray;

#endif
