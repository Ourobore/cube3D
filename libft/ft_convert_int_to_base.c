/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int_to_base.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:25:33 by lchapren          #+#    #+#             */
/*   Updated: 2020/01/06 10:26:15 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*convert_int_to_base(long int nbr, char *base)
{
	long int	i;
	int			rest;
	int			length_base;
	char		*s;

	i = 0;
	if (nbr < 0)
		nbr += 4294967296;
	length_base = ft_strlen(base);
	i = get_length_int_base(nbr, base, &i);
	s = ft_calloc(sizeof(char), i + 1);
	if (nbr == 0)
		s[0] = '0';
	while (nbr != 0)
	{
		i--;
		rest = nbr % length_base;
		nbr = nbr / length_base;
		s[i] = base[rest];
	}
	return (s);
}
