/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 08:07:46 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/03 10:56:43 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

extern int map[];

void			hori_intersection(t_player *p, t_hit *hori, double ra)
{
	int mx, my, mp, dof;
	float rx, ry, x0, y0;
	float aatan;

	dof = 0;
	aatan = -1 / tan(ra);
	if (ra > PI)
	{
		ry = (((int)p->pos.y >> 6) << 6) - 0.0001;
		rx = (p->pos.y - ry) * aatan + p->pos.x;
		y0 = -64;
		x0 = -y0 * aatan;
	}
	if (ra < PI)
	{
		ry = (((int)p->pos.y >> 6) << 6) + 64;
		rx = (p->pos.y - ry) * aatan + p->pos.x;
		y0 = 64;
		x0 = -y0 * aatan;
	}
	if (ra == 0 || ra == PI)
	{
		rx = p->pos.x;
		ry = p->pos.y;
		dof = 14;
	}
	while (dof < 14)
	{
		mx = (int)(rx) >> 6;
		my = (int)(ry) >> 6;
		mp = my * 14 + mx;
		if (mp < 196 && mp > 0 && map[mp] == 1)
			break;
		else
		{
			rx += x0;
			ry += y0;
			dof++;
		}
	}
	hori->dist = sqrt((rx - p->pos.x) * (rx - p->pos.x) + (ry - p->pos.y) * (ry - p->pos.y));
	hori->p.x = rx;
	hori->p.y = ry;
}

void		vert_intersection(t_player *p, t_hit *vert, double ra)
{
	int mx, my, mp, dof;
	float rx, ry, x0, y0;
	float aatan;

	dof = 0;
	aatan = -tan(ra);
	if (ra > P2 && ra < P3)
	{
		rx = (((int)p->pos.x >> 6) << 6) - 0.0001;
		ry = (p->pos.x - rx) * aatan + p->pos.y;
		x0 = -64;
		y0 = -x0 * aatan;
	}
	if (ra < P2 || ra > P3)
	{
		rx = (((int)p->pos.x >> 6) << 6) + 64;
		ry = (p->pos.x - rx) * aatan + p->pos.y;
		x0 = 64;
		y0 = -x0 * aatan;
	}
	if (ra == 0 || ra == PI)
	{
		rx = p->pos.x;
		ry = p->pos.y;
		dof = 14;
	}
	while (dof < 14)
	{
		mx = (int)(rx) >> 6;
		my = (int)(ry) >> 6;
		mp = my * 14 + mx;
		if (mp < 196 && mp > 0 && map[mp] == 1)
			break;
		else
		{
			rx += x0;
			ry += y0;
			dof++;
		}
	}
	vert->dist = sqrt((rx - p->pos.x) * (rx - p->pos.x) + (ry - p->pos.y) * (ry - p->pos.y));
	vert->p.x = rx;
	vert->p.y = ry;
}

t_hit			find_intersection_point(t_player *p, t_sdl *sdl)
{
	int		r;
	double	ra;
	t_hit	vert;
	t_hit	hori;
	int		line_h;
	int		line_o;
	double	dist;
	double 	ca;
	double	inc;

	r = 0;
	ra = p->pa - 30 * DR;
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	inc = 60 * DR / W;
	while (r < W)
	{
		vert_intersection(p, &vert, ra);
		hori_intersection(p, &hori, ra);
		if (vert.dist < hori.dist)
		{
			dist = vert.dist;
			SDL_RenderDrawLine(sdl->ren_ptr, p->pos.x, p->pos.y, vert.p.x, vert.p.y);
		}
		else
		{
			dist = hori.dist;
			SDL_RenderDrawLine(sdl->ren_ptr, p->pos.x, p->pos.y, hori.p.x, hori.p.y);
		}
		// 3d walls rendering
		ca = p->pa - ra;
		if (ca < 0)
			ca += 2 * PI;
		if (ca > 2 * PI)
			ca -= 2 * PI;
		line_h = (BLOCK_SIZE * H) / (dist * cos(ca));
		if (line_h >= H)
			line_h = H - 1;
		line_o = H / 2 - line_h / 2;
		SDL_RenderDrawLine(sdl->ren_ptr, r + W, line_o, r + W, line_o + line_h);
		ra += inc;
		r++;
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
	}
	return (vert);
}