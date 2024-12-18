/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:10:25 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/18 20:03:46 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

t_game	*calulate_move_to(t_game *gm)
{
	gm->ply.ipx = gm->ply.px / gm->map->size;
	gm->ply.ipy = gm->ply.py / gm->map->size;
	gm->ply.ipx_add_xo = (gm->ply.px + gm->ray.xo) / gm->map->size;
	gm->ply.ipx_sub_xo = (gm->ply.px - gm->ray.xo) / gm->map->size;
	gm->ply.ipy_add_yo = (gm->ply.py + gm->ray.yo) / gm->map->size;
	gm->ply.ipy_sub_yo = (gm->ply.py - gm->ray.yo) / gm->map->size;
	return (gm);
}

static t_game	*can_move_vert(t_game *gm, char dir)
{
	gm->ply.can_move_horz = 0;
	gm->ply.can_move_vert = 0;
	if (dir == MOV_UP)
	{
		if (gm->map->map[gm->ply.ipy][gm->ply.ipx_add_xo] == '0')
			gm->ply.can_move_horz = 1;
		if (gm->map->map[gm->ply.ipy_add_yo][gm->ply.ipx] == '0')
			gm->ply.can_move_vert = 1;
	}
	if (dir == MOV_DOWN)
	{
		if (gm->map->map[gm->ply.ipy][gm->ply.ipx_sub_xo] == '0')
			gm->ply.can_move_horz = 1;
		if (gm->map->map[gm->ply.ipy_sub_yo][gm->ply.ipx] == '0')
			gm->ply.can_move_vert = 1;
	}
	return (gm);
}

t_game	*can_move_to(t_game *gm, char dir)
{
	gm = calulate_move_to(gm);
	gm->ply.can_move = 0;
	if (dir == MOV_LEFT)
		if (gm->map->map[gm->ply.ipy_sub_yo][gm->ply.ipx_sub_xo] == '0')
			gm->ply.can_move = 1;
	if (dir == MOV_RIGHT)
		if (gm->map->map[gm->ply.ipy_add_yo][gm->ply.ipx_add_xo] == '0')
			gm->ply.can_move = 1;
	if (dir == MOV_UP || dir == MOV_DOWN)
		return (can_move_vert(gm, dir));
	return (gm);
}
