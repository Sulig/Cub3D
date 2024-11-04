/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:56:10 by sadoming          #+#    #+#             */
/*   Updated: 2024/11/04 19:25:10 by sadoming         ###   ########.fr       */
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

static mlx_image_t *bat, *tx_floor, *tx_wall, *ptr, *tx_Xray, *tx_Yray;

/*
*	mapX -> max lenght of map
*	mapY -> max height of map
*	mapS -> Size of map
*/
static int mapX = 8, mapY = 8, mapS = 64;
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


/* Calculate distance
*	between player and rays endpoint
*		** Use Pythagorean theorem --
*/
float	dist(float ax, float ay, float bx, float by, float ang)
{
	(void)ang;
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

/* Raycasting */
void	drawrays(void)
{
	int r, mx, my, mp, dof;
	float rx, ry, ra, xo, yo, disT;

	ra = pa - DR * 30; //Angle vision
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	for (r = 0; r < 60; r++)
	{
		// -- Check Horizontal lines -- //
		dof = 0;
		float distH = 1000000, hx = px, hy = py;
		float aTan = -1 / tan(ra);

		// looking up
		if (ra > PI)
		{
			ry = (((int)py>>6)<<6) -0.0001;
			rx = (py-ry) * aTan + px;
			yo = -64;
			xo = -yo * aTan;
		}

		// looking down
		if (ra < PI)
		{
			ry = (((int)py>>6)<<6) + 64;
			rx = (py-ry) * aTan + px;
			yo = 64;
			xo = -yo * aTan;
		}

		// Forward vision
		if (ra == 0 || ra == PI)
		{
			rx = px;
			ry = py;
			dof = 8;
		}

		while (dof < 8)
		{
			mx = (int)(rx)>>6;
			my = (int)(ry)>>6;
			mp = my * mapX + mx;

			// if the ray hits a wall
			if (mp > 0 && mp < mapX * mapY && map[mp] == 1)
			{
				hx = rx;
				hy = ry;
				distH = dist(px, py, hx, hy, ra);
				dof = 8;
			}
			else
			{
				//let the ray continue
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}

		// -- Check Vertical lines -- //
		dof = 0;
		float distV = 1000000, vx = px, vy = py;
		float nTan = -tan(ra);

		// looking left
		if (ra > P2 && ra < P3)
		{
			rx = (((int)px>>6)<<6) -0.0001;
			ry = (px-rx) * nTan + py;
			xo = -64;
			yo = -xo * nTan;
		}

		// looking right
		if (ra < P2 || ra > P3)
		{
			rx = (((int)px>>6)<<6) + 64;
			ry = (px-rx) * nTan + py;
			xo = 64;
			yo = -xo * nTan;
		}

		// up-down
		if (ra == 0 || ra == PI)
		{
			rx = px;
			ry = py;
			dof = 8;
		}

		while (dof < 8)
		{
			mx = (int)(rx)>>6;
			my = (int)(ry)>>6;
			mp = my * mapX + mx;

			// if the ray hits a wall
			if (mp > 0 && mp < mapX * mapY && map[mp] == 1)
			{
				vx = rx;
				vy = ry;
				distV = dist(px, py, vx, vy, ra);
				dof = 8;
			}
			else
			{
				//let the ray continue
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}

		/* Check what ray is in minnor distance */
		if (distV < distH)
		{
			rx = vx;
			ry = vy;
			disT = distV;
		}
		if (distV > distH)
		{
			rx = hx;
			ry = hy;
			disT = distH;
		}

		tx_Xray->instances[0].x = rx;
		tx_Xray->instances[0].y = ry;

		// -- Let the 3D beggins!
		float ca = pa - ra;

		if (ca < 0)
			ca += 2 * PI;
		if (ca > 2 * PI)
			ca -= 2 * PI;
		disT = disT * cos(ca); // Fix fisheye

		float lineH = (mapS * WIDTH) / disT;	// (mapSize * window width) / disT	// line height
		float lineO = HEIGHT - lineH / 2;		// (window height)					// line offset

		if (lineH > WIDTH)
			lineH = WIDTH;

		ft_printf("lineH = %u\t lineO = %u\n", lineH, lineO);

		/* ** Need to think how i will put this into mlx
		*
		*	+ Idea:
		*		- 1* Create an image with the withd & heith of screen
		*			*(Use the "mlx_new_image" && mlx_image_to_window(mlx, image, 0, 0))
		*		- 2* Use the "mlx_put_pixel(image, x, y, color)"
		*			** This function will be inside of a while
		*			** I supose this will work with "lineH" && "lineO"
		*/

		ra += DR;
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
	}
}
/**/

/*this function will be called for every frame
* this is for detecting key_inputs
* Player movement and pointer is calculed here
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
	}
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	{
		px -= pdx;
		py -= pdy;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	{
		/* Move angle vision "<-" */
		pa -= 0.1f;
		if (pa < 0)
			pa += 2 * PI;
		pdx = cos(pa) * 5;
		pdy = sin(pa) * 5;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
		/* Move angle vision "->" */
		pa += 0.1f;
		if (pa > 2 * PI)
			pa -= 2 * PI;
		pdx = cos(pa) * 5;
		pdy = sin(pa) * 5;
	}
	bat->instances[0].x = px;
	bat->instances[0].y = py;
	/* Radial Movement for pointer */
	ptr->instances[0].x = bat->instances[0].x + cos(pa) * DIST;
	ptr->instances[0].y = bat->instances[0].y + sin(pa) * DIST;

	/* Cast ray */
	drawrays();

	/**/
	ft_printf(CLEAN);
	ft_printf("\nPlayer location: X[%u] Y[%u]\n", bat->instances[0].x, bat->instances[0].y);
	ft_printf("Pointer location: X[%u] Y[%u]\n", ptr->instances[0].x, ptr->instances[0].y);
	printf("\nVision: pdx: %f | pdy: %f ||| pa: %f\n", pdx, pdy, pa);
	/**/
}

void	start(void)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true)))
		error();

	/**/ /**/ /**/ /**/ /**/ /**/ /**/
	mlx_texture_t* texture = mlx_load_png(DIAMOND);
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
	/**/
	mlx_texture_t* tx = mlx_load_png(TX_ERR);
	if (!tx)
        error();
	// Convert texture to a displayable image
	tx_Xray = mlx_texture_to_image(mlx, tx);
	if (!tx_Xray)
        error();
	/**/
	mlx_texture_t* t = mlx_load_png(TX_ERG);
	if (!t)
        error();
	// Convert texture to a displayable image
	tx_Yray = mlx_texture_to_image(mlx, t);
	if (!tx_Yray)
        error();
	/**/ /**/ /**/ /**/ /**/ /**/ /**/


	/*init*/
	px = 200;
	py = 200;
	pdx = cos(pa) * 5;
	pdy = sin(pa) * 5;
	/*----*/

	//print map
	printmap(mlx);

	// Put bat into window
	if (mlx_image_to_window(mlx, bat, px, py) < 0)
        error();
	// this is the "actual pointer"
	if (mlx_image_to_window(mlx, ptr, px + DIST, py + DIST) < 0)
		error();
	// this is the "actual ray-pointer"
	if (mlx_image_to_window(mlx, tx_Xray, px + DIST, py + DIST) < 0)
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
