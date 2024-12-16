/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_minimap_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:37:56 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/16 17:56:36 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	printmap(t_game *gm)
{
	size_t	y;
	size_t	x;
	t_rect	m;

	y = -1;
	m.height = 25;
	m.width = 25;
	while (++y < gm->map->height)
	{
		x = -1;
		while (++x < gm->map->width)
		{
			if (gm->map->map[y][x] == '0')
			{
				m.fill = ft_pixel((int32_t)20, (int32_t)20, (int32_t)20, (int32_t)255);
				printrect(gm->mlxd->wimg, x * m.width, y * m.height, m);
			}
			if (gm->map->map[y][x] == '1')
			{
				m.fill = ft_pixel((int32_t)200, (int32_t)200, (int32_t)200, (int32_t)255);
				printrect(gm->mlxd->wimg, x * m.width, y * m.height, m);
			}
			if (gm->map->map[y][x] == 'P')
			{
				m.fill = ft_pixel((int32_t)255, (int32_t)20, (int32_t)20, (int32_t)255);
				printrect(gm->mlxd->wimg, x * m.width, y * m.height, m);
			}
		}
	}
}
