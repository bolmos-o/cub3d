/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:50:42 by bolmos-o          #+#    #+#             */
/*   Updated: 2019/11/17 18:03:21 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char *tmp;

	tmp = src;
	if (dstsize > 1)
	{
		while (dstsize-- > 1 && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (ft_strlen(tmp));
}
