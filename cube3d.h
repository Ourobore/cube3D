/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 10:39:44 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/11 16:02:42 by lchapren         ###   ########.fr       */
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
# include <math.h>
# include <mlx.h>

# define NB_ELEMENTS 8

typedef enum	t_id
{
	none = 0,
	resolution = 1,
	floor_color = 2,
	ceiling_color = 4,
	sprite_texture = 8,
	north_texture = 16,
	south_texture = 32,
	west_texture = 64,
	east_texture = 128,
}				e_id;

typedef struct	t_map
{
	int		*resolution;
	int		*floor_color;
	int		*ceiling_color;
	
	char	*sprite_texture;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;

	char	**map;
}				s_map;

s_map	init_map();
int		get_next_line(int fd, char **line);
char	**get_map_file(char *map_path);
char	*get_texture_path(char *line);
int		*get_values(char *line, int nb_values);
s_map	parse_file(char **map_file);
s_map	call_parsing(s_map map, char *line);
int		all_identifiants(char **map_file);

char	**get_map_file(char *map_path);

void	calloc_error();
void	map_error();
void	free_double_array(char **double_array);

#endif
