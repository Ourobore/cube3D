/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 10:14:06 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/12 16:53:39 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	calloc_error()
{
	write(1, "Error\n", 6);
	perror("Memory allocation problem");
	system("leaks Cube3D");
	exit(1);
}

void	map_error()
{
	write(1, "Error\n", 6);
	perror("Parsing map problem");
	system("leaks Cube3D");
	exit(2);
}