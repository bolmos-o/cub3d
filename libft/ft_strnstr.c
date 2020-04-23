/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:34:27 by bolmos-o          #+#    #+#             */
/*   Updated: 2019/11/17 18:45:46 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t c;
	size_t cn;
	size_t ci;

	c = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (c < len && haystack[c])
	{
		cn = 0;
		ci = c;
		while (haystack[ci] == needle[cn] && ci < len)
		{
			ci++;
			cn++;
			if (needle[cn] == '\0')
				return ((char *)&haystack[ci - cn]);
		}
		c++;
	}
	return (0);
}
