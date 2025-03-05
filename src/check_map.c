/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:38:36 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/05 19:07:21 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/game.h"

/* Flood fill Method to see if map is closed */
/** Fill with '+' wherever is possible to go
*	- fill -> The map
*	- size -> The size of the map
*	- y -> The y position to start filling
*	- x -> The x position to start filling
*/
static void	ft_path(char **fill, t_lcn size, size_t y, size_t x)
{
	if (y >= size.y)
		return ;
	if (y >= size.y && x >= size.x)
	{
		if (fill[y][x])
			fill[y][x] = '+';
		return ;
	}
	if (x >= size.x || x >= ft_strlen(fill[y]))
		return ;
	if (fill[y][x] != FLOOR && fill[y][x] != ' ')
		return ;
	if (fill[y])
		if (fill[y][x])
			fill[y][x] = '+';
	ft_path(fill, size, y, x + 1);
	ft_path(fill, size, y, x - 1);
	ft_path(fill, size, y - 1, x);
	ft_path(fill, size, y + 1, x);
}

/* Search the first floor cell in map
*	* if not found return floor_cell (MAX, MAX)
*/
static t_lcn	search_first_floor_cell(t_map *m, t_lcn mapsize)
{
	t_lcn	flor_cell;

	flor_cell.y = 0;
	while (flor_cell.y < mapsize.y)
	{
		flor_cell.x = 0;
		while (flor_cell.x < ft_strlen(m->map[flor_cell.y]))
		{
			if (m->map[flor_cell.y][flor_cell.x] == FLOOR)
			{
				if (flor_cell.y == 0 || flor_cell.x == 0)
				{
					m = free_map(m);
					print_custom_err(MAP_NOTCLOSED);
				}
				return (flor_cell);
			}
			flor_cell.x++;
		}
		flor_cell.y++;
	}
	flor_cell.y = mapsize.y;
	flor_cell.x = mapsize.x;
	return (flor_cell);
}

/* Check if the map is closed
*	- if not closed print error
*	- if closed replace '+' with '0'
*/
static t_map	*check_closed_map(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map && map->map[i])
	{
		j = 0;
		while (map && map->map[i][j])
		{
			if (map && map->map[i][j] == '+')
			{
				if (i == 0 || j == 0)
					map = free_map(map);
				else if (i >= arrsize_str(map->map) - 1)
					map = free_map(map);
				else if (j >= ft_strlen(map->map[i]))
					map = free_map(map);
				else
					map->map[i][j] = FLOOR;
			}
			j++;
		}
		i++;
	}
	return (map);
}

/* Check this things:
*	- If the map have valid colors (0-255)
*	- If map have valid symbols (01NSWE)
*	- If the player is in the map
*	- If the map is closed
*/
void	check_valid_map(t_map *m)
{
	t_lcn	map;
	t_lcn	floor;

	map.x = m->width - 1;
	map.y = m->height - 1;
	check_colors(m);
	check_valid_symbol(m);
	check_player_inmap(m);
	while (42)
	{
		floor = search_first_floor_cell(m, map);
		if (floor.y == map.y || floor.x == map.x)
			break ;
		ft_path(m->map, map, floor.y, floor.x);
	}
	m = check_closed_map(m);
	if (!m)
		print_custom_err(MAP_NOTCLOSED);
}
