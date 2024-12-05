/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:32:54 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/05 19:26:14 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

int main(int argc, char **args)
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
			ft_print_stat(map);
			//checker && parser
			//start(map);
			free_map(map);
		}
	}
	exit(0);
}
