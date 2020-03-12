/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:29:58 by lchapren          #+#    #+#             */
/*   Updated: 2020/03/12 17:58:05 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

int	key_press_hook(int key, t_data *data)
{	
	ft_putnbr_fd(key, 1);
	if (key == 53)
	{
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.window_ptr);
		write(1, "Clean exit (escape button)\n", 27);
		//system("leaks Cube3D");
		exit(0);
	}
	if (key == 13)
		data->player.foward = 1;
	if (key == 0)
		data->player.left = 1;
	if (key == 1)
		data->player.backward = 1;
	if (key == 2)
		data->player.right = 1;
	if (key == 123)
		data->player.turn_left = 1;
	if (key == 124)
		data->player.turn_right = 1;
	if (key == 257)
	{
		data->player.speed *= SPRINT;
		data->player.rotation_angle *= SPRINT;
	}
	if (key == 46)
		write(1, "Toogle map\n", 11);
	write(1, "Key\n", 4);
	return(key);
}

int		key_release_hook(int key, t_data *data)
{
	if (key == 13)
		data->player.foward = 0;
	if (key == 0)
		data->player.left = 0;
	if (key == 1)
		data->player.backward = 0;
	if (key == 2)
		data->player.right = 0;
	if (key == 123)
		data->player.turn_left = 0;
	if (key == 124)
		data->player.turn_right = 0;
	if (key == 257)
	{
		data->player.speed /= SPRINT;
		data->player.rotation_angle /= SPRINT;
	}
	return(key);
}

void	player_control(t_data *data)
{
	if (data->player.foward == 1)
		move_player(data, 0);
	if (data->player.left == 1)
		move_player(data, -90);
	if (data->player.right == 1)
		move_player(data, 90);
	if (data->player.backward == 1)
		move_player(data, 180);
	if (data->player.turn_left && ! data->player.turn_right)
		rotate_player(data, -data->player.rotation_angle);
	if (data->player.turn_right && !data->player.turn_left)
		rotate_player(data, data->player.rotation_angle);
}

void	move_player(t_data *data, float angle)
{
	float	new_pos_x;
	float	new_pos_y;
	float	diff_x;
	float	diff_y;

	new_pos_x = data->player.position_x + (((data->player.direction_x * \
				cos((angle * PI) / 180.0)) - (data->player.direction_y * \
				sin((angle * PI) / 180.0))) * 0.1 * data->player.speed);
	new_pos_y = data->player.position_y + (((data->player.direction_x * \
				sin((angle * PI) / 180.0)) + (data->player.direction_y * \
				cos((angle * PI) / 180.0))) * 0.1 * data->player.speed);
	diff_x = fabs(new_pos_x - data->player.position_x);
	diff_y = fabs(new_pos_y - data->player.position_y);
	if (data->map.map[(int)(new_pos_x)][(int)(data->player.position_y)] != '1')
		data->player.position_x = new_pos_x;
	if (data->map.map[(int)(data->player.position_x)][(int)(new_pos_y)] != '1')
		data->player.position_y = new_pos_y;
}


void	rotate_player(t_data *data, float angle)
{
	float	direction_x;
	float	direction_y;

	direction_x = data->player.direction_x;
	direction_y = data->player.direction_y;
	data->player.direction_x = (direction_x * cos((angle * PI) / 180.0)) \
				- (direction_y * sin((angle * PI) / 180.0));
	data->player.direction_y = (direction_x * sin((angle * PI) / 180.0)) \
				+ (direction_y * cos((angle * PI) / 180.0));
}

