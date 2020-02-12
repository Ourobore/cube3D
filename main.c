/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:36:22 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/12 16:59:22 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main(int ac, char **av)
{
	char **map_file;
	char *map_path;
	t_map map;
	int i = 0;
	//int j = 0;

	(void)ac;
	map_path = ft_strdup(av[1]);
	map = init_map();
	printf("\n==================MAIN================\n");
	
	map_file = get_map_file(map_path);
	while (map_file[i])
		printf("%s\n", map_file[i++]);
	
	//gerer les lignes vides et les caracteres qui ne sont pas a leur place

	printf("\n###############################################\n");
	map = parse_file(map_file);
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
	//printf("\n###############################################\n");

	printf("\n======================================\n");
	system("leaks Cube3D");
	
}