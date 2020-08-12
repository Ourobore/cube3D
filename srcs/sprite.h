/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:12:09 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/27 10:11:59 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

typedef struct	s_sp
{
	float	distance;
	float	map_x;
	float	map_y;
	float	x;
	float	y;
	int		height;
	int		on_screen;
}				t_sp;

#endif
