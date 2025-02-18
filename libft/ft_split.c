/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 07:52:54 by lchapren          #+#    #+#             */
/*   Updated: 2020/02/13 13:17:40 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_chaines(char const *s, char c)
{
	size_t	i;
	size_t	is_sep;
	size_t	nb_word;

	i = 0;
	is_sep = 0;
	nb_word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!is_sep)
				nb_word++;
			is_sep = 1;
		}
		else
			is_sep = 0;
		i++;
	}
	return (nb_word);
}

static char	*ft_strndup(const char *s, size_t len)
{
	char	*retour;
	size_t	taille;
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char*)s;
	taille = (len < ft_strlen(s) ? len : ft_strlen(s));
	if (!(retour = ft_calloc(taille + 1, sizeof(char))))
		return (NULL);
	while (i < taille)
	{
		retour[i] = tmp[i];
		i++;
	}
	return (retour);
}

static char	*get_word(char **str, char c)
{
	char	*start;
	char	*retour;

	while (**str && **str == c)
		*str = *str + 1;
	start = *str;
	while (**str && **str != c)
		*str = *str + 1;
	if (!(retour = ft_strndup(start, (size_t)(*str - start))))
		return (NULL);
	return (retour);
}

static void	free_tab(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char		**ft_split(const char *s, char c)
{
	char	**split;
	char	*tmp;
	int		nb_word;
	int		i;

	i = 0;
	nb_word = 0;
	if (!s)
		return (NULL);
	tmp = (char*)s;
	nb_word = nb_chaines(s, c);
	if (!(split = ft_calloc(sizeof(char*), nb_word + 1)))
		return (NULL);
	while (i < nb_word)
	{
		if (!(split[i] = get_word(&tmp, c)))
		{
			free_tab(split);
			return (NULL);
		}
		i++;
	}
	return (split);
}
