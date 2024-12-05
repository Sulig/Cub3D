/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:20:16 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/05 20:15:38 by sadoming         ###   ########.fr       */
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

t_map	*clean_file(t_map *map)
{
	size_t	pos_pop;
	size_t	size;
	size_t	len;
	char	*tmp;

	size = -1;
	pos_pop = ft_search_str(map->file, "F");
	map->file = (char **)arrpop((void **)map->file, pos_pop);
	pos_pop = ft_search_str(map->file, "C");
	map->file = (char **)arrpop((void **)map->file, pos_pop);
	map->map = (char **)arrmap((void **)map->file);
	if (!map->map)
		print_errmalloc();
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
	return (map);
}

t_map	*parse_fileinfo_intovars(t_map *map)
{
	map = fill_pathtotextures(map);
	map	= fill_flcl_color(map);
	map = clean_file(map);
	return (map);
}
