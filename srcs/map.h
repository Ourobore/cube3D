/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:54:05 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/24 12:22:00 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct	s_map
{
	int		*resolution;
	int		*floor_color;
	int		*ceiling_color;

	char	*sprite_texture;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;

	int		sprites_count;

	char	**map;
}				t_map;

#endif
