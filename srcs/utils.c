/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:55:35 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/07 14:10:47 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

s_map	init_map(s_map map)
{
	map.resolution[0] = -1;
	map.resolution[1] = -1;

	map.floor_color[0] = -1;
	map.floor_color[1] = -1;
	map.floor_color[2] = -1;

	map.ceiling_color[0] = -1;
	map.ceiling_color[1] = -1;
	map.ceiling_color[2] = -1;

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