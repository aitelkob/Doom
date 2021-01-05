/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:36:42 by ayagoumi          #+#    #+#             */
/*   Updated: 2021/01/05 18:05:10 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/door.h"

extern int map[];

void			hori_intersection_door(t_player *p, t_hit *hori, double ra)
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
		if (mp < 196 && mp > 0 && map[mp] == 5)
        {
            rx += x0/2;
			ry += y0/2;
			break;
        }
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

void		vert_intersection_door(t_player *p, t_hit *vert, double ra)
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
		if (mp < 196 && mp > 0 && map[mp] == 5)
        {
			rx += x0/2;
			ry += y0/2;
			break;
		}
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