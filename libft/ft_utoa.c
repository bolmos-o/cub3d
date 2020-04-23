/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 20:23:40 by bolmos-o          #+#    #+#             */
/*   Updated: 2019/12/16 20:29:38 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_ilen(unsigned int n)
{
	int		len;

	len = 1;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_utoa(unsigned int n)
{
	char	*s;
	int		len;

	len = ft_ilen(n);
	if (!(s = malloc(sizeof(char) * (len + 1))))
		return (0);
	s[len] = 0;
	while (--len >= 0)
	{
		s[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (s);
}
