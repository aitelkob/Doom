/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 16:08:27 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/06 08:28:48 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void		load_texture(t_doom *d)
{
	if (!(d->sdl.Wall = IMG_Load(WALL)))
	{
		printf("IMG_Load Wall: %s\n", IMG_GetError());
		exit(0);
	}
	if (!(d->sdl.Sky = IMG_Load(SKY)))
	{
		printf("IMG_Load SKY: %s\n", IMG_GetError());
		exit(0);
	}
	if (!(d->sdl.Floor = IMG_Load(FLOOR)))
	{
		printf("IMG_Load Floor: %s\n", IMG_GetError());
		exit(0);
	}
	d->sdl.Wall_pixels = (unsigned int *)d->sdl.Wall->pixels;
	d->sdl.Sky_pixels = (unsigned int *)d->sdl.Sky->pixels;
	d->sdl.Floor_pixels = (unsigned int *)d->sdl.Floor->pixels;
}
