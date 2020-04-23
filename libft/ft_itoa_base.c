/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 20:03:33 by bolmos-o          #+#    #+#             */
/*   Updated: 2019/12/27 03:17:21 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_ilen(int n, int blen)
{
	int		len;

	len = 1;
	while (n > blen || n < -blen)
	{
		n = n / blen;
		len++;
	}
	if (n < 0)
		len++;
	return (len);
}

char		*ft_itoa_base(int n, char *base)
{
	char	*s;
	int		len;
	int		lim;
	int		blen;

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
