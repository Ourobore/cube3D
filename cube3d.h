/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 10:39:44 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/13 12:00:50 by lchapren         ###   ########.fr       */
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

	char	**map;
}				t_map;

/*
**Parsing functions
*/
t_map	init_map();
t_map	parse_file(char **map_file);
t_map	call_parsing(t_map map, char *line);
char	**get_map_file(char *map_path);
char	**get_map(char **map_file);
char	*get_texture_path(char *line, char sep);
int		*get_values(char *line, char sep, int nb_values);
char	*space_trim(char *s);
char	*rm_map_spaces(char *map_line);
int		is_map_character(char c);
int		only_map_characters(char **map_file);

/*
**Map validity functions
*/
int		map_validity(t_map map);
int		valid_resolution(int *resolution, int error_number);
int		valid_color(int	*values, int error_number);
int		valid_path(char *path, int error_number);
int		closed_map(char **map, int error_number);
int		player_verification(char **map, int error_number);
int		map_verification(char **map, int i, int j, int len);

/*
**Utility functions
*/
int		get_next_line(int fd, char **line);
int		is_whitespace(char c);
int		only_spaces(char *s);
int		only_number(char *s);
int		nb_lines(char *map_path);
int		blank_line(char *line);
void	free_double_array(char **double_array);

/*
**Error functions
*/
void	calloc_error();
void	map_error();
void	map_validity_error(int error);

#endif
