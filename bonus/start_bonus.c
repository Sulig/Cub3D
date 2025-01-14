/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:47:42 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/14 20:01:48 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc_bonus/game_bonus.h"

/*
* Start MLX and all the textures
*/
static t_mlxd	init_mlxdata(t_map *map, t_mlxd mlxd)
{
	mlxd.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, TITLE, true);
	if (!mlxd.mlx)
		print_mlxerror();
	mlxd.wimg = mlx_new_image(mlxd.mlx, SCR_WIDTH, SCR_HEIGHT);
	if (!mlxd.wimg)
		print_mlxerror();
	mlxd.tx_no = mlx_load_png(map->tx_no);
	if (!mlxd.tx_no)
		print_mlxerror();
	mlxd.tx_so = mlx_load_png(map->tx_so);
	if (!mlxd.tx_so)
		print_mlxerror();
	mlxd.tx_we = mlx_load_png(map->tx_we);
	if (!mlxd.tx_we)
		print_mlxerror();
	mlxd.tx_ea = mlx_load_png(map->tx_ea);
	if (!mlxd.tx_ea)
		print_mlxerror();
	mlxd.icon = mlx_load_png(ICON);
	if (!mlxd.icon)
		print_mlxerror();
	mlx_set_icon(mlxd.mlx, mlxd.icon);
	return (mlxd);
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
	game.ply.px = game.ply.ipx * CUB_SCALE;
	game.ply.py = game.ply.ipy * CUB_SCALE;
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
	t_mlxd	mlxd;
	t_game	game;

	mlxd = init_mlxdata(map, mlxd);
	if (mlx_image_to_window(mlxd.mlx, mlxd.wimg, 0, 0) < 0)
		print_mlxerror();
	ft_bzero(&game, sizeof(t_game));
	game.mlxd = &mlxd;
	game.map = map;
	game.ply = map->ply;
	game.scr_h = SCR_HEIGHT;
	game.scr_w = SCR_WIDTH;
	game.gost = 0;
	game = *hook_rotation(&game, 0);
	ft_bzero(&game.ray, sizeof(t_ray));
	ft_bzero(&game.tex, sizeof(t_tex));
	game = start_player(game);
	mlx_loop_hook(mlxd.mlx, hook_keyboard, &game);
	mlx_loop(mlxd.mlx);
	mlx_terminate(mlxd.mlx);
	free_mlxd(&mlxd);
}
