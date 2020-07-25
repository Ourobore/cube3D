/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:36:22 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/25 10:39:09 by lchapren         ###   ########.fr       */
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
	}*/
	//faire une init propre de tous les modules!
	
	t_data		data;
	t_ray		ray;
	t_map		map;
	t_player	player;

	printf("\n===================MAIN===============\n");
	(void)ac;
	valid_map_path(av[1]);
	map = parse_file(get_map_file(ft_strdup(av[1])));
	player = initial_player_position(map.map);
	data.mlx = start_mlx(map);
	ray.textures = 1;
	ray.sprite_list = ft_calloc(sizeof(float*), map.sprites_count);
	ray.sprite_map_x = ft_calloc(sizeof(int*), map.sprites_count);
	ray.sprite_map_y = ft_calloc(sizeof(int*), map.sprites_count);
	printf("SPRITES COUNT: %d\n", map.sprites_count);
	data.ray = ray;
	data.player = player;
	data.map = map;
	data.bonus = BONUS;
	if (!map_validity(data))
		perror("Map validity error\n");
	//printf("TEX WIDTH:%d TEX HEIGHT: %d", )
	get_textures(&data, &(data.ray), data.map);
	raycasting(&data, &(data.player), &(data.ray), map);
	mlx_hook(data.mlx.window_ptr, KEYPRESS, KEYPRESSMASK, key_press_hook, &data);
	mlx_hook(data.mlx.window_ptr, KEYRELEASE, KEYRELEASEMASK, key_release_hook, &data);
	mlx_loop_hook(data.mlx.mlx_ptr, raycasting_loop, &data);
	mlx_loop(data.mlx.mlx_ptr);
	printf("\n======================================\n");
	//system("leaks Cube3D");
	
}
/*
t_map	get_map_file(char *map_path)
{
	t_map map;

	valid_map_path(map_path);
	//map = ini_map(); fonction a supprimer
	map = parse_file(get_map_file(map_path));
	ft_putstr_fd(map.north_texture, 0);

}*/
