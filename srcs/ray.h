/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:57:51 by lchapren          #+#    #+#             */
/*   Updated: 2020/08/21 14:37:43 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

typedef struct	s_ray
{
	double	*camera_plane;
	double	raydir_x;
	double	raydir_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	double	tex_pos;
	double	tex_step;

	t_sp	*sp_list;
	double	*buff_dist;

	int		tex_x;
	int		tex_y;
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

	float	real_x;
	float	real_y;
	float	invdet;
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
	int		x;
	int		y;
	int		move_sprite;
	int		sprite_screen_x;

	double	wall_distance;
	double	wall_height;
	int		hit_side;
	int		column;
	int		textures;
}				t_ray;

#endif
