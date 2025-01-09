/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycollision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:19:24 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/09 13:09:28 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

static int	check_wall(t_game *gm)
{
	if (gm->ray.my >= gm->map->height)
		gm->ray.my = gm->map->height - 1;
	if (gm->ray.mx >= gm->map->width)
		gm->ray.mx = gm->map->width - 1;
	if (gm->ray.mp > 0 && gm->ray.mp < gm->map->size)
		if (gm->map->map[gm->ray.my][gm->ray.mx] == '1')
			return (1);
	return (0);
}

static t_game	*hrz_lines_bucle(t_game *gm, double hx, double hy)
{
	gm->ray.hx = gm->ply.px;
	gm->ray.hy = gm->ply.py;
	while (gm->ray.dof_x < gm->map->width)
	{
		gm->ray.mx = (size_t)(gm->ray.rx) >> 6;
		gm->ray.my = (size_t)(gm->ray.ry) >> 6;
		gm->ray.mp = gm->ray.my * gm->map->width + gm->ray.mx;
		if (check_wall(gm))
		{
			hx = gm->ray.rx;
			hy = gm->ray.ry;
			gm->ray.hx = gm->ray.rx;
			gm->ray.hy = gm->ray.ry;
			gm->ray.dis_h = dist(gm->ply.px, gm->ply.py, hx, hy);
			gm->ray.dof_x = gm->map->width;
		}
		else
		{
			gm->ray.rx += gm->ray.xo;
			gm->ray.ry += gm->ray.yo;
			gm->ray.dof_x += 1;
		}
	}
	return (gm);
}

/* Check Horizontal Lines */
t_game	*check_hrzlines(t_game *gm)
{
	gm->ray.dof_x = 0;
	gm->ray.dis_h = 1000000000;
	gm->ray.atan = -1 / tan(gm->ray.ra);
	if (gm->ray.ra > PI)
	{
		gm->ray.ry = (((int)gm->ply.py >> 6) << 6) - 0.0001;
		gm->ray.rx = (gm->ply.py - gm->ray.ry) * gm->ray.atan + gm->ply.px;
		gm->ray.yo = -CUB_SCALE;
		gm->ray.xo = -gm->ray.yo * gm->ray.atan;
	}
	if (gm->ray.ra < PI)
	{
		gm->ray.ry = (((int)gm->ply.py >> 6) << 6) + CUB_SCALE;
		gm->ray.rx = (gm->ply.py - gm->ray.ry) * gm->ray.atan + gm->ply.px;
		gm->ray.yo = CUB_SCALE;
		gm->ray.xo = -gm->ray.yo * gm->ray.atan;
	}
	if (gm->ray.ra == 0 || gm->ray.ra == PI)
	{
		gm->ray.rx = gm->ply.px;
		gm->ray.ry = gm->ply.py;
		gm->ray.dof_x = gm->map->width;
	}
	return (hrz_lines_bucle(gm, gm->ray.hx, gm->ray.hy));
}

static t_game	*vrt_lines_bucle(t_game *gm, double vx, double vy)
{
	gm->ray.vx = gm->ply.px;
	gm->ray.vy = gm->ply.py;
	while (gm->ray.dof_y < gm->map->height)
	{
		gm->ray.mx = (size_t)(gm->ray.rx) >> 6;
		gm->ray.my = (size_t)(gm->ray.ry) >> 6;
		gm->ray.mp = gm->ray.my * gm->map->height + gm->ray.mx;
		if (check_wall(gm))
		{
			vx = gm->ray.rx;
			vy = gm->ray.ry;
			gm->ray.vx = gm->ray.rx;
			gm->ray.vy = gm->ray.ry;
			gm->ray.dis_v = dist(gm->ply.px, gm->ply.py, vx, vy);
			gm->ray.dof_y = gm->map->height;
		}
		else
		{
			gm->ray.rx += gm->ray.xo;
			gm->ray.ry += gm->ray.yo;
			gm->ray.dof_y += 1;
		}
	}
	return (gm);
}

/* Check Vertical Lines */
t_game	*check_vrtlines(t_game *gm)
{
	gm->ray.dof_y = 0;
	gm->ray.dis_v = 1000000000;
	gm->ray.ntan = -tan(gm->ray.ra);
	if (gm->ray.ra > P2 && gm->ray.ra < P3)
	{
		gm->ray.rx = (((int)gm->ply.px >> 6) << 6) - 0.0001;
		gm->ray.ry = (gm->ply.px - gm->ray.rx) * gm->ray.ntan + gm->ply.py;
		gm->ray.xo = -CUB_SCALE;
		gm->ray.yo = -gm->ray.xo * gm->ray.ntan;
	}
	if (gm->ray.ra < P2 || gm->ray.ra > P3)
	{
		gm->ray.rx = (((int)gm->ply.px >> 6) << 6) + CUB_SCALE;
		gm->ray.ry = (gm->ply.px - gm->ray.rx) * gm->ray.ntan + gm->ply.py;
		gm->ray.xo = CUB_SCALE;
		gm->ray.yo = -gm->ray.xo * gm->ray.ntan;
	}
	if (gm->ray.ra == 0 || gm->ray.ra == PI)
	{
		gm->ray.rx = gm->ply.px;
		gm->ray.ry = gm->ply.py;
		gm->ray.dof_y = gm->map->height;
	}
	return (vrt_lines_bucle(gm, gm->ray.vx, gm->ray.vy));
}
