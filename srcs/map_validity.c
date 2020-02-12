/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:23:38 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/12 20:18:11 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		map_validity(t_map map)
{
	valid_resolution(map.resolution, 1);
	valid_color(map.floor_color, 2);
	valid_color(map.ceiling_color, 3);
	valid_path(map.north_texture, 11);
	valid_path(map.south_texture, 12);
	valid_path(map.west_texture, 13);
	valid_path(map.east_texture, 14);
	valid_path(map.sprite_texture, 15);
	closed_map(map.map, 4);
	player_verification(map.map, 5);
	return (1);
}

int		valid_resolution(int *resolution, int error_number)
{
	if (resolution[0] < 1 || resolution[1] < 1)
		map_validity_error(error_number);
	if (resolution[0] < 500)
		resolution[0] = 500;
	if (resolution[1] < 500)
		resolution[1] = 500;
	if (resolution[0] > 5120)
		resolution[0] = 5120;
	if (resolution[1] > 2880)
		resolution[1] = 2880;
	return (1);
}

int		valid_color(int *values, int error_number)
{
	if (values[0] < 0 || values[0] > 255 || values[1] < 0 || \
		values[1] > 255 || values[2] < 0 || values[2] > 255)
		map_validity_error(error_number);
	return (1);
}

int		valid_path(char *path, int error_number)
{
	int fd;

	if ((fd = open(path, O_RDONLY)) == -1)
		map_validity_error(error_number);
	//Check file type
	close(fd);
	return (1);
}

int		closed_map(char **map, int error_number)
{
	int i;
	int j;
	int len;
	int line_len;

	i = 0;
	len = 0;
	while (map[len])
		len++;
	while (map[i])
	{
		j = 0;
		line_len = ft_strlen(map[i]);
		while (map[i][j])
		{
			if ((i == 0 && map[i][j] != '1') || \
				(i == len && map[i][j] != '1') || \
				(j == 0 && map[i][j] != '1') || \
				(j == line_len && map[i][j] != '1'))
				map_validity_error(error_number);
			j++;
		}
		i++;
	}
	return (1);
}
