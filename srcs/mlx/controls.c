/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:29:58 by lchapren          #+#    #+#             */
/*   Updated: 2020/08/21 16:36:55 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

int		key_press_hook(int key, t_data *data)
{
	if (key == ESC)
		destroy_window(data);
	if (key == FOWARD)
		data->player.foward = 1;
	if (key == LEFT)
		data->player.left = 1;
	if (key == BACKWARD)
		data->player.backward = 1;
	if (key == RIGHT)
		data->player.right = 1;
	if (key == TURNLEFT)
		data->player.turn_left = 1;
	if (key == TURNRIGHT)
		data->player.turn_right = 1;
	if (data->bonus)
		bonus_key_press(key, data);
	return (key);
}

int		key_release_hook(int key, t_data *data)
{
	if (key == FOWARD)
		data->player.foward = 0;
	if (key == LEFT)
		data->player.left = 0;
	if (key == BACKWARD)
		data->player.backward = 0;
	if (key == RIGHT)
		data->player.right = 0;
	if (key == TURNLEFT)
		data->player.turn_left = 0;
	if (key == TURNRIGHT)
		data->player.turn_right = 0;
	if (data->bonus)
		bonus_key_release(key, data);
	return (key);
}

int		player_control(t_data *data)
{
	if (data->player.foward == 1)
		move_player(*data, &data->player, data->map, 0);
	if (data->player.left == 1)
		move_player(*data, &data->player, data->map, 90);
	if (data->player.right == 1)
		move_player(*data, &data->player, data->map, -90);
	if (data->player.backward == 1)
		move_player(*data, &data->player, data->map, 180);
	if (data->player.turn_left && !data->player.turn_right)
		rotate_player(&data->player, data->player.rotation_angle);
	if (data->player.turn_right && !data->player.turn_left)
		rotate_player(&data->player, -data->player.rotation_angle);
	raycasting(data, &data->player, &data->ray, data->map);
	return (0);
}

void	move_player(t_data data, t_player *player, t_map map, float angle)
{
	float	new_pos_x;
	float	new_pos_y;

	new_pos_x = player->pos_x + (((player->dir_x * \
				cos((angle * PI) / 180.0)) - (player->dir_y * \
				sin((angle * PI) / 180.0))) * 0.1 * player->speed);
	new_pos_y = player->pos_y + (((player->dir_x * \
				sin((angle * PI) / 180.0)) + (player->dir_y * \
				cos((angle * PI) / 180.0))) * 0.1 * player->speed);
	if (!is_solid_cell(data, map, (int)(new_pos_x), (int)(player->pos_y)))
		player->pos_x = new_pos_x;
	if (!is_solid_cell(data, map, (int)(player->pos_x), (int)(new_pos_y)))
		player->pos_y = new_pos_y;
}

void	rotate_player(t_player *player, float angle)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = old_dir_x * cos((angle * PI) / 180.0) \
						- player->dir_y * sin((angle * PI) / 180.0);
	player->dir_y = old_dir_x * sin((angle * PI) / 180.0) \
						+ player->dir_y * cos((angle * PI) / 180.0);
	player->plane_x = old_plane_x * cos((angle * PI) / 180.0) \
						- player->plane_y * sin((angle * PI) / 180.0);
	player->plane_y = old_plane_x * sin((angle * PI) / 180.0) \
						+ player->plane_y * cos((angle * PI) / 180.0);
}
