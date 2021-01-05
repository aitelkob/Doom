/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:36:48 by ayagoumi          #+#    #+#             */
/*   Updated: 2021/01/05 18:02:44 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOR_H
#define DOOR_H
#include "headers.h"
void		vert_intersection_door(t_player *p, t_hit *vert, double ra);
void			hori_intersection_door(t_player *p, t_hit *hori, double ra);

#endif