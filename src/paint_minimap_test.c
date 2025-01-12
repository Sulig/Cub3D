/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_minimap_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:37:56 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/12 13:54:45 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"
#define MAP_WINDOW_WIDTH 200  // Ancho de la ventana del mapa
#define MAP_WINDOW_HEIGHT 200 // Altura de la ventana del mapa
#define MAP_WINDOW_X 50       // Coordenada X de inicio de la ventana del mapa
#define MAP_WINDOW_Y 50       // Coordenada Y de inicio de la ventana del mapa
#define VIEW_RADIUS 5         // Radio en celdas alrededor del jugador

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

/*void	printmap(t_game *gm)
{
	t_rect	m;
	size_t	x;
	size_t	y;
	int		ply_ipx;
	int		ply_ipy;
	int		start_x;
	int		end_x;
	int		start_y;
	int		end_y;
	int		map_x;
	int		map_y;
	t_rect	m;
	size_t	x;
	size_t	y;

	m.height = MINMAP_CH;
	m.width = MINMAP_CW;
	ply_ipx = (int)(gm->ply.ipx);
	ply_ipy = (int)(gm->ply.ipy);
	start_x = (ply_ipx - VIEW_RADIUS >= 0) ? ply_ipx - VIEW_RADIUS : 0;
	end_x = (ply_ipx + VIEW_RADIUS < (int)gm->map->width) ? ply_ipx
		+ VIEW_RADIUS : (int)gm->map->width - 1;
	start_y = (ply_ipy - VIEW_RADIUS >= 0) ? ply_ipy - VIEW_RADIUS : 0;
	end_y = (ply_ipy + VIEW_RADIUS < (int)gm->map->height) ? ply_ipy
		+ VIEW_RADIUS : (int)gm->map->height - 1;
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
	paint_player(gm, start_x, start_y);
}*/
/*void	paint_player(t_game *gm)
{
	m.height = MINMAP_CH;
	m.width = MINMAP_CW;
	// Coordenadas del jugador dentro del mapa
	x = gm->ply.ipx * MINMAP_CW + MAP_WINDOW_X;
	y = gm->ply.ipy * MINMAP_CH + MAP_WINDOW_Y;
	m.fill = ft_pixel((int32_t)255, (int32_t)20, (int32_t)20, (int32_t)156);
	printrect(gm->mlxd->wimg, x, y, m);
	// Coordenadas del jugador con la dirección
	x = (gm->ply.ipx + cos(gm->ply.pa)) * MINMAP_CW + MAP_WINDOW_X;
	y = (gm->ply.ipy + sin(gm->ply.pa)) * MINMAP_CH + MAP_WINDOW_Y;
	m.fill = ft_pixel((int32_t)255, (int32_t)200, (int32_t)20, (int32_t)156);
	printrect(gm->mlxd->wimg, x, y, m);
}

void	printmap(t_game *gm)
{
	t_rect	m;
	size_t	x;
	size_t	y;
	size_t	ply_ipx;
	size_t	ply_ipy;
	size_t	view_radius;
	size_t	start_x;
	size_t	end_x;
	size_t	start_y;
	size_t	end_y;
	int		map_x;
	int		map_y;
	t_rect	m;
	size_t	x;
	size_t	y;

	m.height = MINMAP_CH;
	m.width = MINMAP_CW;
	// Aseguramos que las variables sean del mismo tipo y manejamos VIEW_RADIUS como size_t
	ply_ipx = (size_t)gm->ply.ipx;
	ply_ipy = (size_t)gm->ply.ipy;
	view_radius = (size_t)VIEW_RADIUS;
	// Calcula los límites del área visible manejando el tipo size_t
	start_x = (ply_ipx > view_radius) ? ply_ipx - view_radius : 0;
	end_x = (ply_ipx + view_radius < gm->map->width) ? ply_ipx
		+ view_radius : gm->map->width - 1;
	start_y = (ply_ipy > view_radius) ? ply_ipy - view_radius : 0;
	end_y = (ply_ipy + view_radius < gm->map->height) ? ply_ipy
		+ view_radius : gm->map->height - 1;
	y = start_y;
	while (y <= end_y)
	{
		x = start_x;
		while (x <= end_x)
		{
			map_x = x * m.width + MAP_WINDOW_X;
			map_y = y * m.height + MAP_WINDOW_Y;
			// Verifica si la celda está dentro de la ventana
			if (map_x + m.width <= MAP_WINDOW_X + MAP_WINDOW_WIDTH &&
				map_y + m.height <= MAP_WINDOW_Y + MAP_WINDOW_HEIGHT)
			{
				if (gm->map->map[y][x] == '0')
				{
					m.fill = ft_pixel((int32_t)20, (int32_t)20, (int32_t)20,
							(int32_t)50);
					printrect(gm->mlxd->wimg, map_x, map_y, m);
				}
				else if (gm->map->map[y][x] == '1')
				{
					m.fill = ft_pixel((int32_t)200, (int32_t)200, (int32_t)200,
							(int32_t)50);
					printrect(gm->mlxd->wimg, map_x, map_y, m);
				}
			}
			x++;
		}
		y++;
	}
	paint_player(gm);
}*/
/*static void	paint_player(t_game *gm)
{
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
				m.fill = ft_pixel((int32_t)20, (int32_t)20, (int32_t)20,
						(int32_t)50);
				printrect(gm->mlxd->wimg, x * m.width, y * m.height, m);
			}
			if (gm->map->map[y][x] == '1')
			{
				m.fill = ft_pixel((int32_t)200, (int32_t)200, (int32_t)200,
						(int32_t)50);
				printrect(gm->mlxd->wimg, x * m.width, y * m.height, m);
			}
		}
	}
	paint_player(gm);
}*/
