/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 08:07:46 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/30 09:45:35 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

extern int map[];

void			hori_intersection(t_player *p, t_hit *hori)
{
	int r, mx, my, mp, dof;
	float rx, ry, ra, x0, y0;
	float aatan;

	ra = p->pa;
	r = 0;
	while (r < 1)
	{
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
		r++;
	}
	if (mp < 0)
		hori->dist = 10000;
	else
		hori->dist = mp;
	hori->p.x = rx;
	hori->p.y = ry;
}

void		vert_intersection(t_player *p, t_hit *vert)
{
	int r, mx, my, mp, dof;
	float rx, ry, ra, x0, y0;
	float aatan;

	ra = p->pa;
	r = 0;
	while (r < 1)
	{
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
		r++;
	}
	if (mp < 0)
		vert->dist = 10000;
	else
		vert->dist = mp;
	vert->p.x = rx;
	vert->p.y = ry;
}

t_hit			find_intersection_point(t_player *p)
{
	t_hit vert;
	t_hit hori;

	hori.dist = 100000;
	vert.dist = 100000;
	hori_intersection(p, &hori);
	vert_intersection(p, &vert);
	// printf("hori ==== {%lf}       vert ==== {%lf}\n",hori.dist, vert.dist);
	if (hori.dist > vert.dist)
		return (vert);
	return (hori);
}