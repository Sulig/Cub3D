/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_minimap_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:37:56 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/18 18:56:31 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

static void	paint_player(t_game *gm)
{
	t_rect	m;
	size_t	x;
	size_t	y;

	m.height = MINMAP_CH;
	m.width = MINMAP_CW;
	x = gm->ply.ipx * MINMAP_CW;
	y = gm->ply.ipy * MINMAP_CH;
	m.fill = ft_pixel((int32_t)255, (int32_t)20, (int32_t)20, (int32_t)156);
	printrect(gm->mlxd->wimg, x, y, m);
	x = (gm->ply.ipx + cos(gm->ply.pa)) * MINMAP_CW;
	y = (gm->ply.ipy + sin(gm->ply.pa)) * MINMAP_CH;
	m.fill = ft_pixel((int32_t)255, (int32_t)200, (int32_t)20, (int32_t)156);
	printrect(gm->mlxd->wimg, x, y, m);
}

void	printmap(t_game *gm)
{
	size_t	y;
	size_t	x;
	t_rect	m;

	y = -1;
	m.height = MINMAP_CH;
	m.width = MINMAP_CW;
	while (++y < gm->map->height)
	{
		x = -1;
		while (++x < gm->map->width)
		{
			if (gm->map->map[y][x] == '0')
			{
				m.fill = ft_pixel((int32_t)20, (int32_t)20, (int32_t)20, (int32_t)50);
				printrect(gm->mlxd->wimg, x * m.width, y * m.height, m);
			}
			if (gm->map->map[y][x] == '1')
			{
				m.fill = ft_pixel((int32_t)200, (int32_t)200, (int32_t)200, (int32_t)50);
				printrect(gm->mlxd->wimg, x * m.width, y * m.height, m);
			}
		}
	}
	paint_player(gm);
}
