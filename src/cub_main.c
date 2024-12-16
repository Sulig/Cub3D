/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:32:54 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/16 17:31:32 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

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
			//call map checker here
			start(map);
			free_map(map);
		}
	}
	exit(0);
}
