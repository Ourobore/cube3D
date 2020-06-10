/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:36:22 by lchapren          #+#    #+#             */
/*   Updated: 2020/06/10 14:18:58 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main(int ac, char **av)
{
	char *map_path;
	t_map map;
	int i = 0;

	(void)ac;
	map_path = ft_strdup(av[1]);
	valid_map_path(map_path);
	
	map = init_map();
	printf("\n==================MAIN================\n");
	map = parse_file(get_map_file(map_path));

	printf("\n###############################################\n");
	printf("%s\n", map.north_texture);
	printf("%s\n", map.south_texture);
	printf("%s\n", map.west_texture);
	printf("%s\n", map.east_texture);
	printf("%s\n", map.sprite_texture);
	printf("%d %d\n", map.resolution[0], map.resolution[1]);
	printf("%d %d %d\n", map.floor_color[0], map.floor_color[1], map.floor_color[2]);
	printf("%d %d %d\n", map.ceiling_color[0], map.ceiling_color[1], map.ceiling_color[2]);
	i = 0;
	while (map.map[i])
	{
		printf("%s\n", map.map[i]);
		i++;
	}

	t_data data;

	data.mlx = start_mlx(map);
	data.map = map;
	printf("###############################################\n");
	printf("MAP_VALIDITY: [%d]\n", map_validity(data));
	printf("###############################################\n");

	t_player player;
	player = initial_player_position(map.map);
	printf("[%f][%f][%f][%f]\n", player.position_x, player.position_y, player.direction_x, player.direction_y);
	
	data.player = player;
	data = init_player(data);
	my_raycasting(&data);
	mlx_hook(data.mlx.window_ptr, KEYPRESS, KEYPRESSMASK, key_press_hook, &data);
	mlx_hook(data.mlx.window_ptr, KEYRELEASE, KEYRELEASEMASK, key_release_hook, &data);
	mlx_loop_hook(data.mlx.mlx_ptr, raycasting_loop, &data);
	mlx_loop(data.mlx.mlx_ptr);
	//main_mlx_loop(data);
	printf("\n======================================\n");
	//system("leaks Cube3D");
	
}
