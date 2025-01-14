/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:14:03 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/14 19:46:44 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc_bonus/game_bonus.h"

/* Look for mouse position
*	- If action = 0 -> Start mouse position
*	- If action = 1 -> Compare movement and apply rotation
*/
t_game	*hook_rotation(t_game *gm, int action)
{
	int32_t	mouse_x;
	int32_t	mouse_y;

	mlx_get_mouse_pos(gm->mlxd->mlx, &mouse_x, &mouse_y);
	if (action)
	{
		if (mouse_x < gm->msp_x)
			rotate(gm, ROT_LEFT);
		else if (mouse_x > gm->msp_x)
			rotate(gm, ROT_RIGHT);
	}
	gm->msp_x = mouse_x;
	gm->msp_y = mouse_y;
	return (gm);
}

/* Resize the window */
t_game	*resize_window(t_game *gm)
{
	size_t	w;
	size_t	h;

	w = gm->mlxd->mlx->width;
	h = gm->mlxd->mlx->height;
	if (gm->scr_h == h && gm->scr_w == w)
		return (gm);
	if (h < w)
		w = h;
	while (w % RAYS)
	{
		if (w < 60)
			w++;
		else
			w--;
	}
	mlx_resize_image(gm->mlxd->wimg, w, w);
	gm->ray.scale = w / RAYS;
	gm->scr_w = w;
	gm->scr_h = w;
	return (gm);
}

/* BONUS ACTIONS */
/*
*	- Resize the window
*	- Move vision with moving the mouse
*	- Gost Mode!
*/
t_game	*bonus_actions(t_game *gm)
{
	if (mlx_is_key_down(gm->mlxd->mlx, MLX_KEY_SPACE))
	{
		if (gm->gost)
			gm->gost = 0;
		else
			gm->gost = 1;
	}
	gm = hook_rotation(gm, 1);
	gm = resize_window(gm);
	return (gm);
}
