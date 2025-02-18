/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:58:37 by lchapren          #+#    #+#             */
/*   Updated: 2020/08/25 12:57:14 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

t_player	initial_player_position(t_map map)
{
	int			i;
	int			j;
	t_player	player;

	i = 0;
	player.pos_x = 0;
	while (map.map && map.map[i])
	{
		j = 0;
		while (map.map && map.map[i][j])
		{
			if (map.map[i][j] == 'N' || map.map[i][j] == 'E' || \
				map.map[i][j] == 'S' || map.map[i][j] == 'W')
			{
				player = get_player(map.map[i][j], i, j);
				player = get_plane(player, map.map[i][j]);
			}
			j++;
		}
		i++;
	}
	player = init_player(player);
	return (player);
}

t_player	get_player(char c, int i, int j)
{
	t_player	player;

	player.pos_x = i + 0.5;
	player.pos_y = j + 0.5;
	player.dir_x = 0.0;
	player.dir_y = 0.0;
	if (c == 'N')
		player.dir_x = -1.0;
	else if (c == 'E')
		player.dir_y = 1.0;
	else if (c == 'S')
		player.dir_x = 1.0;
	else if (c == 'W')
		player.dir_y = -1.0;
	player.speed = 1;
	return (player);
}

t_player	get_plane(t_player player, char spawn_dir)
{
	if (spawn_dir == 'N')
	{
		player.plane_y = 0.77;
		player.plane_x = 0.0;
	}
	else if (spawn_dir == 'S')
	{
		player.plane_y = -0.77;
		player.plane_x = 0.0;
	}
	else if (spawn_dir == 'W')
	{
		player.plane_y = 0.0;
		player.plane_x = -0.77;
	}
	else if (spawn_dir == 'E')
	{
		player.plane_y = 0.0;
		player.plane_x = 0.77;
	}
	return (player);
}

t_player	init_player(t_player player)
{
	player.foward = 0;
	player.left = 0;
	player.right = 0;
	player.backward = 0;
	player.turn_left = 0;
	player.turn_right = 0;
	player.sprint = 0;
	player.crouch = 0;
	player.speed = BASE_SPEED;
	player.rotation_angle = ROTATION_ANGLE;
	player.height = PLAYER_HEIGHT;
	return (player);
}
