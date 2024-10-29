/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:56:10 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/29 19:43:16 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

/* TESTING ZONE! */
#include <stdio.h>

float px, py, pdx, pdy, pa;
/*
	-> px	-> Player X Position
	-> py	-> Player Y Position
	-> pdx	-> Player Delta X *
	-> pdy	-> Player Delta Y **
	-> pa	-> Player Angle (Where is fancing (what are you looking at?))

	*	pdx
	**	pdy
*/

static mlx_image_t *bat, *tx_floor, *tx_wall, *ptr;
static int			vel = 7;

static int mapS = 64;
static int map[]=
{
	1,1,1,1,1,1,1,1,
	1,0,1,0,0,0,0,1,
	1,0,1,0,0,0,0,1,
	1,0,1,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,1,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1
};

static void error(void)
{
	ft_printf_fd(2, mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	printmap(mlx_t *mlx)
{
	int y = 0, x = 0;

	for (int s = 0; s < mapS; s++)
	{
		if (map[s] == 0)
			if (mlx_image_to_window(mlx, tx_floor, x * mapS, y * mapS) < 0)
        		error();
		if (map[s] == 1)
			if (mlx_image_to_window(mlx, tx_wall, x * mapS, y * mapS) < 0)
        		error();
		x++;
		if ((s + 1) % 8 == 0 && s)
		{
			x = 0;
			y++;
		}
	}
}

/*this function will be called for every frame
* this is for detecting key_inputs
*/
void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
	{
		px += pdx;
		py += pdy;
		bat->instances[0].y -= vel;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	{
		px -= pdx;
		py -= pdy;
		bat->instances[0].y += vel;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	{
		pa -= 0.1f;
		if (pa < 0)
			pa += 2 * PI;
		pdx = cos(pa) * 5;
		pdy = sin(pa) * 5;
		bat->instances[0].x -= vel;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
		pa += 0.1f;
		if (pa > 2 * PI)
			pa -= 2 * PI;
		pdx = cos(pa) * 5;
		pdy = sin(pa) * 5;
		bat->instances[0].x += vel;
	}

	ft_printf(CLEAN);
	ft_printf("\nPlayer location: X[%u] Y[%u] Z[%u]\n", bat->instances[0].x, bat->instances[0].y, bat->instances[0].z);
	printf("px: %f | py: %f || pdx: %f | pdy: %f ||| pa: %f\n", px, py, pdx, pdy, pa);

}

void	start(void)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true)))
		error();

	/**/ /**/ /**/ /**/ /**/ /**/ /**/
	mlx_texture_t* texture = mlx_load_png(BAT);
	if (!texture)
        error();
	// Convert texture to a displayable image
	bat = mlx_texture_to_image(mlx, texture);
	if (!bat)
        error();
	/**/
	mlx_texture_t* textur = mlx_load_png(TX_ERGR);
	if (!textur)
        error();
	// Convert texture to a displayable image
	tx_floor = mlx_texture_to_image(mlx, textur);
	if (!tx_floor)
        error();
	/**/
	mlx_texture_t* textu = mlx_load_png(TX_ERROR);
	if (!textu)
        error();
	// Convert texture to a displayable image
	tx_wall = mlx_texture_to_image(mlx, textu);
	if (!tx_wall)
        error();
	/**/
	mlx_texture_t* tex = mlx_load_png(DIAMOND);
	if (!tex)
        error();
	// Convert texture to a displayable image
	ptr = mlx_texture_to_image(mlx, tex);
	if (!ptr)
        error();
	/**/ /**/ /**/ /**/ /**/ /**/ /**/


	/*init*/
	px = 300;
	py = 300;
	pdx = cos(pa) * 5;
	pdy = sin(pa) * 5;
	/*----*/

	//print map
	printmap(mlx);

	// Put bat into window
	if (mlx_image_to_window(mlx, bat, px, py) < 0)
        error();
	// this is the "actual pointer"
	if (mlx_image_to_window(mlx, ptr, px, py) < 0)
		error();

	/********************************/
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
}

/* ############# */

int main(int argc, char **args)
{
	if (argc != 2 || !args)
	{
		ft_printf_fd(2, "%s Error\nIncorrect number of arguments\n", R);
		ft_printf_fd(2, "%s Please introduce ONE file .cub", Y);
		ft_printf_fd(2, " like this example:\n./cub3D map.cub %s \n", D);
		exit(1);
	}
	/* ADD File && Map control condition */
	/* +++++ */
		/* Put this to run if map is correct -> */
			start(/*t_map*/); // The idea will be passing the map into a struct
		/* I will change (exit) to respective function,
		*  so exit failure ocours if something went wrong,
		*  instead of function returning "EXIT_FAILURE"
		*/
	/* +++++ */
	return (0);
}
