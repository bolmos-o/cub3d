/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 22:48:12 by bolmos-o          #+#    #+#             */
/*   Updated: 2019/11/11 23:18:04 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	long	i;
	char	*str;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	if (!(str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	while (*s1)
		str[i++] = *s1;
	while (*s2)
		str[i++] = *s2++;
	str[i] = 0;
	return (str);
}
