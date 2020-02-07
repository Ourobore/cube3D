/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 10:39:44 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/07 13:58:33 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "./libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <mlx.h>

typedef struct	t_map
{
	int		resolution[2];
	int		floor_color[3];
	int		ceiling_color[3];
	
	char	*sprite_texture;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;

	char	**map;
}				s_map;

s_map	init_map(s_map map);
char	**get_map_file(char *map_path);

void	calloc_error();

#endif
