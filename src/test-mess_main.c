/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test-mess_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:56:10 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/12 19:31:56 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

/*this function will be called for every frame
 * this is for detecting key_inputs
 * Player movement and pointer is calculed here
 */
void ft_hook(void* param)
{
	mlx_t* mlx = param;

	// ----- Wall collision -----
	int xo = 0, yo = 0;

	if (pdx < 0)
		xo = -COLL_SIZE;
	else
		xo = COLL_SIZE;
	if (pdy < 0)
		yo = -COLL_SIZE;
	else
		yo = COLL_SIZE;

	int ipx = px / mapS, ipx_add_xo = (px+xo) / mapS, ipx_sub_xo = (px - xo) / mapS;
	int ipy = py / mapS, ipy_add_yo = (py+yo) / mapS, ipy_sub_yo = (py - yo) / mapS;
	//***********************//

	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		if (map[ipy_sub_yo][ipx_sub_xo] == 0)
		{
			px += -1 * VEL * cos(pa + P2);
			py += -1 * VEL * sin(pa + P2);
		}
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		if (map[ipy_add_yo][ipx_add_xo] == 0)
		{
			px += 1 * VEL * cos(pa + P2);
			py += 1 * VEL * sin(pa + P2);
		}
	}
	if (mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W))
	{
		if (map[ipy][ipx_add_xo] == 0)
			px += pdx;
		if (map[ipy_add_yo][ipx] == 0)
			py += pdy;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S))
	{
		if (map[ipy][ipx_sub_xo] == 0)
			px -= pdx;
		if (map[ipy_sub_yo][ipx] == 0)
			py -= pdy;
	}
}

/* ############# */
