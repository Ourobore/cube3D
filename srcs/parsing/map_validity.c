/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:23:38 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/19 10:27:12 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		map_validity(t_data data)
{
	valid_resolution(data, data.map.resolution, 1);
	valid_color(data.map.floor_color, 2);
	valid_color(data.map.ceiling_color, 3);
	valid_path(data.map.north_texture, 11);
	valid_path(data.map.south_texture, 12);
	valid_path(data.map.west_texture, 13);
	valid_path(data.map.east_texture, 14);
	valid_path(data.map.sprite_texture, 15);
	closed_map(data.map.map, 4);
	player_verification(data.map.map, 5);
	return (1);
}

int		valid_resolution(t_data data, int *resolution, int err_num)
{
	int	size_x;
	int	size_y;

	if (resolution[0] < 1 || resolution[1] < 1)
		map_validity_error(err_num);
	mlx_get_screen_size(data.mlx.mlx_ptr, &size_x, &size_y);
	if (resolution[0] > size_x)
		resolution[0] = size_x;
	if (resolution[1] > size_y)
		resolution[1] = size_y;
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
	int nb_lines;
	//int line_len;

	i = 0;
	nb_lines = 0;
	while (map[nb_lines])
		nb_lines++;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != ' ' && \
				!map_verification(map, i, j, nb_lines))
				map_validity_error(error_number);
			j++;
		}
		i++;
	}
	return (1);
}
