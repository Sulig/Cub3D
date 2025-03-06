/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:38:17 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/06 16:55:52 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/game.h"

/* Calculate distance
 *	between player and rays endpoint
 *		** Use Pythagorean theorem --
*/
double	dist(double ax, double ay, double bx, double by)
{
	double	dx;
	double	dy;

	dx = bx - ax;
	dy = by - ay;
	return (sqrt(dx * dx + dy * dy));
}

/* Returns a uint32_t representing the color inserted in this function
 * R [0-255] - G [0-255] - B [0-255] - && ALPHA [0-255]
*/
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

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

/* Prints a Rectangle
 * - `paint` => Canvas MLX
 * - `x` && `y` => Start Position
 * - `rect` => *- width, height & color in a struct
*/
void	printrect(mlx_image_t *paint, size_t x, size_t y, t_rect rect)
{
	size_t	sy;
	size_t	sx;

	sy = 0;
	while (sy < rect.height)
	{
		sx = 0;
		while (sx < rect.width)
		{
			mlx_put_pixel(paint, x + sx, y + sy, rect.fill);
			sx++;
		}
		sy++;
	}
}

void	paint_bg(t_game *game)
{
	t_rect	sky;
	t_rect	floor;

	sky.height = game->scr_h;
	sky.width = game->scr_w;
	sky.fill = game->c_sky;
	floor.height = sky.height / 2;
	floor.width = sky.width;
	floor.fill = game->c_flr;
	printrect(game->mlxd->wimg, 0, 0, sky);
	printrect(game->mlxd->wimg, 0, floor.height, floor);
}
