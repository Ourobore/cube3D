/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:58:37 by lchapren          #+#    #+#             */
/*   Updated: 2020/03/06 14:29:39 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

t_player	initial_player_position(char **map)
{
	int			i;
	int			j;
	t_player	player;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' || \
				map[i][j] == 'S' || map[i][j] == 'W')
				player = get_player(map[i][j], i, j);
			j++;
		}
		i++;
	}
	return (player);
}

t_player	get_player(char c, int i, int j)
{
	t_player	player;

	player.position_x = i + 0.5;
	player.position_y = j + 0.5;
	player.direction_x = 0.0;
	player.direction_y = 0.0;
	if (c == 'N')
		player.direction_x = -1.0;
	else if (c == 'E')
		player.direction_y = 1.0;
	else if (c == 'S')
		player.direction_x = 1.0;
	else if (c == 'W')
		player.direction_y = -1.0;
	return (player);
}
