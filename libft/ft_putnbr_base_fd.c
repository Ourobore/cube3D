/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:27:18 by lchapren          #+#    #+#             */
/*   Updated: 2020/01/06 10:28:05 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_base_fd(long int nbr, int fd, char *base)
{
	long int		nbl;
	unsigned int	longueur_b;
	unsigned int	i;

	i = 0;
	nbl = nbr;
	longueur_b = ft_strlen(base);
	if (nbl < 0)
	{
		write(1, "-", 1);
		nbl = nbl * -1;
	}
	if (nbl >= 0 && nbl <= longueur_b - 1)
		ft_putchar_fd(base[nbl], fd);
	else
	{
		ft_putnbr_base_fd(nbl / longueur_b, fd, base);
		ft_putchar_fd(base[(nbl % longueur_b)], fd);
	}
}
