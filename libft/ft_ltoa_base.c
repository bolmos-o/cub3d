/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 03:18:42 by bolmos-o          #+#    #+#             */
/*   Updated: 2019/12/29 16:12:14 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	long		ft_ilen(long n, long blen)
{
	long		len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / blen;
		len++;
	}
	if (len == 0)
		len++;
	return (len);
}

char				*ft_ltoa_base(long n, char *base)
{
	char		*s;
	long		len;
	long		lim;
	long		blen;

	blen = ft_strlen(base);
	len = ft_ilen(n, blen);
	if (!(s = malloc(sizeof(char) * (len + 1))))
		return (0);
	s[len] = 0;
	lim = 0;
	if (n < 0)
	{
		s[0] = '-';
		lim = 1;
	}
	while (--len >= lim)
	{
		if (n % blen < 0)
			s[len] = base[-n % blen];
		else
			s[len] = base[n % blen];
		n = n / blen;
	}
	return (s);
}
