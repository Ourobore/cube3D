/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:12:09 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/25 14:12:20 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

typedef struct  s_sp
{
	float	distance;
	float	map_x;
	float	map_y;
	float	x;
	float	y;
	int		sp_height;
}               t_sp;

#endif
