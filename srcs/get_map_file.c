/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 10:01:37 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/11 18:18:59 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		blank_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t' || \
			line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
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

char	**get_map_file(char *map_path)
{
	int		i;
	int		r;
	int		fd;
	char	*line;
	char	**map_file;

	i = 0;
	fd = open(map_path, O_RDONLY);
	if (!(map_file = ft_calloc(sizeof(char*), nb_lines(map_path) + 1)))
		calloc_error();
	while ((r = get_next_line(fd, &line)))
	{
		if (!blank_line(line))
			map_file[i++] = ft_strdup(line);
		free(line);
	}
	if (!blank_line(line))
		map_file[i] = ft_strdup(line);
	free(line);
	return (map_file);
}
/*

int		nb_carac(char *map_, int line)
{
	int		fd;
	char	c;
	int		count;
	int		line_number;

	fd = open(map_, O_RDONLY);
	count = 0;
	line_number = 0;
	while (read(fd, &c, 1))
	{
		if (line_number == line && c != '\n')
			count++;
		if (c == '\n')
			line_number++;
	}
	close(fd);
	return (count);
}

char	**get_map_file(char *map_path)
{
	char	**map_file;
	char	c;
	int		fd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fd = open(map_path, O_RDONLY);
	if (!(map_file = ft_calloc(sizeof(char*), nb_lines(map_path) + 1)))
		calloc_error();
	while (read(fd, &c, 1))
	{
		if (j == 0 && !(map_file[i] = ft_calloc(1, nb_carac(map_path, i) + 1)))
			calloc_error();
		if (c != '\n')
			map_file[i][j++] = c;
		else
		{
			i++;
			j = 0;
		}
	}
	close(fd);
	return (map_file);
}
*/
