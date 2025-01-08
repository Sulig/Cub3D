/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:05:22 by andmart2          #+#    #+#             */
/*   Updated: 2025/01/08 19:39:34 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	handle_key_rotation(t_game *game, int key, float angle_delta)
{
	if (mlx_is_key_down(game->mlxd->mlx, key))
	{
		game->ply.pa += angle_delta;
		if (game->ply.pa < 0)
			game->ply.pa += 2 * PI;
		else if (game->ply.pa > 2 * PI)
			game->ply.pa -= 2 * PI;
		game->ply.pdx = cos(game->ply.pa) * VEL;
		game->ply.pdy = sin(game->ply.pa) * VEL;
	}
}

void	handle_key_movement(t_game *game, int key, float angle_offset,
		float direction)
{
	if (mlx_is_key_down(game->mlxd->mlx, key))
	{
		game->ply.px += direction * VEL * cos(game->ply.pa + angle_offset);
		game->ply.py += direction * VEL * sin(game->ply.pa + angle_offset);
	}
}

void	handle_key_translation(t_game *game, int key_forward, int key_backward)
{
	if (mlx_is_key_down(game->mlxd->mlx, key_forward))
	{
		game->ply.px += game->ply.pdx;
		game->ply.py += game->ply.pdy;
		game->ply.plx_inmap = game->ply.px / game->map->size;
		game->ply.ply_inmap = game->ply.py / game->map->size;
	}
	if (mlx_is_key_down(game->mlxd->mlx, key_backward))
	{
		game->ply.px -= game->ply.pdx;
		game->ply.py -= game->ply.pdy;
	}
}

void	hook_keyboard(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlxd->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlxd->mlx);
	handle_key_rotation(game, MLX_KEY_LEFT, -0.1f);
	handle_key_rotation(game, MLX_KEY_RIGHT, 0.1f);
	handle_key_movement(game, MLX_KEY_A, P2, -1);
	handle_key_movement(game, MLX_KEY_D, P2, 1);
	handle_key_translation(game, MLX_KEY_UP, MLX_KEY_DOWN);
	handle_key_translation(game, MLX_KEY_W, MLX_KEY_S);
	raycasting(game);
	printmap(game);
}
