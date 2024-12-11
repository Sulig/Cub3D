/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:51:50 by andmart2          #+#    #+#             */
/*   Updated: 2024/12/11 17:55:46 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

int	ft_is_valid_neighbor(char c)
{
	return (c == ' ' || c == '1');
}

/*checks that around the ' ' the other chars are valid*/
int	ft_check_map_spaces(t_map *m, int i, int j)
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

/*checks that all the chars are valid and there is justo player position */
int	ft_check_map_chars(t_map *m, int i, int j)
{
	char	c;

	c = m->map[i][j];
	if (c != ' ' && c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'W'
		&& c != 'E')
		return (0);
	return (1);
}

/*verifies if the map is valid by checking the spaces,
	the chars and if there is one player */
void	ft_check_valid_map(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->height)
	{
		j = 0;
		while (j < m->width)
		{
			if (m->map[i][j] == ' ')
			{
				if (!ft_check_map_spaces(m, i, j))
					print_other_err("Invalid map, not closed properly");
			}
			if (!ft_check_map_chars(m, i, j))
				print_other_err("Invalid map, wrong characters");
			j++;
		}
		i++;
	}
	if (!check_colors(map))
		print_other_err("Invalid ceiling or floor colors");
}
