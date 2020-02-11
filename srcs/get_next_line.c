/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:01:54 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/11 18:10:28 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

char	*concatenation(char *str, char c)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i])
		i++;
	if (!(ret = malloc(sizeof(char) * (i + 2))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = c;
	ret[i + 1] = 0;
	free(str);
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	int		r;
	char	c;
	char	*cat;

	if (fd < 0 || !line || !(cat = malloc(sizeof(char) * 1)))
		return (-1);
	cat[0] = 0;
	while ((r = read(fd, &c, 1)) && c != '\n')
	{
		if (r < 0)
			return (-1);
		cat = concatenation(cat, c);
	}
	*line = cat;
	return (r);
}
