/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_minimap_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:37:56 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/14 20:37:46 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc_bonus/game_bonus.h"

t_view_area	calculate_view_area(t_game *gm, int ply_ipx, int ply_ipy)
{
	t_view_area	area;

	if (ply_ipx - VIEW_RADIUS >= 0)
		area.start.x = ply_ipx - VIEW_RADIUS;
	else
		area.start.x = 0;
	if (ply_ipy - VIEW_RADIUS >= 0)
		area.start.y = ply_ipy - VIEW_RADIUS;
	else
		area.start.y = 0;
	if (ply_ipx + VIEW_RADIUS < (int)gm->map->width)
		area.end.x = ply_ipx + VIEW_RADIUS;
	else
		area.end.x = (int)gm->map->width - 1;
	if (ply_ipy + VIEW_RADIUS < (int)gm->map->height)
		area.end.y = ply_ipy + VIEW_RADIUS;
	else
		area.end.y = (int)gm->map->height - 1;
	return (area);
}

void	paint_player(t_game *gm, t_point start)
{
	t_rect	m;
	int		x;
	int		y;

	m.height = MINMAP_CELL_H;
	m.width = MINMAP_CELL_W;
	x = (gm->ply.ipx - start.x) * m.width + MAP_WINDOW_X;
	y = (gm->ply.ipy - start.y) * m.height + MAP_WINDOW_Y;
	m.fill = ft_pixel(255, 20, 20, 156);
	printrect(gm->mlxd->wimg, x, y, m);
	x = (gm->ply.ipx + cos(gm->ply.pa) - start.x) * m.width + MAP_WINDOW_X;
	y = (gm->ply.ipy + sin(gm->ply.pa) - start.y) * m.height + MAP_WINDOW_Y;
	m.fill = ft_pixel(255, 200, 20, 156);
	printrect(gm->mlxd->wimg, x, y, m);
}

#include <stdbool.h>

// Función para verificar si una coordenada está dentro de los límites de una fila
static bool	is_within_row_bounds(t_game *gm, size_t y, size_t x)
{
	// Asegúrate de que 'y' esté dentro de los límites del mapa
	if (y >= gm->map->height)
		return (false);
	// Verifica que 'x' esté dentro de los límites de la fila 'y'
	// Asumimos que el mapa está representado como un array de cadenas y cada fila tiene longitud variable
	return (x < ft_strlen(gm->map->map[y]));
		// Verifica que 'x' esté dentro de los límites de la fila
}

void	draw_map_area(t_game *gm, t_view_area area)
{
	t_draw_params	params;

	size_t x, y;
	// Asegúrate de inicializar params.rect correctamente
	params.rect.height = MINMAP_CELL_H;
	params.rect.width = MINMAP_CELL_W;
	y = area.start.y;
	while (y <= area.end.y)
	{
		x = area.start.x;
		while (x <= area.end.x)
		{
			// Verifica que las coordenadas estén dentro de los límites del mapa y de la fila
			if (is_within_row_bounds(gm, y, x))
			{
				params.map_x = (x - area.start.x) * params.rect.width
					+ MAP_WINDOW_X;
				params.map_y = (y - area.start.y) * params.rect.height
					+ MAP_WINDOW_Y;
				// Accede al mapa de forma segura
				if (gm->map->map[y][x] == '0')
					params.rect.fill = ft_pixel(20, 20, 20, 50);
				else if (gm->map->map[y][x] == '1')
					params.rect.fill = ft_pixel(200, 200, 200, 50);
				printrect(gm->mlxd->wimg, params.map_x, params.map_y,
					params.rect);
			}
			x++;
		}
		y++;
	}
}

/*void	draw_map_area(t_game *gm, t_view_area area)
{
	t_draw_params	params;
	size_t			x;
	size_t			y;
	int				ply_ipx;
	int				ply_ipy;
	t_view_area		area;

	params.rect.height = MINMAP_CELL_H;
	params.rect.width = MINMAP_CELL_W;
	y = area.start.y;
	while (y <= area.end.y)
	{
		x = area.start.x;
		while (x <= area.end.x)
		{
			params.map_x = (x - area.start.x) * params.rect.width
				+ MAP_WINDOW_X;
			params.map_y = (y - area.start.y) * params.rect.height
				+ MAP_WINDOW_Y;
			if (gm->map->map[y][x] == '0')
				params.rect.fill = ft_pixel(20, 20, 20, 50);
			else if (gm->map->map[y][x] == '1')
				params.rect.fill = ft_pixel(200, 200, 200, 50);
			printrect(gm->mlxd->wimg, params.map_x, params.map_y, params.rect);
			x++;
		}
		y++;
	}
}*/
void	printmap(t_game *gm)
{
    int         ply_ipx;  // Declarar ply_ipx
    int         ply_ipy;  // Declarar ply_ipy
    t_view_area area;     // Declarar area

    ply_ipx = (int)(gm->ply.ipx);
    ply_ipy = (int)(gm->ply.ipy);
    area = calculate_view_area(gm, ply_ipx, ply_ipy);
    draw_map_area(gm, area);
    paint_player(gm, area.start);
}
