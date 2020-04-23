/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:56:18 by bolmos-o          #+#    #+#             */
/*   Updated: 2019/11/15 20:59:43 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = dst;
	while (n-- > 0)
	{
		if (*(unsigned char *)src == (unsigned char)c)
		{
			*tmp++ = *(unsigned char *)src;
			return (tmp);
		}
		else
			*tmp++ = *(unsigned char *)src++;
	}
	return (0);
}
