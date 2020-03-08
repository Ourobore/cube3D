/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:36:00 by lchapren          #+#    #+#             */
/*   Updated: 2020/03/08 14:46:55 by lchapren         ###   ########.fr       */
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
	
	int		dda_x;
	int		dda_y;
	float	speed;
	float	crouch;
}				t_player;

# define PLAYER_X data->player.position_x
# define PLAYER_Y data->player.position_y
# define DIR_X data->player.direction_x
# define DIR_Y data->player.direction_y

#endif
