/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_minimap_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:37:56 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/10 20:40:51 by andmart2         ###   ########.fr       */
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


/*static void	paint_player(t_game *gm)
{
	t_rect	m;
	size_t	x;
	size_t	y;

	m.height = MINMAP_CH;
	m.width = MINMAP_CW;
	x = (MINIMAP_VIEW_WIDTH / 2) * MINMAP_CW;
	y = (MINIMAP_VIEW_HEIGHT / 2) * MINMAP_CH;
	m.fill = ft_pixel(255, 20, 20, 156);
	printrect(gm->mlxd->wimg, x, y, m);
	
	x += cos(gm->ply.pa) * MINMAP_CW;
	y += sin(gm->ply.pa) * MINMAP_CH;
	m.fill = ft_pixel(255, 200, 20, 156);
	printrect(gm->mlxd->wimg, x, y, m);
}*/

/*void	printmap(t_game *gm)
{
	int start_x, start_y, end_x, end_y; // Cambiar a int
	size_t x, y;
	t_rect m;

	// Calcular el rango visible basado en la posición del jugador
	start_x = gm->ply.ipx - MINIMAP_VIEW_WIDTH / 2;
	start_y = gm->ply.ipy - MINIMAP_VIEW_HEIGHT / 2;
	end_x = gm->ply.ipx + MINIMAP_VIEW_WIDTH / 2;
	end_y = gm->ply.ipy + MINIMAP_VIEW_HEIGHT / 2;

	// Asegurarse de no salir de los límites del mapa
	if (start_x < 0) start_x = 0;
	if (start_y < 0) start_y = 0;
	if ((size_t)end_x > gm->map->width) end_x = gm->map->width;
	if ((size_t)end_y > gm->map->height) end_y = gm->map->height;

	m.height = MINMAP_CH;
	m.width = MINMAP_CW;

	// Dibujar solo las celdas visibles
	y = start_y;
	while (y < (size_t)end_y)
	{
		x = start_x;
		while (x < (size_t)end_x)
		{
			if (gm->map->map[y][x] == '0')
			{
				m.fill = ft_pixel(20, 20, 20, 50);
				printrect(gm->mlxd->wimg, (x - start_x) * m.width, (y - start_y) * m.height, m);
			}
			if (gm->map->map[y][x] == '1')
			{
				m.fill = ft_pixel(200, 200, 200, 50);
				printrect(gm->mlxd->wimg, (x - start_x) * m.width, (y - start_y) * m.height, m);
			}
			x++;
		}
		y++;
	}

	// Dibujar al jugador
	paint_player(gm);
}
*/


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
