/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_mapstruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:40:39 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/05 14:30:29 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	*free_map(t_map *map)
{
	map->file = ft_free_arrstr(map->file);
	map->map = ft_free_arrstr(map->map);
	map->tx_no = ft_free_str(map->tx_no);
	map->tx_so = ft_free_str(map->tx_so);
	map->tx_we = ft_free_str(map->tx_we);
	map->tx_ea = ft_free_str(map->tx_ea);
	ft_bzero(map, sizeof(t_map));
	free(map);
	return (NULL);
}

t_map	*new_map(t_map *map, char *file)
{
	char	*tmp;
	int		fd;

	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
	{
		print_errmalloc();
		return (NULL);
	}
	fd = open(file, O_RDONLY);
	tmp = get_next_line(fd);
	if (!tmp)
		ft_printf("\033[1;31mError\nSomething went wrong!\n");
	while (tmp)
	{
		map->file = (char **)arrpush((void **)map->file, (void *)tmp);
		tmp = ft_free_str(tmp);
		tmp = get_next_line(fd);
	}
	return (map);
}
