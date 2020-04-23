/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <bolmos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 16:05:43 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/04/22 16:34:14 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	new_position(t_game *g)
{
	if (g->pos.pos[X] == (int)g->pos.pos[X])
		g->pos.pos[X] += 0.01;
	if (g->pos.pos[Y] == (int)g->pos.pos[Y])
		g->pos.pos[Y] += 0.01;
	if (g->key.crouch == 1)
	{
		if (g->pos.horizon > 1.3)
			g->pos.horizon = g->pos.horizon / 1.03;
		g->info.speed = 0.02;
	}
	else if (g->key.crouch == 0)
	{
		if (g->pos.horizon < 2)
			g->pos.horizon = g->pos.horizon * 1.03;
		g->info.speed = 0.06;
	}
	if (g->key.l_down == 1)
		if (g->pos.angle < 7)
			g->pos.angle = g->pos.angle + (g->pos.angle / 10);
	if (g->key.l_up == 1)
		if (g->pos.angle > 1)
			g->pos.angle = g->pos.angle - (g->pos.angle / 10);
}

void	new_position2(t_game *g)
{
	if (g->key.up == 1)
		move(13, g);
	if (g->key.down == 1)
		move(1, g);
	if (g->key.left == 1)
		move(0, g);
	if (g->key.right == 1)
		move(2, g);
	if (g->key.r_left == 1)
		rotate(123, &g->pos);
	if (g->key.r_right == 1)
		rotate(124, &g->pos);
	if (g->key.jump == 1)
		jump(g);
	if (g->key.use == 1)
		use(g);
}

void	use(t_game *g)
{
	if (g->pars.map[(int)((g->pos.pos[X] + g->pos.dir[X]))]
			[(int)(g->pos.pos[Y] + g->pos.dir[Y])] == '4')
		g->pars.map[(int)((g->pos.pos[X] + g->pos.dir[X]))]
				[(int)(g->pos.pos[Y] + g->pos.dir[Y])] = '5';
	else if (g->pars.map[(int)((g->pos.pos[X] + g->pos.dir[X]))]
			[(int)(g->pos.pos[Y] + g->pos.dir[Y])] == '5')
		g->pars.map[(int)((g->pos.pos[X] + g->pos.dir[X]))]
				[(int)(g->pos.pos[Y] + g->pos.dir[Y])] = '4';
	g->key.use = 0;
}

void	jump(t_game *g)
{
	if (g->pos.horizon < g->jump)
	{
		g->pos.horizon = g->pos.horizon * 1.13;
		if (g->pos.horizon >= g->jump)
			g->jump = 2;
	}
	else
	{
		g->pos.horizon = g->pos.horizon / 1.13;
		if (g->pos.horizon <= g->jump)
		{
			g->jump = 16;
			g->key.jump = 0;
		}
	}
}

void	draw_hp(t_game *g)
{
	int	v;
	int	i;
	int	color;

	v = 20;
	while (v < 120)
	{
		i = 20;
		color = (v < g->info.hp + 20) ? 0x00FF00 : 0xFF0000;
		while (i < 35)
			pixel_put(&g->img, v, i++, color);
		v++;
	}
}
