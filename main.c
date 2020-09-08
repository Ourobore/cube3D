/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:36:22 by lchapren          #+#    #+#             */
/*   Updated: 2020/08/25 13:18:40 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		main(int ac, char **av)
{
	t_data	data;
	char	*map_path;

	data.save = 0;
	if (av && av[1])
		map_path = ft_strdup(av[1]);
	else
		exit(0);
	valid_map_path(map_path);
	if (ac >= 3)
	{
		param_error(ac, av[2]);
		data.save = 1;
	}
	data = init_data(data, map_path);
	if (!map_validity(data))
		perror("Map validity error\n");
	get_textures(&data, &(data.ray), data.map);
	raycasting(&data, &(data.player), &(data.ray), data.map);
	loop_mlx(data);
}

t_data	init_data(t_data data, char *map_path)
{
	t_map		map;
	t_ray		ray;
	t_player	player;

	map = parse_file(get_map_file(map_path), BONUS);
	player = initial_player_position(map);
	data.mlx.mlx_ptr = mlx_init();
	valid_resolution(data, map.res, 1);
	data.mlx.window_ptr = mlx_new_window(data.mlx.mlx_ptr, \
	map.res[0], map.res[1], "Cube3D");
	ray.textures = 1;
	get_sprite_list(&ray, player, map);
	data.ray = ray;
	data.player = player;
	data.map = map;
	return (data);
}
