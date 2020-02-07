/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:41:55 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/07 16:14:25 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

char	*get_texture_path(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (i == 0 || i == ft_strlen(line))
		map_error();
	return (&line[i]);
}

int		get_values(char *line)

s_map	call_parsing(s_map map, char *line)
{
	if (line[0] == 'R')
		;
	else if (line[0] == 'F');
		;
	else if (line[0] == 'C');
		;
	else if (line[0] == 'S' && !map.sprite_texture);
		map.sprite_texture = get_texture_path(&line[1]);
	else if (line[0] == 'N' && line[1] == 'O' && !map.north_texture)
		map.north_texture = get_texture_path(&line[2]);
	else if (line[0] == 'S' && line[1] == 'O' && !map.south_texture)
		map.south_texture = get_texture_path(&line[2]);
	else if (line[0] == 'W' && line[1] == 'E' && !map.west_texture)
		map.west_texture = get_texture_path(&line[2]);
	else if (line[0] == 'E' && line[1] == 'A' && !map.east_texture)
		map.east_texture = get_texture_path(&line[2]);
	else
		map_error();
	return (map);
}

s_map	parse_file(char **map_file)
{
	int i;
	char **parse;

	i = 0;
	while (map_file[i] && i < 8)
	{
		parse = ft_split(map_file[i], ' ');
		if (parse[0] == 0 || parse[0] == 1)
			map_error();
	}
}