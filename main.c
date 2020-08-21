/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:36:22 by lchapren          #+#    #+#             */
/*   Updated: 2020/08/21 16:27:31 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main(int ac, char **av)
{/*
	char *map_path;
	t_map map;
	int i = 0;

	(void)ac;
	map_path = ft_strdup(av[1]);
	valid_map_path(map_path);
	
	intf("\n==================MAIN================\n");
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
	}*/

	//faire une init propre de tous les modules!
	
	t_data		data;
	t_ray		ray;
	t_map		map;
	t_player	player;

	printf("\n===================MAIN===============\n");
	(void)ac;
	valid_map_path(av[1]);
	if (ac >= 3)
	{
		param_error(ac, av[2]);
		data.save = 1;
	}
	map = parse_file(get_map_file(av[1]));
	player = initial_player_position(map.map);
	data.mlx = start_mlx(map);
	ray.textures = 1;
	get_sprite_list(&ray, player, map);
	data.ray = ray;
	data.player = player;
	data.map = map;
	data.bonus = BONUS;
	if (!map_validity(data))
		perror("Map validity error\n");
	get_textures(&data, &(data.ray), data.map);
	raycasting(&data, &(data.player), &(data.ray), map);
	int	fd;
	if (data.save == 1)
	{
		if (!(fd = open("./save.bmp", O_WRONLY | O_CREAT, 0644)))
			exit(-1);
		write_bmp(data, fd);
	}
	mlx_hook(data.mlx.window_ptr, KEYPRESS, KEYPRESSMASK, key_press_hook, &data);
	mlx_hook(data.mlx.window_ptr, KEYRELEASE, KEYRELEASEMASK, key_release_hook, &data);
	mlx_hook(data.mlx.window_ptr, DESTROYNOTIFY,STRUCTNOTIFYMASK, destroy_window, &data);
	mlx_loop_hook(data.mlx.mlx_ptr, player_control, &data);
	mlx_loop(data.mlx.mlx_ptr);
	printf("\n======================================\n");
	//system("leaks Cube3D");
	
}
