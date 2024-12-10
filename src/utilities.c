/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:38:17 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/10 18:42:09 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

/* Prints a Rectangle
 * - mlx-img, -- X --, -- Y --, width, height, color
 */
void	printRect(mlx_image_t *paint, size_t x, size_t y, t_rect rect)
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
