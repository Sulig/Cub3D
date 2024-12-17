/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:01:29 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/16 19:25:39 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

/*
* Calculate how many times has to repeat a pixel
*	of the texture to apply and print
*	** See `get_rgba` in utilities.c
*/
static t_game	*texture_and_print(t_game *gm, int r)
{
	size_t	y;
	size_t	x;

	y = -1;
	gm->tex.rc.height = 1;
	gm->tex.rc.width = 1;
	if (gm->ray.dis_v < gm->ray.dis_h)
		gm->tex.wall_x = fmod(gm->ray.vy, CUB_SCALE) / CUB_SCALE;
	else
		gm->tex.wall_x = fmod(gm->ray.hx, CUB_SCALE) / CUB_SCALE;
	while (++y < gm->ray.line_t)
	{
		x = -1;
		gm->tex.ty = (y * gm->mlxd->tx_ac->height) / gm->ray.line_t;
		while (++x < gm->ray.scale)
		{
			gm->tex.tx = gm->tex.wall_x * gm->mlxd->tx_ac->width;
			gm->tex.rc.fill = get_rgba(gm->mlxd->tx_ac, gm->tex.tx, gm->tex.ty);
			gm->tex.x = (SCR_HEIGHT + r * gm->ray.scale) + x;
			gm->tex.y = ((SCR_HEIGHT / 2) - gm->ray.line_t / 2) + y;
			printrect(gm->mlxd->wimg, gm->tex.x, gm->tex.y, gm->tex.rc);
		}
	}
	return (gm);
}

/* Check if the ray is in horizontal wall */
static t_game	*horizontall_wall(t_game *gm)
{
	gm->ray.rx = gm->ray.vx;
	gm->ray.ry = gm->ray.vy;
	gm->ray.dist = gm->ray.dis_v;
	gm->ray.delta_x = gm->ray.rx - gm->ply.px;
	gm->ray.delta_y = gm->ray.ry - gm->ply.py;
	gm->ray.theta = atan2(gm->ray.delta_y, gm->ray.delta_x);
	if (gm->ray.theta > -PI / 2 && gm->ray.theta < P2)
		gm->mlxd->tx_ac = gm->mlxd->tx_ea;
	else
		gm->mlxd->tx_ac = gm->mlxd->tx_we;
	return (gm);
}

/* Calculate the distance */
static t_game	*check_wall_orientation(t_game *gm)
{
	if (gm->ray.dis_v < gm->ray.dis_h)
		return (horizontall_wall(gm));
	else
	{
		gm->ray.rx = gm->ray.hx;
		gm->ray.ry = gm->ray.hy;
		gm->ray.dist = gm->ray.dis_h;
		gm->ray.delta_x = gm->ray.rx - gm->ply.px;
		gm->ray.delta_y = gm->ray.ry - gm->ply.py;
		gm->ray.theta = atan2(gm->ray.delta_y, gm->ray.delta_x);
		if (gm->ray.theta > 0 && gm->ray.theta < PI)
			gm->mlxd->tx_ac = gm->mlxd->tx_so;
		else
			gm->mlxd->tx_ac = gm->mlxd->tx_no;
	}
	return (gm);
}

static t_game	*calculate_line_h(t_game *gm)
{
	double	ca;

	ca = gm->ply.pa - gm->ray.ra;
	if (ca < 0)
		ca += 2 * PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	gm->ray.dist = gm->ray.dist * cos(ca);
	gm->ray.line_h = (gm->map->size * SCR_WIDTH) / gm->ray.dist;
	if (gm->ray.line_h > SCR_HEIGHT)
		gm->ray.line_h = SCR_HEIGHT;
	gm->ray.line_o = SCR_HEIGHT / 2 - gm->ray.line_h / 2;
	gm->ray.line_t = gm->ray.line_h + gm->ray.line_o;
	return (gm);
}

void	raycasting(t_game *game)
{
	int	r;

	r = 0;
	game->ray.ra = game->ply.pa - DR * 30;
	if (game->ray.ra < 0)
		game->ray.ra += 2 * PI;
	if (game->ray.ra > 2 * PI)
		game->ray.ra -= 2 * PI;
	paint_bg(game);
	while (r < RAYS)
	{
		ft_printf("\033[1;35mr = %i\n", r);
		game = check_hrzlines(game);
		game = check_vrtlines(game);
		game = check_wall_orientation(game);
		game = calculate_line_h(game);
		game = texture_and_print(game, r);
		game->ray.ra += DR;
		if (game->ray.ra < 0)
			game->ray.ra += 2 * PI;
		if (game->ray.ra > 2 * PI)
			game->ray.ra -= 2 * PI;
		r++;
	}
	printmap(game);
}
