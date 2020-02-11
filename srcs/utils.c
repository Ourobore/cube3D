/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:55:35 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/11 13:22:52 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

s_map	init_map()
{
	s_map	map;
	
	if (!(map.resolution = ft_calloc(sizeof(int), 2)))
		calloc_error();
	if (!(map.floor_color = ft_calloc(sizeof(int), 3)))
		calloc_error();
	if (!(map.ceiling_color = ft_calloc(sizeof(int), 3)))
		calloc_error();
		
/*
	map.resolution[0] = 0;
	map.resolution[1] = 0;

	map.floor_color[0] = 0;
	map.floor_color[1] = 0;
	map.floor_color[2] = 0;

	map.ceiling_color[0] = 0;
	map.ceiling_color[1] = 0;
	map.ceiling_color[2] = 0;
*/
	return (map);
}

void	free_double_array(char **double_array)
{
	int i;
	
	i = 0;
	while (double_array[i])
	{
		free(double_array[i]);
		i++;
	}
	free(double_array);
}