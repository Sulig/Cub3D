/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:29:32 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/06 19:28:49 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/game.h"

static t_game	*set_texture_direction(t_game *gm)
{
	if (gm->ray.side == 1)
	{
		if (gm->ray.dir_y > 0)
			gm->mlxd->tx_ac = gm->mlxd->tx_so;
		else
			gm->mlxd->tx_ac = gm->mlxd->tx_no;
	}
	else
	{
		if (gm->ray.dir_x > 0)
			gm->mlxd->tx_ac = gm->mlxd->tx_ea;
		else
			gm->mlxd->tx_ac = gm->mlxd->tx_we;
	}
	return (gm);
}

static void	paint_pixel(t_game *gm, int x, int y, t_tex t)
{
	if (x < 0 || x >= (int)gm->scr_w || y < 0 || y >= (int)gm->scr_h)
		return ;
	t.color = get_rgba(gm->mlxd->tx_ac, t.x, t.y);
	mlx_put_pixel(gm->mlxd->wimg, x, y, t.color);
}

t_game	*draw_textured_wall(t_game *gm, size_t r)
{
	t_tex	t;
	int		y;

	set_texture_direction(gm);
	t.width = gm->mlxd->tx_ac->width;
	t.height = gm->mlxd->tx_ac->height;
	if (gm->ray.side == 0)
		t.wall_x = gm->ply.py + gm->ray.dist * gm->ray.dir_y;
	else
		t.wall_x = gm->ply.px + gm->ray.dist * gm->ray.dir_x;
	t.wall_x -= floor(t.wall_x);
	t.x = (int)(t.wall_x * (double)t.width);
	t.step = 1.0 * t.height / gm->ray.line_h;
	t.tex_pos = (gm->ray.line_o - gm->scr_h / 2 + gm->ray.line_h / 2) * t.step;
	y = gm->ray.line_o;
	while (y < gm->ray.line_t)
	{
		t.y = (int)t.tex_pos & (t.height - 1);
		t.tex_pos += t.step;
		paint_pixel(gm, r, y, t);
		y++;
	}
	return (gm);
}
