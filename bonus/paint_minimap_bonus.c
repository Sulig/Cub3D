/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_minimap_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:37:56 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/15 20:37:35 by sadoming         ###   ########.fr       */
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

t_draw_params	prepare_drawing_params(size_t x, size_t y, t_view_area area,
		t_game *gm)
{
	t_draw_params	params;

	params.rect.height = MINMAP_CELL_H;
	params.rect.width = MINMAP_CELL_W;
	params.map_x = (x - area.start.x) * params.rect.width + MAP_WINDOW_X;
	params.map_y = (y - area.start.y) * params.rect.height + MAP_WINDOW_Y;
	if (gm->map->map[y][x] == '0')
	{
		params.rect.fill = ft_pixel(20, 20, 20, 50);
	}
	else
	{
		params.rect.fill = ft_pixel(200, 200, 200, 50);
	}
	return (params);
}

void	draw_map_area(t_game *gm, t_view_area area)
{
	size_t			x;
	size_t			y;
	t_draw_params	params;

	y = area.start.y;
	while (y <= area.end.y)
	{
		x = area.start.x;
		while (x <= area.end.x)
		{
			if (y < gm->map->height && x < ft_strlen(gm->map->map[y]))
			{
				params = prepare_drawing_params(x, y, area, gm);
				printrect(gm->mlxd->wimg, params.map_x, params.map_y,
					params.rect);
			}
			x++;
		}
		y++;
	}
}

void	printmap(t_game *gm)
{
	t_view_area	area;
	int			ply_ipx;
	int			ply_ipy;

	ply_ipx = (int)(gm->ply.ipx);
	ply_ipy = (int)(gm->ply.ipy);
	area = calculate_view_area(gm, ply_ipx, ply_ipy);
	draw_map_area(gm, area);
	paint_player(gm, area.start);
}
