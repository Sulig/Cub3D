/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:47:42 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/16 18:34:45 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

/*
 * Start MLX and all the textures
 */
static t_mlxd	*init_mlxdata(t_map *map, t_mlxd *mlxd)
{
	mlxd->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, TITLE, true);
	if (!mlxd->mlx)
		print_mlxerror();
	mlxd->wimg = mlx_new_image(mlxd->mlx, SCR_WIDTH, SCR_HEIGHT);
	if (!mlxd->wimg)
		print_mlxerror();
	mlxd->tx_no = mlx_load_png(map->tx_no);
	if (!mlxd->tx_no)
		print_mlxerror();
	mlxd->tx_so = mlx_load_png(map->tx_so);
	if (!mlxd->tx_so)
		print_mlxerror();
	mlxd->tx_we = mlx_load_png(map->tx_we);
	if (!mlxd->tx_we)
		print_mlxerror();
	mlxd->tx_ea = mlx_load_png(map->tx_ea);
	if (!mlxd->tx_ea)
		print_mlxerror();
	mlxd->icon = mlx_load_png(ICON);
	if (!mlxd->icon)
		print_mlxerror();
	mlx_set_icon(mlxd->mlx, mlxd->icon);
	return (mlxd);
}

/*
 * Track on keydown => Do action
 * Need cleaning
 */
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
}

/*
 * Start player vars and set bgcolor
 */
static t_game	start_player(t_game game)
{
	int32_t	color[3];

	if (game.map->pla == 'N')
		game.ply.pa = P3;
	else if (game.map->pla == 'S')
		game.ply.pa = P2;
	else if (game.map->pla == 'W')
		game.ply.pa = PI;
	else if (game.map->pla == 'E')
		game.ply.pa = 0;
	game.ply.px = game.ply.plx_inmap * CUB_SCALE;
	game.ply.py = game.ply.ply_inmap * CUB_SCALE;
	game.ply.pdx = cos(game.ply.pa) * 5;
	game.ply.pdy = sin(game.ply.pa) * 5;
	color[0] = (int32_t)game.map->c_rgb[0];
	color[1] = (int32_t)game.map->c_rgb[1];
	color[2] = (int32_t)game.map->c_rgb[2];
	game.c_sky = ft_pixel(color[0], color[1], color[2], 255);
	color[0] = (int32_t)game.map->f_rgb[0];
	color[1] = (int32_t)game.map->f_rgb[1];
	color[2] = (int32_t)game.map->f_rgb[2];
	game.c_flr = ft_pixel(color[0], color[1], color[2], 255);
	game.ray.scale = SCR_WIDTH / RAYS;
	return (game);
}

void	start(t_map *map)
{
	t_mlxd	*mlxd;
	t_game	game;

	mlxd = ft_calloc(sizeof(t_mlxd), 1);
	if (!mlxd)
		print_errmalloc();
	mlxd = init_mlxdata(map, mlxd);
	if (mlx_image_to_window(mlxd->mlx, mlxd->wimg, 0, 0) < 0)
		print_mlxerror();
	game.mlxd = mlxd;
	game.map = map;
	game.ply = map->ply;
	ft_bzero(&game.ray, sizeof(t_ray));
	ft_bzero(&game.tex, sizeof(t_tex));
	game = start_player(game);
	paint_bg(game);
	raycasting(&game);
	// mlx_loop_hook(mlxd->mlx, hook_keyboard, &game);
	mlx_loop(mlxd->mlx);
	mlx_terminate(mlxd->mlx);
	// free memory inside mlxd?
	mlxd = ft_free_ptr((void *)mlxd);
}
