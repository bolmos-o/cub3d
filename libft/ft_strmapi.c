/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:10:39 by bolmos-o          #+#    #+#             */
/*   Updated: 2019/11/10 22:55:48 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	l;

	if (s == NULL)
		return (NULL);
	l = 0;
	while (s[l])
		l++;
	if (!(str = malloc(sizeof(char) * (l + 1))))
		return (0);
	l = 0;
	while (s[l])
	{
		str[l] = (*f)(l, s[l]);
		l++;
	}
	str[l] = 0;
	return (str);
}
