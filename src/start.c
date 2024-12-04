/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:47:42 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/04 20:26:15 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

t_mlxd	init_mlxdata(t_map *map)
{
	t_mlxd	mlxd;

	mlxd.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, TITLE, true);
	if (!mlxd.mlx)
		error();
	mlxd.wimg = mlx_new_image(mlxd.mlx, SCR_WIDTH, SCR_HEIGHT);
	if (!mlxd.wimg)
		error();
	mlxd.tx_no = mlx_load_png(map->tx_no);
	if (!mlxd.tx_no)
		error();
	mlxd.tx_so = mlx_load_png(map->tx_so);
	if (!mlxd.tx_so)
		error();
	mlxd.tx_we = mlx_load_png(map->tx_we);
	if (!mlxd.tx_we)
		error();
	mlxd.tx_ea = mlx_load_png(map->tx_ea);
	if (!mlxd.tx_ea)
		error();
	mlxd.icon = mlx_load_png(ICON);
	if (!mlxd.icon)
		error();
	return (mlxd);
}

t_ply	start_player(t_map *map)
{
	t_ply	ply;

	ft_bzero(&ply, sizeof(t_ply));
	return (ply);
}

void	start(t_map *map)
{
	t_mlxd	mlxd;
	t_game	game;

	mlxd = init_mlxdata(map);
	if (mlx_image_to_window(mlxd.mlx, mlxd.wimg, 0, 0) < 0)
		error();
	game.mlxd = mlxd;
	game.map = map;
	game.ply = start_player(map);
}
