/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:56:25 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/04/22 17:17:35 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_wcount(char const *s, char c)
{
	int	wd;

	wd = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s && *s != c)
			s++;
		if (*(s - 1) != c)
			wd++;
	}
	return (wd);
}

static	int		ft_count(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static	char	**free_ar(char **str)
{
	char **tmp;

	tmp = str;
	while (*str)
		free(*str++);
	free(tmp);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	int		wd;

	wd = 0;
	if (!s)
		return (0);
	if (!(str = malloc(sizeof(char *) * (ft_wcount(s, c) + 1))))
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (!(str[wd++] = ft_substr(s, 0, ft_count(s, c))))
				return (free_ar(str));
			s += ft_count(s, c);
		}
	}
	str[wd] = 0;
	return (str);
}
