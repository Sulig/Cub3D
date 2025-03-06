/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:12:11 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/05 18:47:28 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/game.h"

/* Verifies the format of file and check if exist */
int	check_format(char *file)
{
	char	*format;

	format = ft_strstr(file, ".cub");
	if (!format)
		print_err_arfor(1);
	format = NULL;
	if (open(file, O_RDONLY) == -1)
		print_err_arfor(2);
	return (1);
}

/* Checks if map->file have dupplicated info or missing info */
int	check_dupmiss(t_map *map)
{
	size_t	checker[6];
	size_t	cnt;

	cnt = -1;
	checker[0] = ft_strinarr_cnd(map->file, "NO");
	checker[1] = ft_strinarr_cnd(map->file, "SO");
	checker[2] = ft_strinarr_cnd(map->file, "WE");
	checker[3] = ft_strinarr_cnd(map->file, "EA");
	checker[4] = ft_strinarr_cnd(map->file, "F");
	checker[5] = ft_strinarr_cnd(map->file, "C");
	while (++cnt < 6)
	{
		if (!checker[cnt])
		{
			map = free_map(map);
			print_err_dupmiss(0);
		}
		else if (checker[cnt] > 1)
		{
			map = free_map(map);
			print_err_dupmiss(1);
		}
	}
	return (1);
}

/* Check if the color is in correct range of [0 - 255] */
int	check_colors(t_map *map)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (map->c_rgb[i] < 0 || map->c_rgb[i] > 255)
		{
			map = free_map(map);
			print_custom_err(BAD_CCOLOR);
		}
		if (map->f_rgb[i] < 0 || map->f_rgb[i] > 255)
		{
			map = free_map(map);
			print_custom_err(BAD_FCOLOR);
		}
		i++;
	}
	return (1);
}

/* Check if the map contains only a valid symbols */
int	check_valid_symbol(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!ft_strchr(MAP_CHARS, map->map[i][j]))
			{
				map = free_map(map);
				print_custom_err(INVALID_MAP);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/* Check if player is not in the corners of map */
int	check_player_inmap(t_map *m)
{
	if (m->ply.ipy == 0 || m->ply.ipx == 0)
	{
		m = free_map(m);
		print_custom_err(INVALID_MAP);
	}
	if (m->ply.ipy >= m->height - 1 || m->ply.ipx >= m->width - 1)
	{
		m = free_map(m);
		print_custom_err(INVALID_MAP);
	}
	if (m->ply.ipx >= ft_strlen(m->map[m->ply.ipy]) - 1)
	{
		m = free_map(m);
		print_custom_err(INVALID_MAP);
	}
	return (1);
}
