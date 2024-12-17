/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:05:22 by andmart2          #+#    #+#             */
/*   Updated: 2024/12/17 20:20:52 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

/* Rotate the perspective view */
void	rotate(t_game *gm, char direction)
{
	if (direction == ROT_LEFT)
	{
		gm->ply.pa -= ANGLE_D;
		if (gm->ply.pa < 0)
			gm->ply.pa += 2 * PI;
		gm->ply.pdx = cos(gm->ply.pa) * VEL;
		gm->ply.pdy = sin(gm->ply.pa) * VEL;
	}
	if (direction == ROT_RIGHT)
	{
		gm->ply.pa += ANGLE_D;
		if (gm->ply.pa > 2 * PI)
			gm->ply.pa -= 2 * PI;
		gm->ply.pdx = cos(gm->ply.pa) * VEL;
		gm->ply.pdy = sin(gm->ply.pa) * VEL;
	}
}

/* Translate / Move the player */
void	translate(t_game *gm, char dir)
{
	if (dir == MOV_LEFT)
	{
		gm->ply.px += -1 * VEL * cos(gm->ply.pa + P2);
		gm->ply.py += -1 * VEL * sin(gm->ply.pa + P2);
	}
	if (dir == MOV_RIGHT)
	{
		gm->ply.px += 1 * VEL * cos(gm->ply.pa + P2);
		gm->ply.py += 1 * VEL * sin(gm->ply.pa + P2);
	}
	if (dir == MOV_UP)
	{
		gm->ply.px += gm->ply.pdx;
		gm->ply.py += gm->ply.pdy;
	}
	if (dir == MOV_DOWN)
	{
		gm->ply.px -= gm->ply.pdx;
		gm->ply.py -= gm->ply.pdy;
	}
	gm->ply.plx_inmap = gm->ply.px / gm->map->size;
	gm->ply.ply_inmap = gm->ply.py / gm->map->size;
}
