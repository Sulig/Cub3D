/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:10:25 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/09 12:58:21 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

static char	get_cell(t_map *map, long x, long y)
{
	x /= CUB_SCALE;
	y /= CUB_SCALE;
	if (y <= 0 || y >= (long)map->height)
		return ('1');
	if (x <= 0 || x >= (long)map->width)
		return ('1');
	return (map->map[y][x]);
}

/* Manage collisions with a 'rackmap' tool */
int	can_move_to(t_game *gm)
{
	char next_horz;
	char next_vert;
	char next_diag;

	next_horz = get_cell(gm->map, gm->ply.new_px, gm->ply.py);
	next_vert = get_cell(gm->map, gm->ply.px, gm->ply.new_py);
	next_diag = get_cell(gm->map, gm->ply.new_px, gm->ply.new_py);
	if (next_diag == '1')
		return (0);
	if (next_horz == '1' && next_vert == '1')
		return (0);
	return (1);
}
