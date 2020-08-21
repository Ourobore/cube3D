/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 10:00:23 by lchapren          #+#    #+#             */
/*   Updated: 2020/08/21 12:19:34 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	bonus_key_press(int key, t_data *data)
{
	if (key == T)
	{
		data->ray.textures *= -1;
		write(1, "Untextured raycasting toogled\n", 30);
	}
	if (key == SHIFT && !data->player.sprint && !data->player.crouch)
	{
		data->player.sprint = 1;
		data->player.speed *= SPRINT;
		data->player.rotation_angle *= SPRINT;
		write(1, "Player is now sprinting\n", 24);
	}
	if (key == SPACE && !data->player.crouch && !data->player.sprint)
	{
		data->player.crouch = 1;
		data->player.height += 2.0;
		data->player.speed /= 2.0;
		write(1, "Player is now crouching\n", 24);
	}
}

void	bonus_key_release(int key, t_data *data)
{
	if (key == SHIFT && data->player.sprint)
	{
		data->player.sprint = 0;
		data->player.speed = BASE_SPEED;
		data->player.rotation_angle = ROTATION_ANGLE;
		write(1, "Player isn't sprinting anymore\n", 31);
	}
	if (key == SPACE && data->player.crouch)
	{
		data->player.crouch = 0;
		data->player.height = PLAYER_HEIGHT;
		data->player.speed = BASE_SPEED;
		write(1, "Player is now standing\n", 24);
	}
}
