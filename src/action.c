/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:05:22 by andmart2          #+#    #+#             */
/*   Updated: 2025/01/08 12:58:08 by sadoming         ###   ########.fr       */
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

/* Translate / Move the player */
void	translate(t_game *gm, char dir)
{
	if (dir == MOV_LEFT || dir == MOV_RIGHT)
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
	if (dir == MOV_UP || dir == MOV_DOWN)
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
	//print_player_position(gm);
}
