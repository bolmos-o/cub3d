/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <bolmos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 16:21:18 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/04/22 16:03:35 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parsing(t_pars *pars, char *path)
{
	char	**ar;
	char	*line;
	t_list	*lst;
	int		fd;

	(!ft_strnstr(path, ".cub", ft_strlen(path))) ? error_msg(0) : 0;
	((fd = open(path, O_RDONLY)) <= 1) ? error_msg(1) : 0;
	lst = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ar = (ft_isalpha(line[0])) ? ft_split(line, ' ') : 0;
		if (ft_isalpha(line[0]) && lst == 0)
			get_values(ar, pars);
		else if (ft_isalpha(line[0]) && lst != 0)
			error_msg(2);
		else if (ft_isdigit(line[0]) || line[0] == ' ')
			ft_lstadd_back(&lst, ft_lstnew(ft_strdup(line)));
		(ar) ? free_ar((void **)ar) : 0;
		free(line);
	}
	free(line);
	close(fd);
	get_map(lst, pars);
	return (0);
}

void	get_values(char **ar, t_pars *pars)
{
	if (ar[0][0] == 'R')
	{
		pars->w = ft_atoi(ar[1]);
		pars->h = ft_atoi(ar[2]);
	}
	else if (ar[0][0] == 'N' && ar[0][1] == 'O')
		pars->no = ft_strdup(ar[1]);
	else if (ar[0][0] == 'S' && ar[0][1] == 'O')
		pars->so = ft_strdup(ar[1]);
	else if (ar[0][0] == 'W' && ar[0][1] == 'E')
		pars->we = ft_strdup(ar[1]);
	else if (ar[0][0] == 'E' && ar[0][1] == 'A')
		pars->ea = ft_strdup(ar[1]);
	else if (ar[0][0] == 'S' && ar[0][1] != 'O')
		pars->s = ft_strdup(ar[1]);
	else if (ar[0][0] == 'C')
		pars->c = get_color(ar[1]);
	else if (ar[0][0] == 'F')
		pars->f = get_color(ar[1]);
}

int		get_map(t_list *lst, t_pars *pars)
{
	int		i;
	t_list	*tmp;

	i = 0;
	if (!(pars->map = malloc(sizeof(char *) * (ft_lstsize(lst) + 1))))
		return (0);
	while (lst)
	{
		pars->map[i++] = lst->content;
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	pars->map[i] = 0;
	verify_map(pars->map);
	return (0);
}

int		get_color(char *rgb)
{
	char	**ar;
	int		color;

	ar = ft_split(rgb, ',');
	color = (ft_atoi(ar[0]) << 16 | ft_atoi(ar[1]) << 8 | ft_atoi(ar[2]) << 0);
	free_ar((void **)ar);
	return (color);
}

void	free_ar(void **ar)
{
	void	**tmp;

	tmp = ar;
	while (*ar)
		free(*ar++);
	free(tmp);
}
