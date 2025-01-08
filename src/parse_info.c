/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:20:16 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/08 13:30:13 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

static t_map	*fill_pathtotextures(t_map *map)
{
	size_t	pos_pop;

	map->tx_no = map->file[ft_search_str(map->file, "NO")];
	map->tx_so = map->file[ft_search_str(map->file, "SO")];
	map->tx_we = map->file[ft_search_str(map->file, "WE")];
	map->tx_ea = map->file[ft_search_str(map->file, "EA")];
	map->tx_no = ft_strdup(map->tx_no);
	map->tx_so = ft_strdup(map->tx_so);
	map->tx_we = ft_strdup(map->tx_we);
	map->tx_ea = ft_strdup(map->tx_ea);
	pos_pop = ft_search_str(map->file, "NO");
	map->file = (char **)arrpop((void **)map->file, pos_pop);
	pos_pop = ft_search_str(map->file, "SO");
	map->file = (char **)arrpop((void **)map->file, pos_pop);
	pos_pop = ft_search_str(map->file, "WE");
	map->file = (char **)arrpop((void **)map->file, pos_pop);
	pos_pop = ft_search_str(map->file, "EA");
	map->file = (char **)arrpop((void **)map->file, pos_pop);
	return (map);
}

static t_map	*fill_flcl_color(t_map *map)
{
	char	*cl_tmp;
	char	*fl_tmp;
	char	**tmp;

	cl_tmp = map->file[ft_search_str(map->file, "C")];
	fl_tmp = map->file[ft_search_str(map->file, "F")];
	cl_tmp = ft_strtrim(cl_tmp, "C \t");
	fl_tmp = ft_strtrim(fl_tmp, "F \t");
	tmp = ft_split(cl_tmp, ',');
	if (!tmp || arrsize_str(tmp) != 3)
		print_err_dupmiss(2);
	map->c_rgb[0] = ft_atoi(tmp[0]);
	map->c_rgb[1] = ft_atoi(tmp[1]);
	map->c_rgb[2] = ft_atoi(tmp[2]);
	tmp = ft_free_arrstr(tmp);
	tmp = ft_split(fl_tmp, ',');
	if (!tmp || arrsize_str(tmp) != 3)
		print_err_dupmiss(2);
	map->f_rgb[0] = ft_atoi(tmp[0]);
	map->f_rgb[1] = ft_atoi(tmp[1]);
	map->f_rgb[2] = ft_atoi(tmp[2]);
	tmp = ft_free_arrstr(tmp);
	cl_tmp = ft_free_str(cl_tmp);
	fl_tmp = ft_free_str(fl_tmp);
	return (map);
}

static t_map	*clean_file(t_map *map)
{
	size_t	pos_pop;
	char	*tmp;

	pos_pop = ft_search_str(map->file, "F");
	map->file = (char **)arrpop((void **)map->file, pos_pop);
	pos_pop = ft_search_str(map->file, "C");
	map->file = (char **)arrpop((void **)map->file, pos_pop);
	map->map = (char **)arrmap((void **)map->file);
	if (!map->map)
		print_errmalloc();
	tmp = ft_strtrim(map->tx_no, "NO \t");
	map->tx_no = ft_strremplace(map->tx_no, tmp);
	tmp = ft_free_str(tmp);
	tmp = ft_strtrim(map->tx_so, "SO \t");
	map->tx_so = ft_strremplace(map->tx_so, tmp);
	tmp = ft_free_str(tmp);
	tmp = ft_strtrim(map->tx_we, "WE \t");
	map->tx_we = ft_strremplace(map->tx_we, tmp);
	tmp = ft_free_str(tmp);
	tmp = ft_strtrim(map->tx_ea, "EA \t");
	map->tx_ea = ft_strremplace(map->tx_ea, tmp);
	tmp = ft_free_str(tmp);
	return (map);
}

static t_map	*set_mapsize(t_map *map)
{
	size_t	len;

	map->height = -1;
	while (map->map[++map->height])
	{
		len = -1;
		while (map->map[map->height][++len])
		{
			if (ft_strchr("NSWE", map->map[map->height][len]))
			{
				map->pla = map->map[map->height][len];
				map->map[map->height][len] = '0';
				map->has_player++;
				map->ply.ipx = len;
				map->ply.ipy = map->height;
			}
		}
		if (len > map->width)
			map->width = len;
	}
	map->size = map->height * map->width;
	if (!map->has_player || map->has_player > 1)
		print_other_err(BAD_PLY_NUM);
	return (map);
}

/*
* Parse the recollected info `map->file`
* into the corresponent vars
*/
t_map	*parse_fileinfo_intovars(t_map *map)
{
	size_t	size;
	size_t	len;
	char	*tmp;

	size = -1;
	map = fill_pathtotextures(map);
	map = fill_flcl_color(map);
	map = clean_file(map);
	while (map->map[++size])
	{
		len = 0;
		while (map->map[size][len])
		{
			if (map->map[size][len] == '\t')
			{
				map->map[size][len] = ' ';
				tmp = ft_strinter(map->map[size], "   ", len);
				map->map[size] = ft_strremplace(map->map[size], tmp);
				tmp = ft_free_str(tmp);
			}
			len++;
		}
	}
	return (set_mapsize(map));
}
