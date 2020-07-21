/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 10:14:06 by lchapren          #+#    #+#             */
/*   Updated: 2020/07/21 12:54:38 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	calloc_error(void)
{
	write(1, "Error\n", 6);
	perror("Memory allocation problem");
	system("leaks Cube3D");
	exit(1);
}

void	map_error(void)
{
	write(1, "Error\n", 6);
	perror("Parsing map problem");
	system("leaks Cube3D");
	exit(2);
}

void	map_validity_error(int error)
{
	write(1, "Error\n", 6);
	if (error == 1)
		perror("Invalid resolution");
	else if (error == 2)
		perror("Invalid floor color");
	else if (error == 3)
		perror("Invalid ceiling color");
	else if (error == 4)
		perror("Unclosed map");
	else if (error == 5)
		perror("Player placement problem");
	else if (error == 11)
		perror("Invalid north texture path");
	else if (error == 12)
		perror("Invalid south texture path");
	else if (error == 13)
		perror("Invalid west texture path");
	else if (error == 14)
		perror("Invalid east texture path");
	else if (error == 15)
		perror("Invalid sprite texture path");
	else if (error == 16)
		perror("Invalid map file path");
	//system("leaks Cube3D");
	exit(3);
}

int		valid_map_path(char *map_path)
{
	int fd;

	if (map_path[ft_strlen(map_path) - 4] != '.' || \
		map_path[ft_strlen(map_path) - 3] != 'c' || \
		map_path[ft_strlen(map_path) - 2] != 'u' || \
		map_path[ft_strlen(map_path) - 1] != 'b' || \
		(fd = open(map_path, O_RDONLY)) == -1)
		map_validity_error(16);
	close(fd);
	return (1);
}
