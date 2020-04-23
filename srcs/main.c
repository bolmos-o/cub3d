/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <bolmos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 16:03:10 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/04/22 17:03:42 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/cub3d.h"

void	get_texture(t_game *g)
{
	int		i;
	char	**s;

	i = 0;
	s = malloc(sizeof(char *) * TEXTURE_NUM);
	s[0] = g->pars.no;
	s[1] = g->pars.so;
	s[2] = g->pars.we;
	s[3] = g->pars.ea;
	s[4] = g->pars.s;
	s[5] = ft_strdup("pics/greenlight.xpm");
	while (i < TEXTURE_NUM)
	{
		if (!(g->tex[i].img.img = mlx_xpm_file_to_image(g->mlx,
						s[i], &g->tex[i].w, &g->tex[i].h)))
		{
			error_msg(6);
		}
		g->tex[i].img.addr = mlx_get_data_addr(g->tex[i].img.img,
				&g->tex[i].img.bpp, &g->tex[i].img.ll, &g->tex[i].img.endian);
		if (i > 4)
			free(s[i]);
		i++;
	}
	free(s);
}

void	def_position(t_pos *p, char c)
{
	if (c == 'N')
	{
		p->dir[X] = -1.0;
		p->plane[Y] = 0.66;
	}
	else if (c == 'S')
	{
		p->dir[X] = 1.0;
		p->plane[Y] = -0.66;
	}
	else if (c == 'E')
	{
		p->dir[Y] = 1.0;
		p->plane[X] = 0.66;
	}
	else if (c == 'W')
	{
		p->dir[Y] = -1.0;
		p->plane[X] = -0.66;
	}
}

void	get_position(t_pos *p, t_pars *pars)
{
	int	i;
	int	j;

	p->angle = 2;
	p->horizon = 2;
	i = 0;
	while (pars->map[i])
	{
		j = 0;
		while (pars->map[i][j])
		{
			if (ft_isalpha(pars->map[i][j]))
			{
				p->pos[X] = i;
				p->pos[Y] = j;
				def_position(p, pars->map[i][j]);
				pars->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void	init_hook(t_game *g)
{
	mlx_hook(g->win, 2, 0, keypress, g);
	mlx_hook(g->win, 3, 0, keyrelease, g);
	mlx_hook(g->win, 17, 0L, quit, g);
	mlx_loop_hook(g->mlx, render, g);
}

int		main(int argc, char **argv)
{
	t_game		*g;

	g = ft_calloc(1, sizeof(t_game));
	if (argc == 1)
		error_msg(5);
	else if (argc == 3 && !(ft_strncmp(argv[2], "--save", ft_strlen(argv[2]))))
		g->save = 1;
	else if (argc != 2)
		return (0);
	g->mlx = mlx_init();
	parsing(&g->pars, argv[1]);
	get_position(&g->pos, &g->pars);
	get_texture(g);
	g->info.speed = 0.06;
	g->info.hp = 100;
	g->jump = 16;
	g->win = mlx_new_window(g->mlx, g->pars.w, g->pars.h, "Cub3D");
	g->img.img = mlx_new_image(g->mlx, g->pars.w, g->pars.h);
	g->img.addr = mlx_get_data_addr(g->img.img,
					&g->img.bpp, &g->img.ll, &g->img.endian);
	init_hook(g);
	mlx_loop(g->mlx);
	return (0);
}
