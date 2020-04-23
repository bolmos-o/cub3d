/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <bolmos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 16:21:01 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/04/22 15:41:37 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		quit(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	exit(0);
}

void	rotate(int key, t_pos *p)
{
	double	rotspeed;
	double	tmp;

	if (key == 123 || key == 124)
	{
		rotspeed = (key == 123) ? 0.04 : -0.04;
		tmp = p->dir[X];
		p->dir[X] = p->dir[X] * cos(rotspeed) - p->dir[Y] * sin(rotspeed);
		p->dir[Y] = tmp * sin(rotspeed) + p->dir[Y] * cos(rotspeed);
		tmp = p->plane[X];
		p->plane[X] = p->plane[X] * cos(rotspeed) - p->plane[Y] * sin(rotspeed);
		p->plane[Y] = tmp * sin(rotspeed) + p->plane[Y] * cos(rotspeed);
	}
}

void	move(int key, t_game *g)
{
	double	tmp;

	if (key == 13 || key == 1)
	{
		tmp = (key == 13) ? g->pos.dir[X] : -g->pos.dir[X];
		if (!(ft_strchr("124", g->pars.map[(int)(g->pos.pos[X] + tmp *
				g->info.speed)][(int)(g->pos.pos[Y])])))
			g->pos.pos[X] += tmp * g->info.speed;
		tmp = (key == 13) ? g->pos.dir[Y] : -g->pos.dir[Y];
		if (!(ft_strchr("124", g->pars.map[(int)g->pos.pos[X]]
				[(int)(g->pos.pos[Y] + tmp * g->info.speed)])))
			g->pos.pos[Y] += tmp * g->info.speed;
	}
	else if (key == 0 || key == 2)
	{
		tmp = (key == 0) ? g->pos.plane[X] : -g->pos.plane[X];
		if (!(ft_strchr("124", g->pars.map[(int)(g->pos.pos[X] - tmp *
					g->info.speed)][(int)(g->pos.pos[Y])])))
			g->pos.pos[X] -= tmp * g->info.speed;
		tmp = (key == 0) ? g->pos.plane[Y] : -g->pos.plane[Y];
		if (!(ft_strchr("124", g->pars.map[(int)g->pos.pos[X]]
					[(int)(g->pos.pos[Y] - tmp * g->info.speed)])))
			g->pos.pos[Y] -= tmp * g->info.speed;
	}
}

int		keyrelease(int key, t_game *g)
{
	if (key == 13)
		g->key.up = 0;
	else if (key == 1)
		g->key.down = 0;
	else if (key == 0)
		g->key.left = 0;
	else if (key == 2)
		g->key.right = 0;
	else if (key == 123)
		g->key.r_left = 0;
	else if (key == 124)
		g->key.r_right = 0;
	else if (key == 125)
		g->key.l_down = 0;
	else if (key == 126)
		g->key.l_up = 0;
	else if (key == 257)
		g->key.crouch = 0;
	return (0);
}

int		keypress(int key, t_game *g)
{
	if (key == 13)
		g->key.up = 1;
	else if (key == 1)
		g->key.down = 1;
	else if (key == 0)
		g->key.left = 1;
	else if (key == 2)
		g->key.right = 1;
	else if (key == 123)
		g->key.r_left = 1;
	else if (key == 124)
		g->key.r_right = 1;
	else if (key == 125)
		g->key.l_down = 1;
	else if (key == 126)
		g->key.l_up = 1;
	else if (key == 257)
		g->key.crouch = 1;
	else if (key == 49)
		g->key.jump = 1;
	else if (key == 14)
		g->key.use = 1;
	else if (key == 53)
		quit(g);
	return (0);
}
