/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:12:11 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/14 17:10:28 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc_bonus/game_bonus.h"

/* Verifies the format of file */
int	check_format(char *file)
{
	char	*format;

	if (open(file, O_RDONLY) == -1)
		print_err_arfor(1);
	format = ft_strstr(file, ".cub");
	if (!format)
		print_err_arfor(2);
	format = NULL;
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
			print_err_dupmiss(0);
		else if (checker[cnt] > 1)
			print_err_dupmiss(1);
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
			return (0);
		if (map->f_rgb[i] < 0 || map->f_rgb[i] > 255)
			return (0);
		i++;
	}
	return (1);
}
