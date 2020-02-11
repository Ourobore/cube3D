/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:23:38 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/11 16:04:47 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		all_identifiants(char **map_file)
{
	int		i;
	int		j;
	int		mask;
	
	i = 0;
	mask = 0;
	while (map_file[i] && i < NB_ELEMENTS && map_file[i][0] != '0' && map_file[i][0] != '1')
	{
		j = 0;
		while (map_file[i][0] == '\n')
		{
			i++;
			//NB_ELEMENTS++;
		}
		while (map_file[i][j] == ' ' && map_file[i][j])
			j++;
		printf("ID: %s |%d|\n", &map_file[i][j], j);
		if (map_file[i][j] == 'R')
			mask += resolution;
		else if (map_file[i][j] == 'F')
			mask += floor_color;
		else if (map_file[i][j] == 'C')
			mask += ceiling_color;
		else if (map_file[i][j] == 'N' && map_file[i][j + 1] == 'O')
			mask += north_texture;
		else if (map_file[i][j] == 'S' && map_file[i][j + 1] == 'O')
			mask += south_texture;
		else if (map_file[i][j] == 'W' && map_file[i][j + 1] == 'E')
			mask += west_texture;
		else if (map_file[i][j] == 'E' && map_file[i][j + 1] == 'A')
			mask += east_texture;
		else if (map_file[i][j] == 'S')
			mask += sprite_texture;
		else
			map_error();
		i++;
	}
	if (mask == 255)
		return (1);
	map_error();
	return (0);
}
/*
void	map_validity(char **map_file)
{
	
}*/