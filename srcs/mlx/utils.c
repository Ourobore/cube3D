/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:58:37 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/21 14:29:20 by lchapren         ###   ########.fr       */
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
			{
				player = get_player(map[i][j], i, j);
				player = get_plane(player, map[i][j]);
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
	player.last_pos_x = 1.0;
	player.last_pos_y = 1.0;
	player.last_dir_x = 1.0;
	player.last_dir_y = 1.0;

	return (player);
}

t_player get_plane(t_player player, char spawn_dir)
{
    if (spawn_dir == 'N')
    {
        player.plane_x = 1.0;
        player.plane_y = 0.0;
    }
    else if (spawn_dir == 'S')
    {
        player.plane_x = -1.0;
        player.plane_y = 0.0;
    }
    else if (spawn_dir == 'W')
    {
        player.plane_x = 0.0;
        player.plane_y = -1.0;
    }
    else if (spawn_dir == 'E')
    {
        player.plane_x = 0.0;
        player.plane_y = 1.0;
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
	player.speed = 1;
	player.rotation_angle = 3;
	player.height = 2;
	return (player);
}
//ces deux fonctions peuvent aller dans mlx.c
t_data	new_image(t_data data)
{
	int bpp;
	int line_length;
	int endian;

	data.mlx.image = mlx_new_image(data.mlx.mlx_ptr, data.map.resolution[0], data.map.resolution[1]);
	data.mlx.image_data = (int*)mlx_get_data_addr(data.mlx.image, &bpp, &line_length, &endian);
	return (data);
}

int		raycasting_loop(t_data *data)
{
	//printf("loop\n");
	player_control(&(data->player), data->map);
	if (player_moved(data)/* && data->mlx.rendered == 1*/)
	{
		data->mlx.rendered = 0;
		mlx_destroy_image (data->mlx.mlx_ptr, data->mlx.image);
		raycasting(data, &(data->player), data->ray, data->map);
	}
	return (1);
}
/*
float *rotate_direction(float raydir[], float angle)
{
	float direction_x;
	float direction_y;

	direction_x = raydir[0];
	direction_y = raydir[1];
	raydir[0] = (direction_x * cos((angle * PI) / 180.0) -
				(direction_y * sin((angle * PI) / 180.0)));
	raydir[1] = (direction_x * sin((angle * PI) / 180.0)) +
				(direction_y * cos((angle * PI) / 180.0));
	return (raydir);
}

*/
float *rotate_direction(float direction_x, float direction_y, float angle)
{
	float *new_direction;

	if (!(new_direction = ft_calloc(sizeof(float), 2)))
		calloc_error();
	new_direction[0] = (direction_x * cos((angle * PI) / 180.0)) -
						(direction_y * sin((angle * PI) / 180.0));
	new_direction[1] = (direction_x * sin((angle * PI) / 180.0)) +
					   (direction_y * cos((angle * PI) / 180.0));
	return (new_direction);
}

int		player_moved(t_data *data)
{
	if (data->player.last_pos_x == data->player.position_x && \
		data->player.last_pos_y == data->player.position_y && \
		data->player.last_dir_x == data->player.direction_x && \
		data->player.last_dir_y == data->player.direction_y)
		return (0);
	else
		return (1);
}
