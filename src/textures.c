/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:29:32 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/05 20:36:12 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/game.h"

/* Get the pixel color in texture */
uint32_t	get_rgba(mlx_texture_t *texture, size_t x, size_t y)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = texture->pixels[y * texture->width * 4 + (x * 4)];
	g = texture->pixels[y * texture->width * 4 + (x * 4) + 1];
	b = texture->pixels[y * texture->width * 4 + (x * 4) + 2];
	a = texture->pixels[y * texture->width * 4 + (x * 4) + 3];
	return (r << 24 | g << 16 | b << 8 | a);
}

static void	draw_pixel_column(t_game *gm, int r, int y)
{
	size_t	x;
	double	step_tex;
	double	tex_pos;

	x = 0;
	step_tex = (double)gm->mlxd->tx_ac->height / gm->ray.line_t;
	tex_pos = y * step_tex;
	gm->tex.ty = (int)tex_pos % gm->mlxd->tx_ac->height;
	while (x < gm->ray.scale)
	{
		gm->tex.tx = (int)(gm->tex.wall_x * gm->mlxd->tx_ac->width) % gm->mlxd->tx_ac->width;
		uint32_t color = get_rgba(gm->mlxd->tx_ac, gm->tex.tx, gm->tex.ty);
		mlx_put_pixel(gm->mlxd->wimg, r * gm->ray.scale + x, y + gm->ray.line_o, color);
		x++;
	}
}

t_game	*texture_and_print(t_game *gm, int r)
{
	int y;

	y = 0;
	while (y < gm->ray.line_t)
	{
		draw_pixel_column(gm, r, y);
		y++;
	}
	return (gm);
}
