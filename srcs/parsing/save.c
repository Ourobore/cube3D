/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 09:35:41 by lchapren          #+#    #+#             */
/*   Updated: 2020/08/12 10:55:27 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	fill_oct(char *str, int data)
{
	str[0] = (unsigned char)data;
	str[1] = (unsigned char)(data >> 8);
	str[2] = (unsigned char)(data >> 16);
	str[3] = (unsigned char)(data >> 24);
}

void	fill_save(t_mlx mlx, int *res, int fd, int end)
{
	int				i;
	int				j;
	unsigned char	rgb[3];

	i = 0;
	while (i < res[1])
	{
		j = 0;
		while (j < res[0])
		{
			rgb[0] = mlx.image_data[(res[1] - i) * res[0] + j] >> 16;
			rgb[1] = mlx.image_data[(res[1] - i) * res[0] + j] >> 8;
			rgb[2] = mlx.image_data[(res[1] - i) * res[0] + j];
			write(fd, &rgb[2], 1);
			write(fd, &rgb[1], 1);
			write(fd, &rgb[0], 1);
			j++;
		}
		rgb[0] = 0;
		rgb[1] = 0;
		rgb[2] = 0;
		write(fd, rgb, end);
		i++;
	}
}

void	write_bmp(t_data data, int fd)
{
	int		size;
	int		end_line;
	char	header[14];
	char	header_img[40];

	end_line = (4 - data.map.res[0] * 3 % 4) % 4;
	size = 54 + 3 * (data.map.res[0] + end_line) * data.map.res[1];
	ft_bzero(header, sizeof(*header) * 14);
	ft_bzero(header_img, sizeof(*header_img) * 40);
	header[0] = 'B';
	header[1] = 'M';
	fill_oct(header + 2, size);
	fill_oct(header + 10, 54);
	if (write(fd, header, 14) < 0)
		exit(5);
	fill_oct(header_img, 40);
	fill_oct(header_img + 4, data.map.res[0]);
	fill_oct(header_img + 8, data.map.res[1]);
	header_img[12] = (unsigned char)1;
	fill_oct(header_img + 14, 24);
	if (write(fd, header_img, 40) < 0)
		exit(5);
	fill_save(data.mlx, data.map.res, fd, end_line);
	exit(7);
}
