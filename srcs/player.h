/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:36:00 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/22 09:43:03 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct	s_player
{
	float	position_x;
	float	position_y;
	float	direction_x;
	float	direction_y;
	float	plane_x;
	float	plane_y;
	
	float	speed;
	float	rotation_angle;
	int		height;
	
	int		foward;
	int		left;
	int		right;
	int		backward;
	int		turn_left;
	int		turn_right;

	float 	last_pos_x;
	float	last_pos_y;
	float	last_dir_x;
	float	last_dir_y;
}				t_player;

# define PLAYER_X data->player.position_x
# define PLAYER_Y data->player.position_y
# define DIR_X data->player.direction_x
# define DIR_Y data->player.direction_y

#endif
