/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_minimap_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:29:56 by andmart2          #+#    #+#             */
/*   Updated: 2025/01/13 20:18:03 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"
#define MAP_WINDOW_WIDTH 200  // Ancho de la ventana del mapa
#define MAP_WINDOW_HEIGHT 200 // Altura de la ventana del mapa
#define MAP_WINDOW_X 50       // Coordenada X de inicio de la ventana del mapa
#define MAP_WINDOW_Y 50       // Coordenada Y de inicio de la ventana del mapa
#define VIEW_RADIUS 5         // Radio en celdas alrededor del jugador


/*typedef struct s_point {
    int x;
    int y;
} t_point;

typedef struct s_view_area {
    t_point start;
    t_point end;
} t_view_area;

typedef struct s_draw_params {
    t_rect rect;
    int map_x;
    int map_y;
} t_draw_params;

t_view_area	calculate_view_area(t_game *gm, int ply_ipx, int ply_ipy)
{
    t_view_area area;

    area.start.x = (ply_ipx - VIEW_RADIUS >= 0) ? ply_ipx - VIEW_RADIUS : 0;
    area.end.x = (ply_ipx + VIEW_RADIUS < (int)gm->map->width)
                 ? ply_ipx + VIEW_RADIUS : (int)gm->map->width - 1;
    area.start.y = (ply_ipy - VIEW_RADIUS >= 0) ? ply_ipy - VIEW_RADIUS : 0;
    area.end.y = (ply_ipy + VIEW_RADIUS < (int)gm->map->height)
                 ? ply_ipy + VIEW_RADIUS : (int)gm->map->height - 1;

    return area;
}

void	paint_player(t_game *gm, t_point start)
{
    t_rect	m;
    int		x;
    int		y;

    m.height = MINMAP_CH;
    m.width = MINMAP_CW;

    // Posición del jugador
    x = (gm->ply.ipx - start.x) * m.width + MAP_WINDOW_X;
    y = (gm->ply.ipy - start.y) * m.height + MAP_WINDOW_Y;
    m.fill = ft_pixel(255, 20, 20, 156);
    printrect(gm->mlxd->wimg, x, y, m);

    // Dirección del jugador
    x = (gm->ply.ipx + cos(gm->ply.pa) - start.x) * m.width + MAP_WINDOW_X;
    y = (gm->ply.ipy + sin(gm->ply.pa) - start.y) * m.height + MAP_WINDOW_Y;
    m.fill = ft_pixel(255, 200, 20, 156);
    printrect(gm->mlxd->wimg, x, y, m);
}

void	draw_map_area(t_game *gm, t_view_area area)
{
    t_draw_params	params;
    size_t			x;
    size_t			y;

    params.rect.height = MINMAP_CH;
    params.rect.width = MINMAP_CW;

    y = (size_t)area.start.y;
    while ((int)y <= area.end.y)
    {
        x = (size_t)area.start.x;
        while ((int)x <= area.end.x)
        {
            params.map_x = (x - area.start.x) * params.rect.width + MAP_WINDOW_X;
            params.map_y = (y - area.start.y) * params.rect.height + MAP_WINDOW_Y;

            if (gm->map->map[y][x] == '0')
                params.rect.fill = ft_pixel(20, 20, 20, 50);
            else if (gm->map->map[y][x] == '1')
                params.rect.fill = ft_pixel(200, 200, 200, 50);

            printrect(gm->mlxd->wimg, params.map_x, params.map_y, params.rect);
            x++;
        }
        y++;
    }
}

void	printmap(t_game *gm)
{
    int			ply_ipx;
    int			ply_ipy;
    t_view_area	area;

    ply_ipx = (int)(gm->ply.ipx);
    ply_ipy = (int)(gm->ply.ipy);

    // Calcular área visible
    area = calculate_view_area(gm, ply_ipx, ply_ipy);

    // Dibujar el área del mapa
    draw_map_area(gm, area);

    // Dibujar el jugador
    paint_player(gm, area.start);
}*/

void	paint_player(t_game *gm, int start_x, int start_y)
{
	t_rect	m;
	int		x;
	int		y;

	m.height = MINMAP_CH;
	m.width = MINMAP_CW;
	x = (gm->ply.ipx - start_x) * m.width + MAP_WINDOW_X;
	y = (gm->ply.ipy - start_y) * m.height + MAP_WINDOW_Y;
	m.fill = ft_pixel(255, 20, 20, 156);
	printrect(gm->mlxd->wimg, x, y, m);
	x = (gm->ply.ipx + cos(gm->ply.pa) - start_x) * m.width + MAP_WINDOW_X;
	y = (gm->ply.ipy + sin(gm->ply.pa) - start_y) * m.height + MAP_WINDOW_Y;
	m.fill = ft_pixel(255, 200, 20, 156);
	printrect(gm->mlxd->wimg, x, y, m);
}

void	calculate_view_area(t_game *gm, int ply_ipx, int ply_ipy, int *start_x,
		int *end_x, int *start_y, int *end_y)
{
	if (ply_ipx - VIEW_RADIUS >= 0)
		*start_x = ply_ipx - VIEW_RADIUS;
	else
		*start_x = 0;
	if (ply_ipx + VIEW_RADIUS < (int)gm->map->width)
		*end_x = ply_ipx + VIEW_RADIUS;
	else
		*end_x = (int)gm->map->width - 1;
	if (ply_ipy - VIEW_RADIUS >= 0)
		*start_y = ply_ipy - VIEW_RADIUS;
	else
		*start_y = 0;
	if (ply_ipy + VIEW_RADIUS < (int)gm->map->height)
		*end_y = ply_ipy + VIEW_RADIUS;
	else
		*end_y = (int)gm->map->height - 1;
}

void	draw_map_area(t_game *gm, int start_x, int end_x, int start_y,
		int end_y)
{
	size_t	x;
	int		map_x;
	int		map_y;
	t_rect	m;
	size_t	y;

	m.height = MINMAP_CH;
	m.width = MINMAP_CW;
	y = (size_t)start_y;
	while ((int)y <= end_y)
	{
		x = (size_t)start_x;
		while ((int)x <= end_x)
		{
			map_x = (x - start_x) * m.width + MAP_WINDOW_X;
			map_y = (y - start_y) * m.height + MAP_WINDOW_Y;
			if (gm->map->map[y][x] == '0')
			{
				m.fill = ft_pixel(20, 20, 20, 50);
				printrect(gm->mlxd->wimg, map_x, map_y, m);
			}
			else if (gm->map->map[y][x] == '1')
			{
				m.fill = ft_pixel(200, 200, 200, 50);
				printrect(gm->mlxd->wimg, map_x, map_y, m);
			}
			x++;
		}
		y++;
	}
}

void	printmap(t_game *gm)
{
	int	ply_ipx;
	int	start_x;
	int	start_y;
	int	ply_ipy;
	int	end_x;
	int	end_y;

	ply_ipx = (int)(gm->ply.ipx);
	ply_ipy = (int)(gm->ply.ipy);
	calculate_view_area(gm, ply_ipx, ply_ipy, &start_x, &end_x, &start_y,
		&end_y);
	draw_map_area(gm, start_x, end_x, start_y, end_y);
	paint_player(gm, start_x, start_y);
}
