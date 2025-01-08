/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:05:22 by andmart2          #+#    #+#             */
/*   Updated: 2025/01/08 19:29:02 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

/* Rotate the perspective view */
void	rotate(t_game *gm, char direction)
{
	if (direction == ROT_LEFT)
	{
		gm->ply.pa -= ANGLE_D;
		if (gm->ply.pa < 0)
			gm->ply.pa += 2 * PI;
		gm->ply.pdx = cos(gm->ply.pa) * VEL;
		gm->ply.pdy = sin(gm->ply.pa) * VEL;
	}
	if (direction == ROT_RIGHT)
	{
		gm->ply.pa += ANGLE_D;
		if (gm->ply.pa > 2 * PI)
			gm->ply.pa -= 2 * PI;
		gm->ply.pdx = cos(gm->ply.pa) * VEL;
		gm->ply.pdy = sin(gm->ply.pa) * VEL;
	}
}

void	translate(t_game *gm, char dir)
{
	if (dir == MOV_LEFT || dir == MOV_RIGHT)
		translate_horizontal(gm, dir);
	else if (dir == MOV_UP || dir == MOV_DOWN)
		translate_vertical(gm, dir);
}

void	translate_horizontal(t_game *gm, char dir)
{
	gm = can_move_to(gm, dir);
	if (gm->ply.can_move && dir == MOV_LEFT)
	{
		gm->ply.px += -1 * VEL * cos(gm->ply.pa + P2);
		gm->ply.py += -1 * VEL * sin(gm->ply.pa + P2);
	}
	if (gm->ply.can_move && dir == MOV_RIGHT)
	{
		gm->ply.px += 1 * VEL * cos(gm->ply.pa + P2);
		gm->ply.py += 1 * VEL * sin(gm->ply.pa + P2);
	}
}

void	translate_vertical(t_game *gm, char dir)
{
	gm = can_move_to(gm, dir);
	if (dir == MOV_UP && gm->ply.can_move_horz)
		gm->ply.px += gm->ply.pdx;
	if (dir == MOV_UP && gm->ply.can_move_vert)
		gm->ply.py += gm->ply.pdy;
	if (dir == MOV_DOWN && gm->ply.can_move_horz)
		gm->ply.px -= gm->ply.pdx;
	if (dir == MOV_DOWN && gm->ply.can_move_vert)
		gm->ply.py -= gm->ply.pdy;
}

void	hook_keyboard(void *param)
{
	t_game	*gm;

	gm = (t_game *)param;
	if (mlx_is_key_down(gm->mlxd->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(gm->mlxd->mlx);
	if (mlx_is_key_down(gm->mlxd->mlx, MLX_KEY_W))
		translate(gm, MOV_UP);
	if (mlx_is_key_down(gm->mlxd->mlx, MLX_KEY_UP))
		translate(gm, MOV_UP);
	if (mlx_is_key_down(gm->mlxd->mlx, MLX_KEY_S))
		translate(gm, MOV_DOWN);
	if (mlx_is_key_down(gm->mlxd->mlx, MLX_KEY_DOWN))
		translate(gm, MOV_DOWN);
	if (mlx_is_key_down(gm->mlxd->mlx, MLX_KEY_A))
		translate(gm, MOV_LEFT);
	if (mlx_is_key_down(gm->mlxd->mlx, MLX_KEY_D))
		translate(gm, MOV_RIGHT);
	if (mlx_is_key_down(gm->mlxd->mlx, MLX_KEY_LEFT))
		rotate(gm, ROT_LEFT);
	if (mlx_is_key_down(gm->mlxd->mlx, MLX_KEY_RIGHT))
		rotate(gm, ROT_RIGHT);
	raycasting(gm);
	printmap(gm);
}
