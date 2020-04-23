/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolmos-o <bolmos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 16:20:55 by bolmos-o          #+#    #+#             */
/*   Updated: 2020/04/22 16:56:55 by bolmos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int		pixel_find(t_img *d, int x, int y)
{
	return (*(unsigned int*)(d->addr + (y * d->ll + x * (d->bpp / 8))));
}

void	draw_walls(t_draw *d, t_game *g, int v)
{
	int		i;
	int		start;
	int		drawend;
	double	y;
	double	step;

	start = -d->lineh / g->pos.horizon + g->pars.h / g->pos.angle;
	drawend = start + d->lineh;
	start = (start < 0) ? 0 : start;
	drawend = (drawend >= g->pars.h) ? g->pars.h - 1 : drawend;
	step = 1.0 * g->tex[d->n].h / d->lineh;
	y = (start - g->pars.h / g->pos.angle + d->lineh / g->pos.horizon) * step;
	i = 0;
	while (i < start)
		pixel_put(&g->img, v, i++, g->pars.c);
	while (start < drawend)
	{
		i = pixel_find(&g->tex[d->n].img, d->x, (int)y);
		pixel_put(&g->img, v, start++, i);
		y += step;
	}
	while (drawend < (g->pars.h))
		pixel_put(&g->img, v, drawend++, g->pars.f);
}

void	draw_sprites(t_render *r, t_game *g, int v)
{
	int			color;
	int			x;
	int			y;
	t_sprite	*tmp;
	int			t;

	while (r->s)
	{
		t = (g->pars.map[r->s->pos_x][r->s->pos_y] == '3') ? 5 : 4;
		x = (int)((v - (-r->s->w / 2 + r->s->screen)) * g->tex[t].w / r->s->w);
		if (x >= 0 && x < g->tex[t].w)
			while (r->s->drawstart < r->s->drawend)
			{
				y = (((r->s->drawstart - g->pars.h / g->pos.angle + r->s->h /
						g->pos.horizon) * 256 * g->tex[t].h) / r->s->h) / 256;
				color = pixel_find(&g->tex[t].img, x, y);
				if (color != 0x00980088)
					pixel_put(&g->img, v, r->s->drawstart, color);
				r->s->drawstart++;
			}
		tmp = r->s;
		r->s = r->s->next;
		free(tmp);
	}
}

void	draw(t_render *r, t_game *g, int v)
{
	t_draw	d;
	double	perpdist;
	double	wall;

	if (r->side == 0)
	{
		perpdist = (r->map[X] - g->pos.pos[X] +
					(1 - r->step[X]) / 2) / r->raydir[X];
		wall = g->pos.pos[Y] + perpdist * r->raydir[Y];
		d.n = (r->raydir[X] >= 0) ? 0 : 1;
	}
	else
	{
		perpdist = (r->map[Y] - g->pos.pos[Y] +
					(1 - r->step[Y]) / 2) / r->raydir[Y];
		wall = g->pos.pos[X] + perpdist * r->raydir[X];
		d.n = (r->raydir[Y] >= 0) ? 2 : 3;
	}
	d.lineh = (int)(g->pars.h / perpdist);
	d.x = (int)((wall - floor(wall)) * g->tex[d.n].w);
	if ((r->side == 0 && r->raydir[X] > 0) ||
					(r->side == 1 && r->raydir[Y] < 0))
		d.x = g->tex[d.n].w - d.x - 1;
	draw_walls(&d, g, v);
}
