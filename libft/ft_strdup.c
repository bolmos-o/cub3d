/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:20:58 by bolmos-o          #+#    #+#             */
/*   Updated: 2019/11/15 22:31:32 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;

	i = 0;
	if (!(dup = malloc(ft_strlen(s1) + 1)))
		return (NULL);
	while (*s1)
	{
		dup[i] = *s1++;
		i++;
	}
	dup[i] = 0;
	return (dup);
}
