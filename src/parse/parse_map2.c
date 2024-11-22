/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:03:30 by andmart2          #+#    #+#             */
/*   Updated: 2024/11/22 13:11:39 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3Dgame.h"

void	ft_more_boards(t_data *data, t_map *m, int i)
{
	while (m->file[i])
	{
		if (!ft_is_valid_line(m->file[i]))
			ft_error(data, "Invalid map");
		i++;
	}
}