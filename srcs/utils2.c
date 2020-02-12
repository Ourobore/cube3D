/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:01:29 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/12 20:39:30 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		is_map_character(char c)
{
	if (c == '0' || c == '1' || c == '2' || \
		c == 'N' || c == 'S' || c == 'W' || \
		c == 'E')
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
				is_map_character(map[i][j]) == 'S')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		map_validity_error(error_number);
	return (1);
}
