/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 10:01:37 by lchapren          #+#    #+#             */
/*   Updated: 2020/08/25 11:53:07 by lchapren         ###   ########.fr       */
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
	if (!map_path || (fd = open(map_path, O_RDONLY)) == -1)
		return (NULL);
	if (!(map = ft_calloc(sizeof(char*), nb_lines(map_path) + 1)))
		calloc_error();
	while ((r = get_next_line(fd, &line)))
	{
		if (i > NB_ELEMENTS && blank_line(line))
			map_error();
		if (!blank_line(line))
			map[i++] = ft_strdup(line);
		free(line);
	}
	free(line);
	i = NB_ELEMENTS;
	close(fd);
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

	if ((fd = open(map_path, O_RDONLY)) == -1)
		return (-1);
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
