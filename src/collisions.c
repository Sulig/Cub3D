/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:10:25 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/08 18:03:52 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

static char	fill_rackmap(t_map *map, long y, long x)
{
	if (y <= 0 || y >= (long)map->height)
		return ('1');
	if (x <= 0 || x >= (long)map->width)
		return ('1');
	return (map->map[y][x]);
}

/* Actualize rack rackmap (take care of no tresspasing of map) */
static t_game	*actualize_rackmap(t_game *gm)
{
	long	add_x;
	long	sub_x;
	long	add_y;
	long	sub_y;

	add_x = gm->ply.ipx_add_xo;
	sub_x = gm->ply.ipx_sub_xo;
	add_y = gm->ply.ipy_add_yo;
	sub_y = gm->ply.ipy_sub_yo;
	gm->ply.rackmap[0][0] = fill_rackmap(gm->map, add_y, sub_x);
	gm->ply.rackmap[0][1] = fill_rackmap(gm->map, add_y, gm->ply.ipx);
	gm->ply.rackmap[0][2] = fill_rackmap(gm->map, add_y, add_x);
	gm->ply.rackmap[1][0] = fill_rackmap(gm->map, gm->ply.ipy, add_x);
	gm->ply.rackmap[1][1] = 'X';
	gm->ply.rackmap[1][2] = fill_rackmap(gm->map, gm->ply.ipx, sub_x);
	gm->ply.rackmap[2][0] = fill_rackmap(gm->map, sub_y, add_x);
	gm->ply.rackmap[2][1] = fill_rackmap(gm->map, sub_y, gm->ply.ipx);
	gm->ply.rackmap[2][2] = fill_rackmap(gm->map, sub_y, sub_x);
	return (gm);
}

t_game	*calulate_move_to(t_game *gm)
{
	int	xo;
	int	yo;

	if (gm->ply.pdx < 0)
		xo = -COLL_SIZE;
	else
		xo = COLL_SIZE;
	if (gm->ply.pdy < 0)
		yo = -COLL_SIZE;
	else
		yo = COLL_SIZE;
	gm->ply.can_move = 0;
	gm->ply.can_move_horz = 0;
	gm->ply.can_move_vert = 0;
	gm->ply.ipx = gm->ply.px / CUB_SCALE;
	gm->ply.ipy = gm->ply.py / CUB_SCALE;
	if (gm->ply.ipx < 0 || gm->ply.ipy < 0)
		print_other_err(PLY_TRSNMAP);
	gm->ply.ipx_add_xo = (gm->ply.px + xo) / CUB_SCALE;
	gm->ply.ipx_sub_xo = (gm->ply.px - xo) / CUB_SCALE;
	gm->ply.ipy_add_yo = (gm->ply.py + yo) / CUB_SCALE;
	gm->ply.ipy_sub_yo = (gm->ply.py - yo) / CUB_SCALE;
	gm = actualize_rackmap(gm);
	return (gm);
}

static t_game	*can_move_vert(t_game *gm, char dir)
{
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
