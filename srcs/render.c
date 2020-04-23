/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <bolmos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 16:13:02 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/04/22 16:35:22 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		render(t_game *g)
{
	t_render	r;
	int			v;

	new_position(g);
	new_position2(g);
	if (g->pars.map[(int)(g->pos.pos[X])][(int)(g->pos.pos[Y])] == '3')
		g->info.hp -= 1;
	v = 0;
	r.s = 0;
	r.invdet = 1.0 / (g->pos.plane[X] * g->pos.dir[Y] -
					g->pos.dir[X] * g->pos.plane[Y]);
	while (v < g->pars.w)
	{
		get_delta(g, &r, v);
		get_dist(g, &r);
		draw(&r, g, v);
		draw_sprites(&r, g, v);
		v++;
	}
	draw_hp(g);
	if (g->save == 1)
		save_screen(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
	return (0);
}

void	get_delta(t_game *g, t_render *r, int v)
{
	int		i;
	double	camera;

	camera = 2 * v / (double)g->pars.w - 1;
	i = X;
	while (i < 2)
	{
		r->raydir[i] = g->pos.dir[i] + g->pos.plane[i] * camera;
		r->map[i] = (int)g->pos.pos[i];
		r->delta[i] = fabs(1 / r->raydir[i]);
		if (r->raydir[i] < 0)
		{
			r->step[i] = -1;
			r->dist[i] = (g->pos.pos[i] - r->map[i]) * r->delta[i];
		}
		else
		{
			r->step[i] = 1;
			r->dist[i] = (r->map[i] + 1.0 - g->pos.pos[i]) * r->delta[i];
		}
		i++;
	}
}

void	get_dist(t_game *g, t_render *r)
{
	int		hit;
	int		pos;

	hit = 0;
	while (hit == 0)
	{
		pos = (r->dist[X] < r->dist[Y]) ? X : Y;
		r->dist[pos] += r->delta[pos];
		r->map[pos] += r->step[pos];
		r->side = pos;
		if (ft_strchr("236", g->pars.map[r->map[X]][r->map[Y]]))
			calc_sprite(r, g);
		hit = (ft_strchr("14", g->pars.map[r->map[X]][r->map[Y]])) ? 1 : 0;
	}
}

int		sprite_list(t_sprite **alst, int pos_x, int pos_y)
{
	t_sprite	*n;

	if (!(n = malloc(sizeof(t_sprite))))
		return (0);
	n->pos_x = pos_x;
	n->pos_y = pos_y;
	n->next = 0;
	if (*alst)
	{
		n->next = *alst;
		*alst = n;
	}
	else
		*alst = n;
	return (0);
}

void	calc_sprite(t_render *r, t_game *g)
{
	double	sprite[2];
	double	transform[2];

	sprite_list(&r->s, r->map[X], r->map[Y]);
	sprite[X] = r->s->pos_x + 0.5 - g->pos.pos[X];
	sprite[Y] = r->s->pos_y + 0.5 - g->pos.pos[Y];
	transform[X] = r->invdet *
			(g->pos.dir[Y] * sprite[X] - g->pos.dir[X] * sprite[Y]);
	transform[Y] = r->invdet *
			(-(g->pos.plane[Y]) * sprite[X] + g->pos.plane[X] * sprite[Y]);
	r->s->screen = (int)((g->pars.w / 2) * (1 + transform[X] / transform[Y]));
	r->s->h = abs((int)(g->pars.h / (transform[Y])));
	r->s->w = abs((int)(g->pars.h / (transform[Y])));
	r->s->drawstart = -r->s->h / g->pos.horizon + g->pars.h / g->pos.angle;
	r->s->drawend = r->s->drawstart + r->s->h;
	if (r->s->drawstart < 0)
		r->s->drawstart = 0;
	if (r->s->drawend >= g->pars.h)
		r->s->drawend = g->pars.h - 1;
}
