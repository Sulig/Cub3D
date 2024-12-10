/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:47:42 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/10 17:53:05 by sadoming         ###   ########.fr       */
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
	return (mlxd);
}

/*
* Track on keydown => Do action
*/

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
	//Asignar orientacion del jugador
	//mlx_loop_hook(game.mlxd, ft_hook, &game);
	mlx_loop(game.mlxd);
	mlx_terminate(game.mlxd);
}
