/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:36:00 by lchapren          #+#    #+#             */
/*   Updated: 2020/08/12 10:53:09 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct	s_player
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;

	float	speed;
	float	rotation_angle;
	float	height;

	int		foward;
	int		left;
	int		right;
	int		backward;
	int		turn_left;
	int		turn_right;

	float	last_pos_x;
	float	last_pos_y;
	float	last_dir_x;
	float	last_dir_y;
}				t_player;

#endif
