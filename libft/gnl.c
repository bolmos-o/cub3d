/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <bolmos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:57:18 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/04/22 18:05:19 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*cpy(char *s, int start, int len)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = malloc(len + 1);
	while (i < len)
		cpy[i++] = s[start++];
	cpy[i] = 0;
	return (cpy);
}

static char	*cat(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*cat;

	i = 0;
	j = 0;
	cat = malloc(ft_strlen(s1) + ft_strlen(s2));
	while (s1[i])
	{
		cat[i] = s1[i];
		i++;
	}
	while (s2[j])
		cat[i++] = s2[j++];
	cat[i] = 0;
	free(s1);
	free(s2);
	return (cat);
}

static int	src(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int			get_next_line(int fd, char **line)
{
	int				ret;
	static char		*buf;
	int				j;
	int				chk;

	*line = 0;
	chk = 0;
	if (buf && buf[(j = src(buf, '\n'))] == '\n')
	{
		buf[j++] = '0';
		*line = cpy(buf, j, src(buf, '\n') - j);
		chk = (j + ft_strlen(*line) != BUFFER_SIZE) ? 1 : 0;
	}
	else
		buf = malloc(BUFFER_SIZE + 1);
	while (chk != 1 && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[BUFFER_SIZE] = 0;
		j = src(buf, '\n');
		chk = (buf[j] == '\n') ? 1 : 0;
		*line = (*line == 0) ? cpy(buf, 0, j) : cat(*line, cpy(buf, 0, j));
	}
	return (chk == 1) ? 1 : 0;
}
