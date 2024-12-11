/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:01:29 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/11 19:40:24 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	raycasting(t_game *game)
{
	int	r;

	r = 0;
	game->ray.ra = game->ply.pa - DR * 30;
	if (game->ray.ra < 0)
		game->ray.ra += 2 * PI;
	if (game->ray.ra > 2 * PI)
		game->ray.ra -= 2 * PI;
	while (r < RAYS)
	{
		game = check_hrzlines(game);
		game = check_vrtlines(game);
		//*
		game->ray.ra += DR;
		if (game->ray.ra < 0)
			game->ray.ra += 2 * PI;
		if (game->ray.ra > 2 * PI)
			game->ray.ra -= 2 * PI;
		r++;
	}
}
