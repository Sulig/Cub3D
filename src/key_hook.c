/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:05:22 by andmart2          #+#    #+#             */
/*   Updated: 2024/12/17 18:00:04 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

static void	rotate(t_game *gm, int key, double angle_delta)
{
	if (mlx_is_key_down(gm->mlxd->mlx, key))
	{
		gm->ply.pa += angle_delta;
		if (gm->ply.pa < 0)
			gm->ply.pa += 2 * PI;
		else if (gm->ply.pa > 2 * PI)
			gm->ply.pa -= 2 * PI;
		gm->ply.pdx = cos(gm->ply.pa) * VEL;
		gm->ply.pdy = sin(gm->ply.pa) * VEL;
	}
}

void	handle_key_movement(t_game *gm, int key, double angle_offset,
		double direction)
{
	if (mlx_is_key_down(gm->mlxd->mlx, key))
	{
		gm->ply.px += direction * VEL * cos(gm->ply.pa + angle_offset);
		gm->ply.py += direction * VEL * sin(gm->ply.pa + angle_offset);
	}
}

void	handle_key_translation(t_game *gm, int key_forward, int key_backward)
{
	if (mlx_is_key_down(gm->mlxd->mlx, key_forward))
	{
		gm->ply.px += gm->ply.pdx;
		gm->ply.py += gm->ply.pdy;
		gm->ply.plx_inmap = gm->ply.px / gm->map->size;
		gm->ply.ply_inmap = gm->ply.py / gm->map->size;
	}
	if (mlx_is_key_down(gm->mlxd->mlx, key_backward))
	{
		gm->ply.px -= gm->ply.pdx;
		gm->ply.py -= gm->ply.pdy;
	}
}

void	hook_keyboard(void *param)
{
	t_game	*gm;

	gm = (t_game *)param;
	if (mlx_is_key_down(gm->mlxd->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(gm->mlxd->mlx);
	rotate(gm, MLX_KEY_LEFT, -0.1f);
	rotate(gm, MLX_KEY_RIGHT, 0.1f);
	handle_key_movement(gm, MLX_KEY_A, P2, -1);
	handle_key_movement(gm, MLX_KEY_D, P2, 1);
	handle_key_translation(gm, MLX_KEY_UP, MLX_KEY_DOWN);
	handle_key_translation(gm, MLX_KEY_W, MLX_KEY_S);
	raycasting(gm);
	printmap(gm);
}
