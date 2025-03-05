/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:32:54 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/05 17:08:23 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/game.h"

int	main(int argc, char **args)
{
	t_map	*map;

	map = NULL;
	if (argc != 2 || !args)
		print_err_arfor(0);
	if (check_format(args[1]))
	{
		map = new_map(map, args[1]);
		if (map)
		{
			check_dupmiss(map);
			parse_fileinfo_intovars(map);
			check_valid_map(map);
			start(map);
			free_map(map);
		}
	}
	exit(0);
}
