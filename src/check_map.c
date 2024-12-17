/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:51:50 by andmart2          #+#    #+#             */
/*   Updated: 2024/12/17 17:54:25 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

int	ft_is_valid_neighbor(char c)
{
	return (c == ' ' || c == '1');
}

static int	ft_check_map_spaces(t_map *m, size_t i, size_t j)
{
	if (i > 0 && !ft_is_valid_neighbor(m->map[i - 1][j]))
		return (0);
	if (i < m->height - 1 && !ft_is_valid_neighbor(m->map[i + 1][j]))
		return (0);
	if (j > 0 && !ft_is_valid_neighbor(m->map[i][j - 1]))
		return (0);
	if (j < m->width - 1 && !ft_is_valid_neighbor(m->map[i][j + 1]))
		return (0);
	return (1);
}

static int	ft_check_map_chars(t_map *m, size_t i, size_t j)
{
	char	c;

	c = m->map[i][j];
	if (c == ' ' || c == '0' || c == '1')
		return (1);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	ft_check_valid_map(t_map *m)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < m->height)
	{
		j = 0;
		while (j < m->width)
		{
			if (m->map[i][j] == ' ')
			{
				if (!ft_check_map_spaces(m, i, j))
					print_other_err("Invalid map, not closed properly\n");
			}
			if (!ft_check_map_chars(m, i, j))
				print_other_err("Invalid map, wrong characters!\n");
			j++;
		}
		i++;
	}
	if (!check_colors(m))
		print_other_err("Invalid ceiling or floor colors\n");
}
