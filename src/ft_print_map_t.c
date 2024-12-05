/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:59:29 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/05 14:47:49 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game.h"

static void	ft_print_case(char c)
{
	if (c == '1')
		ft_printf("\033[1;35m#");
	else if (c == '+')
		ft_printf("\033[1;32m+");
	else if (c == '0' || c == ' ' || c == '\t')
		ft_printf("\033[0;34m%c", c);
	else if (ft_strchr("NSWE", c))
		ft_printf("\033[0;33m%c", c);
	else
		ft_printf("\033[0;37m%c", c);
}

void	ft_print_map_t(char **map)
{
	size_t	size;
	size_t	len;

	size = 0;
	while (map[size])
	{
		len = 0;
		while (map[size][len])
		{
			ft_print_case(map[size][len]);
			len++;
		}
		//ft_printf("\n");
		size++;
	}
	ft_printf("\n");
}

void	ft_print_stat(t_map *map)
{
	//ft_printf("Width of map: %u\n", map->width);
	//ft_printf("Height of map: %u\n\n", map->height);
	ft_printf("\nPreview of file:\n\n");
	ft_print_map_t(map->file);
	//ft_printf("\nPreview of sol:\n\n");
	//ft_print_map_t(map->sol);
}
