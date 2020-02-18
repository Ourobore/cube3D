/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:55:35 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/13 13:50:02 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_map	init_map(void)
{
	t_map	map;

	return (map);
}

int		is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || \
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int		only_spaces(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!is_whitespace(s[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*space_trim(char *s)
{
	int		i;
	int		j;
	int		count;
	char	*trim;

	i = 0;
	j = 0;
	while (is_whitespace(s[i]))
		i++;
	while (!only_spaces(&s[i]))
		i++;
	if (!(trim = ft_calloc(sizeof(char), i + 1)))
		calloc_error();
	i = 0;
	while (is_whitespace(s[i]))
		i++;
	while (!only_spaces(&s[i]))
		trim[j++] = s[i++];
	free(s);
	return (trim);
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
