/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:05:22 by andmart2          #+#    #+#             */
/*   Updated: 2025/01/14 19:27:56 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc_bonus/game_bonus.h"

/* Rotate the perspective view */
void	rotate(t_game *gm, char direction)
{
	if (direction == ROT_LEFT)
		gm->ply.pa -= ANGLE_D;
	else if (direction == ROT_RIGHT)
		gm->ply.pa += ANGLE_D;
	if (gm->ply.pa < 0)
		gm->ply.pa += 2 * PI;
	if (gm->ply.pa > 2 * PI)
		gm->ply.pa -= 2 * PI;
	gm->ply.pdx = cos(gm->ply.pa) * VEL;
	gm->ply.pdy = sin(gm->ply.pa) * VEL;
}

static void	move_player(t_game *gm, double angle, int sign)
{
	gm->ply.new_px = gm->ply.px;
	gm->ply.new_py = gm->ply.py;
	gm->ply.new_px += sign * VEL * cos(angle);
	gm->ply.new_py += sign * VEL * sin(angle);
}

/* Translate / Move the player */
void	translate(t_game *gm, char dir)
{
	if (dir == MOV_LEFT)
		move_player(gm, gm->ply.pa + P2, -1);
	else if (dir == MOV_RIGHT)
		move_player(gm, gm->ply.pa + P2, 1);
	else if (dir == MOV_UP)
		move_player(gm, gm->ply.pa, 1);
	else if (dir == MOV_DOWN)
		move_player(gm, gm->ply.pa, -1);
	if (can_move_to(gm))
	{
		gm->ply.px = gm->ply.new_px;
		gm->ply.py = gm->ply.new_py;
	}
	gm->ply.ipx = gm->ply.px / CUB_SCALE;
	gm->ply.ipy = gm->ply.py / CUB_SCALE;
	if (gm->ply.ipx < 0 || gm->ply.ipy < 0)
		print_other_err(PLY_TRSNMAP);
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
	gm = bonus_actions(gm);
	raycasting(gm);
}
