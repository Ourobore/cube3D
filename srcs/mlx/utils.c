/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:58:37 by lchapren          #+#    #+#             */
/*   Updated: 2020/03/08 15:29:50 by lchapren         ###   ########.fr       */
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
	player.speed = 1;
	return (player);
}

t_data	new_image(t_data data)
{
	int bpp;
	int line_length;
	int endian;

	if (data.mlx.image)
		mlx_destroy_image (data.mlx.mlx_ptr, data.mlx.image);
	data.mlx.image = mlx_new_image(data.mlx.mlx_ptr, data.map.resolution[0], data.map.resolution[1]);
	data.mlx.image_data = (int*)mlx_get_data_addr(data.mlx.image, &bpp, &line_length, &endian);
	return (data);
}

float *rotate_direction(float direction_x, float direction_y, float angle)
{
	float *new_direction;

	if (!(new_direction = ft_calloc(sizeof(float), 2)))
		calloc_error();
	new_direction[0] = (direction_x * cos((angle * PI) / 180.0) -
						(direction_y * sin((angle * PI) / 180.0)));
	new_direction[1] = (direction_x * sin((angle * PI) / 180.0)) +
					   (direction_y * cos((angle * PI) / 180.0));
	return (new_direction);
}

t_data	move_player(t_data data, float angle)
{
	float	*new_direction;
	new_direction = \
	rotate_direction(data.player.direction_x, data.player.direction_y, angle);
	data.player.position_x += new_direction[0] * 0.1 * data.player.speed;
	data.player.position_y += new_direction[1] * 0.1 * data.player.speed;
	free(new_direction);
	return (data);
}
