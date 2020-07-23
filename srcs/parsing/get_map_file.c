/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 10:01:37 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/23 09:40:48 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**get_map_file(char *map_path)
{
	int		i;
	int		r;
	int		fd;
	char	*line;
	char	**map;

	i = 0;
	fd = open(map_path, O_RDONLY);
	if (!(map = ft_calloc(sizeof(char*), nb_lines(map_path) + 1)))
		calloc_error();
	while ((r = get_next_line(fd, &line)))
	{
		if (i > NB_ELEMENTS && blank_line(line))
		{
			map_error();
		}
		if (!blank_line(line))
			map[i++] = ft_strdup(line);
		free(line);
	}
	//(blank_line(line) ? map_error() : (map[i] = space_trim(ft_strdup(line))));
	free(line);
	i = NB_ELEMENTS;
	//while (map[i])
	//	((map[i] = rm_map_spaces(map[i])) && i++);
	close(fd);
	free(map_path);
	return (map);
}

int		blank_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (is_whitespace(line[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int		nb_lines(char *map_path)
{
	int		fd;
	char	c;
	int		count;
	int		previous_c;

	fd = open(map_path, O_RDONLY);
	count = 1;
	previous_c = 'a';
	while (read(fd, &c, 1))
	{
		if (c == '\n' && previous_c != '\n')
			count++;
		previous_c = c;
	}
	close(fd);
	return (count);
}

char	*rm_map_spaces(char *map_line)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	while (map_line[i])
		if (!is_whitespace(map_line[i++]))
			j++;
	if (!(new_line = ft_calloc(sizeof(char), j + 1)))
		calloc_error();
	i = 0;
	j = 0;
	while (map_line[i])
	{
		if (!is_whitespace(map_line[i]))
			new_line[j++] = map_line[i];
		i++;
	}
	free(map_line);
	return (new_line);
}
