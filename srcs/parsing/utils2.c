/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:01:29 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/28 14:08:42 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		only_number(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		is_map_character(char c)
{
	if (c == ' ' || c == '0' || c == '1' || \
		c == '2' || c == 'N' || c == 'S' || \
		c == 'W' || c == 'E')
		return (c);
	return (0);
}

int		only_map_characters(char **map_file)
{
	int i;
	int j;

	i = 0;
	while (map_file[i])
	{
		j = 0;
		while (map_file[i][j])
			if (!is_map_character(map_file[i][j++]))
				return (0);
		i++;
	}
	return (1);
}

int		map_verification(char **map, int i, int j, int nb_lines)
{
	int	line_len;

	line_len = ft_strlen(map[i]);
	if (i == 0 || i == nb_lines - 1 || j == 0 || j == line_len - 1 || \
		map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || \
		map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
		return (0);
	return (1);
}

int		player_verification(char **map, int error_number)
{
	int	i;
	int	j;
	int player;

	i = 0;
	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_map_character(map[i][j]) == 'N' || \
				is_map_character(map[i][j]) == 'S' || \
				is_map_character(map[i][j]) == 'W' || \
				is_map_character(map[i][j]) == 'E')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		map_validity_error(error_number);
	return (1);
}

int		is_solid_cell(t_map map, int x, int y)
{
	if (map.map[x][y] == '1' || map.map[x][y] == '2')
		return (1);
	return (0);
}

