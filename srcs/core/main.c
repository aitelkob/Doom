/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 05:19:40 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/05 08:56:17 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int map[]=
{
  1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  1,0,0,0,0,0,0,0,0,0,0,0,0,1,
  1,0,0,0,0,1,0,0,0,0,0,0,0,1,
  1,0,0,0,0,0,0,0,0,0,1,0,0,1,
  1,0,0,1,0,0,0,0,0,0,1,0,0,1,
  1,0,0,0,0,1,0,0,0,0,1,0,0,1,
  1,0,0,0,0,0,0,0,0,0,1,0,0,1,
  1,0,0,0,0,1,0,0,0,0,1,0,0,1,
  1,0,0,0,0,5,0,0,0,0,0,0,0,1,
  1,0,0,0,0,1,0,0,0,0,0,0,0,1,
  1,0,0,0,0,1,0,0,0,0,0,0,0,1,
  1,0,0,0,0,1,0,0,0,1,0,0,0,1,
  1,0,0,0,0,0,0,0,0,0,0,0,0,1,
  1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

void	setup_texture(t_tex *tex)
{
	tex->texture = NULL;
	tex->texture = SDL_LoadBMP("../resources/tex.bmp");
	if (tex->texture == NULL)
	{
		 SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "HH HH MAERFT%s", SDL_GetError());
		 exit(0);
	}
}

int		main(int ac, char **av)
{
	t_doom *d;

	if (ac && av[0])
	{
		d = malloc(sizeof(t_doom));
		setup(d);
		setup_texture(&d->tex);
		while (d->upt.input.game)
		{
			process_input(&d->upt);
			update(d);
			render(d);
			init_keys(d);
		}
	}
	return (0);
}
