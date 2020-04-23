/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:53:39 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/04/22 17:05:20 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int	get_len(int n)
{
	if (n / 10 == 0)
		return (n < 0) ? 2 : 1;
	return (1 + get_len(n / 10));
}

char		*ft_itoa(int n)
{
	char	*s;
	int		len;

	len = get_len(n);
	if (!(s = ft_calloc(sizeof(char), (len + 1))))
		return (0);
	if (n < 0)
		s[0] = '-';
	while (!(s[--len]))
	{
		s[len] = (n < 0) ? -(n % 10) + '0' : (n % 10) + '0';
		n /= 10;
	}
	return (s);
}
