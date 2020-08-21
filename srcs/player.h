/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:36:00 by lchapren          #+#    #+#             */
/*   Updated: 2020/08/21 11:26:12 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct	s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	double	sprint;
	double	crouch;
	double	speed;
	double	rotation_angle;
	double	height;

	int		foward;
	int		left;
	int		right;
	int		backward;
	int		turn_left;
	int		turn_right;
}				t_player;

#endif
