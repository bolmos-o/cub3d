/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 22:32:45 by bolmos-o          #+#    #+#             */
/*   Updated: 2019/11/11 23:55:32 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	c;

	if (s == 0)
		return (0);
	c = 0;
	if (start > ft_strlen(s))
	{
		if (!(str = malloc(1)))
			return (0);
		str[0] = 0;
		return (str);
	}
	if (!(str = malloc(len + 1)))
		return (0);
	while (c < len)
	{
		str[c] = s[start];
		c++;
		start++;
	}
	str[c] = '\0';
	return (str);
}
