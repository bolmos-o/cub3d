/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 23:20:34 by bolmos-o          #+#    #+#             */
/*   Updated: 2019/11/11 23:40:45 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		ft_count(char const *s1, char const *set)
{
	size_t	c;
	size_t	c2;
	size_t	c3;

	c = 0;
	c2 = 0;
	c3 = 0;
	while (set[c2])
	{
		if (s1[c] == set[c2] && s1[c])
		{
			c++;
			c2 = -1;
			c3++;
		}
		c2++;
	}
	return (c3);
}

static	size_t		ft_icount(char const *s1, char const *set)
{
	size_t	c;
	size_t	c2;
	size_t	c4;

	c = ft_strlen(s1) - 1;
	c2 = 0;
	c4 = 0;
	while (set[c2])
	{
		if (s1[c] == set[c2] && s1[c])
		{
			c--;
			c2 = -1;
			c4++;
		}
		c2++;
	}
	return (c4);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	c;
	size_t	cbeg;
	size_t	cend;

	if (s1 == NULL)
		return (NULL);
	cbeg = ft_count(s1, set);
	if (!(s1[cbeg]))
	{
		if (!(s2 = malloc(1)))
			return (0);
		s2[0] = 0;
		return (s2);
	}
	cend = ft_icount(s1, set);
	if (!(s2 = malloc(ft_strlen(s1) - cbeg - cend + 1)))
		return (0);
	c = 0;
	while (cbeg < (ft_strlen(s1) - cend))
		s2[c++] = s1[cbeg++];
	s2[c] = 0;
	return (s2);
}
