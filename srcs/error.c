/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <bolmos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 16:29:55 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/04/22 17:01:28 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		error_msg(int code)
{
	if (code == 0)
		ft_printf("Error\nFile not valid.\n");
	else if (code == 1)
		ft_printf("Error\nFile not found.\n");
	else if (code == 2)
		ft_printf("Error\nMap is not the last element.\n");
	else if (code == 3)
		ft_printf("Error\nMap is not fully closed.");
	else if (code == 4)
		ft_printf("Error\nMap contains fobidden characters.\n");
	else if (code == 5)
		ft_printf("Error\nMap file not selected.\n");
	else if (code == 6)
		ft_printf("Error\nImage file invalid.\n");
	exit(1);
}

void	verify_map(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			while (map[x][y] == ' ')
				y++;
			if ((!x || !y || !(map[x + 1])
						|| map[x - 1][y] == ' ' || !(map[x - 1][y])
						|| map[x + 1][y] == ' ' || !(map[x + 1][y])
						|| map[x][y - 1] == ' ' || !(map[x][y - 1])
						|| map[x][y + 1] == ' ' || !(map[x][y + 1]))
					&& map[x][y] != '1')
				error_msg(3);
			if (!ft_strchr(MAP_CHARS, map[x][y]))
				error_msg(4);
			y++;
		}
		x++;
	}
}
