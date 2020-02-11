/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:41:55 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/11 13:29:11 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

char	*get_texture_path(char *line)
{
	int i;
	int fd;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (i == 0 || i == ft_strlen(line) || (fd = open(&line[i], O_RDONLY)) == -1)
	{
		printf("Error\n");
		map_error();
	}
	//Add verification that it's the good type of file
	close(fd);
	return (ft_strdup(&line[i]));
}

int		*get_values(char *line, int nb_values)
{
	int i;
	int j;
	int *values;

	//Fonction de verif de la ligne
	i = 0;
	j = 0;
	if (!(values = ft_calloc(sizeof(int), nb_values)))
		calloc_error();
	while (line[j] && i < nb_values)
	{
		if (line[j] == ' ' || line[j] == ',')
			j++;
		while (line[j] >= '0' && line[j] <= '9')
			values[i] = (values[i] * 10) + (line[j++] - 48);
		i++;
	}
	return (values);
}

s_map	call_parsing(s_map map, char *line)
{
	if (line[0] == 'R')
		map.resolution = get_values(&line[1], 2);
	else if (line[0] == 'F')
		map.floor_color = get_values(&line[1], 3);
	else if (line[0] == 'C')
		map.ceiling_color = get_values(&line[1], 3);
	else if (line[0] == 'N' && line[1] == 'O' && !map.north_texture)
		map.north_texture = get_texture_path(&line[2]);
	else if (line[0] == 'S' && line[1] == 'O' && !map.south_texture)
		map.south_texture = get_texture_path(&line[2]);
	else if (line[0] == 'W' && line[1] == 'E' && !map.west_texture)
		map.west_texture = get_texture_path(&line[2]);
	else if (line[0] == 'E' && line[1] == 'A' && !map.east_texture)
		map.east_texture = get_texture_path(&line[2]);
	else if (line[0] == 'S' && !map.sprite_texture)
		map.sprite_texture = get_texture_path(&line[1]);
	else
		map_error();
	return (map);
}

s_map	parse_file(char **map_file)
{
	int 	i;
	int 	j;
	char	**parse;
	s_map	map;

	i = 0;
	while (map_file[i] && i < NB_ELEMENTS)
	{
		j = 0;
		while (map_file[i][j] == ' ')
			j++;
		map = call_parsing(map, &map_file[i][j]);
		i++;
	}
	//parse map
	//free_double_array(map_file);
	return (map);
}
