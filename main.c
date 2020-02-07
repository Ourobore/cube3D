/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:36:22 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/07 14:58:21 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main(int ac, char **av)
{
	char **map;
	char *map_path;
	int i = 0;
	//int j = 0;

	(void)ac;
	map_path = av[1];
	printf("\n==================MAIN================\n");
	
	map = get_map_file(map_path);
	while (map[i])
		printf("%s\n", map[i++]);
	
	printf("\n======================================\n");
	//system("leaks Cube3D");
}