/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:41:55 by lchapren          #+#    #+#             */
/*   Updated: 2020/08/25 12:17:21 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_map	parse_file(char **map_file, int bonus)
{
	int		i;
	int		j;
	t_map	map;

	i = 0;
	map.sprite_count = 0;
	if (!map_file)
		return (map);
	while (map_file[i] && i < NB_ELEMENTS)
		map = call_parsing(map, &map_file[i++][0]);
	map.map = get_map(map_file, bonus);
	i = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == '2')
				map.sprite_count++;
			j++;
		}
		i++;
	}
	free_double_array(map_file);
	return (map);
}

t_map	call_parsing(t_map map, char *line)
{
	if (line[0] == 'R')
		map.res = get_values(&line[1], ' ', 2);
	else if (line[0] == 'F')
		map.floor_color = get_values(&line[1], ',', 3);
	else if (line[0] == 'C')
		map.ceil_color = get_values(&line[1], ',', 3);
	else if (line[0] == 'N' && line[1] == 'O')
		map.north_texture = get_texture_path(line, ' ');
	else if (line[0] == 'S' && line[1] == 'O')
		map.south_texture = get_texture_path(line, ' ');
	else if (line[0] == 'W' && line[1] == 'E')
		map.west_texture = get_texture_path(line, ' ');
	else if (line[0] == 'E' && line[1] == 'A')
		map.east_texture = get_texture_path(line, ' ');
	else if (line[0] == 'S')
		map.sprite_texture = get_texture_path(line, ' ');
	else
	{
		map_error();
	}
	return (map);
}

char	*get_texture_path(char *line, char sep)
{
	int		i;
	char	*path;
	char	**split;

	i = 0;
	split = ft_split(line, sep);
	while (split[i])
		i++;
	if (i != 2)
		map_error();
	path = space_trim(ft_strdup(split[1]));
	free_double_array(split);
	return (path);
}

int		*get_values(char *line, char sep, int nb_values)
{
	int		i;
	int		*values;
	char	*tmp;
	char	**split;

	i = 0;
	while (is_whitespace(line[i]))
		i++;
	split = ft_split(&line[i], sep);
	i = 0;
	while (split[i])
		if ((split[i] = ft_strtrim(split[i], " ")) && !only_number(split[i++]))
			map_error();
	if (i != nb_values)
		map_error();
	i = -1;
	if (!(values = ft_calloc(sizeof(int), nb_values)))
		calloc_error();
	while (i++ < nb_values - 1)
		values[i] = ft_atoi(split[i]);
	free_double_array(split);
	return (values);
}

char	**get_map(char **map_file, int bonus)
{
	int		i;
	int		j;
	char	**map;

	j = 0;
	i = NB_ELEMENTS;
	while (map_file[i])
		i++;
	if (!(map = ft_calloc(sizeof(char*), i + 1)))
		calloc_error();
	i = NB_ELEMENTS;
	while (map_file[i])
		map[j++] = ft_strdup(map_file[i++]);
	if (!only_map_characters(map, bonus))
		map_error();
	return (map);
}
