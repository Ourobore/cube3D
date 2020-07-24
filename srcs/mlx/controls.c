/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:29:58 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/24 12:05:07 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

int	key_press_hook(int key, t_data *data)
{	
	ft_putnbr_fd(key, 1);
	if (key == ESC)
	{
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.window_ptr);
		write(1, "Clean exit (escape button)\n", 27);
		//system("leaks Cube3D");
		exit(0);
	}
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
	if (key == SHIFT && data->bonus)
	{
		data->player.speed *= SPRINT;
		data->player.rotation_angle *= SPRINT;
	}
	if (key == T && data->bonus)
	{
		data->ray.textures *= -1; // relancer un raycast pour actualiser sans bouger
		raycasting(data, &(data->player), &(data->ray), data->map);
		write(1, "Untextured raycasting toogled\n", 30);
	}
	if (key == CONTROL && data->bonus)
	{
		if (data->player.height != PLAYER_HEIGHT)
		{
			data->player.height = PLAYER_HEIGHT;
			data->player.speed = BASE_SPEED;
			write(1, "Player now standing\n", 21);
		}
		else
		{
			data->player.height += 2;
			data->player.speed /= 2;
			write(1, "Player now couching\n", 22);
		}
		raycasting(data, &(data->player), &(data->ray), data->map);
	}
	if (key == M)
		write(1, "Toogled map\n", 12);
	write(1, "Key\n", 4);
	return(key);
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
	if (key == SHIFT)
	{
		data->player.speed /= SPRINT;
		data->player.rotation_angle /= SPRINT;
	}
	return(key);
}

void	player_control(t_player *player, t_map map)
{
	if (player->foward == 1)
		move_player(player, map,  0);
	if (player->left == 1)
		move_player(player, map, 90);
	if (player->right == 1)
		move_player(player, map, -90);
	if (player->backward == 1)
		move_player(player, map, 180);
	if (player->turn_left && ! player->turn_right)
		rotate_player(player, player->rotation_angle);
	if (player->turn_right && !player->turn_left)
		rotate_player(player, -player->rotation_angle);
}

void	move_player(t_player *player, t_map map, float angle)
{
	float	new_pos_x;
	float	new_pos_y;
	float	diff_x;
	float	diff_y;
	
	new_pos_x = player->position_x + (((player->direction_x * \
				cos((angle * PI) / 180.0)) - (player->direction_y * \
				sin((angle * PI) / 180.0))) * 0.1 * player->speed);
	new_pos_y = player->position_y + (((player->direction_x * \
				sin((angle * PI) / 180.0)) + (player->direction_y * \
				cos((angle * PI) / 180.0))) * 0.1 * player->speed);
	diff_x = fabs(new_pos_x - player->position_x);
	diff_y = fabs(new_pos_y - player->position_y);
	if (map.map[(int)(new_pos_x)][(int)(player->position_y)] != '1')
		player->position_x = new_pos_x;
	if (map.map[(int)(player->position_x)][(int)(new_pos_y)] != '1')
		player->position_y = new_pos_y;
}


void	rotate_player(t_player *player, float angle)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = player->direction_x;
	old_plane_x = player->plane_x;
	player->direction_x = old_dir_x * cos((angle * PI) / 180.0) \
						  - player->direction_y * sin((angle * PI) / 180.0);
	player->direction_y = old_dir_x * sin((angle * PI) / 180.0) \
						  + player->direction_y * cos((angle * PI) / 180.0);
	player->plane_x = old_plane_x * cos((angle * PI) / 180.0) \
						  - player->plane_y * sin((angle * PI) / 180.0);
	player->plane_y = old_plane_x * sin((angle * PI) / 180.0) \
						  + player->plane_y * cos((angle * PI) / 180.0);
/*	
	player->direction_x = (direction_x * cos((angle * PI) / 180.0)) \
				- (direction_y * sin((angle * PI) / 180.0));
	player->direction_y = (direction_x * sin((angle * PI) / 180.0)) \
	+ (direction_y * cos((angle * PI) / 180.0));
*/
}

