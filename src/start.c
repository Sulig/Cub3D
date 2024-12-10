/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:47:42 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/10 18:47:24 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

/*
* Start MLX and all the textures
*/
static t_mlxd	init_mlxdata(t_map *map)
{
	t_mlxd	mlxd;

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
* Track on keydown => Do action
*/

t_game	start_player(t_game game)
{
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
	return (game);
}

void	start(t_map *map)
{
	t_mlxd	mlxd;
	t_game	game;

	mlxd = init_mlxdata(map);
	if (mlx_image_to_window(mlxd.mlx, mlxd.wimg, 0, 0) < 0)
		print_mlxerror();
	game.mlxd = &mlxd;
	game.map = map;
	game.ply = map->ply;
	ft_bzero(&game.raycast, sizeof(t_raycast));
	ft_bzero(&game.cubtex, sizeof(t_cubtex));
	game = start_player(game);
	//mlx_loop_hook(mlxd.mlx, ft_hook, &game);
	mlx_loop(mlxd.mlx);
	mlx_terminate(mlxd.mlx);
}
