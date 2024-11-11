/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:56:10 by sadoming          #+#    #+#             */
/*   Updated: 2024/11/11 19:25:36 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

/* TESTING ZONE! */
#include <stdio.h>

int32_t color, wallc;
float scale = SCR_WIDTH / RAYS;
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

static mlx_image_t *screen;
static mlx_image_t *player, *tx_floor, *tx_wall, *ptr, *tx_ray;

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


int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

static void error(void)
{
	ft_printf_fd(2, mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void ralph(void)
{
	ft_printf_fd(2, "\033[1;31m I'M GONNA WREAK IT!\n");
}

// Print Map
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
float	dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

/* Prints a Rectangle */
void	printRect(mlx_image_t *paint, int r_x, int r_y, int r_width, int r_height, int32_t r_color)
{
	for (int sy = 0; sy < r_height; sy++)
		for (int sx = 0; sx < r_width; sx++)
			mlx_put_pixel(paint, r_x + sx, r_y + sy, r_color);
}

/* Raycasting */
void	drawrays()
{
	int r, mx, my, mp, dof;
	float rx, ry, ra, xo, yo, disT;
	float lineH, lineO;

	ft_printf(CLEAN);
	ra = pa - DR * 30; //Angle vision
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;

	// Clear the screen (Do the "sky" and "floor")
	printRect(screen, 0, 0, SCR_WIDTH, SCR_HEIGHT, ft_pixel((int32_t)22, (int32_t)120, (int32_t)255, (int32_t)255));
	printRect(screen, 0, SCR_HEIGHT / 2, SCR_WIDTH, SCR_HEIGHT / 2, ft_pixel((int32_t)0, (int32_t)0, (int32_t)200, (int32_t)255));

	// --------------------- RAYCAST ---------------------------->
	for (r = 0; r < RAYS; r++)
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
				distH = dist(px, py, hx, hy);
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
				distV = dist(px, py, vx, vy);
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
			//More brighter
			color = ft_pixel((int32_t)20, (int32_t)255, (int32_t)20, (int32_t)255);
			wallc = ft_pixel((int32_t)255, (int32_t)255, (int32_t)225, (int32_t)255);
		}
		if (distV > distH)
		{
			rx = hx;
			ry = hy;
			disT = distH;
			//More darker
			color = ft_pixel((int32_t)20, (int32_t)66, (int32_t)20, (int32_t)255);
			wallc = ft_pixel((int32_t)200, (int32_t)200, (int32_t)200, (int32_t)200);
		}

		// -- Let the 3D beggins!
		float ca = pa - ra;

		if (ca < 0)
			ca += 2 * PI;
		if (ca > 2 * PI)
			ca -= 2 * PI;
		disT = disT * cos(ca); // Fix fisheye

		lineH = (mapS * SCR_WIDTH) / disT;	// (mapSize * window width) / disT		// line height
		if (lineH > SCR_HEIGHT)
			lineH = SCR_HEIGHT;
		lineO = 160 - lineH / 2;			// 160 - lineH / 2	// line offset

		ft_printf("\n ~ \e[38;5;215m Some values: \n");
		printf("{Ray[%i]}-> DisT = %f |/\\-/\\| rx[%f] ry[%f]\n", r, disT, rx, ry);
		printf("lineH = %f\t // lineO = %f\n", lineH, lineO);
		printf("\nPlayer location: X[%f] Y[%f]\n", px, py);
		printf("Vision: pdx: %f | pdy: %f ||| pa: %f\n", pdx, pdy, pa);
		ft_printf("\t\t\t\t V%s", D);

		// ----- mlx-img, --------- X ----------, ---------------- Y -------------------, width, -- height --, color
		printRect(screen, SCR_HEIGHT + r * scale, (SCR_HEIGHT / 2) - (lineH + lineO) / 2, scale, lineH + lineO, color);

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
	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		px -= pdx * pa;
		py += pdy + pdx;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		px += pdx * pa;
		py -= pdy + pdx;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W))
	{
		px += pdx;
		py += pdy;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S))
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
	player->instances[0].x = px;
	player->instances[0].y = py;
	/* Radial Movement for pointer */
	ptr->instances[0].x = player->instances[0].x + cos(pa) * DIST;
	ptr->instances[0].y = player->instances[0].y + sin(pa) * DIST;

	/* Cast ray */
	drawrays(NULL);

	/**/
	//ft_printf(CLEAN);
	//printf("\nPlayer location: X[%f] Y[%f]\n", px, py);
	//ft_printf("Pointer location: X[%u] Y[%u]\n", ptr->instances[0].x, ptr->instances[0].y);
	//printf("\nVision: pdx: %f | pdy: %f ||| pa: %f\n", pdx, pdy, pa);
	/**/
}

void	start(void)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "CUB3D", true)))
		error();

	/**/ /**/ /**/ /**/ /**/ /**/ /**/
	mlx_texture_t* texture = mlx_load_png(DIAMOND);
	if (!texture)
		error();
	// Convert texture to a displayable image
	player = mlx_texture_to_image(mlx, texture);
	if (!player)
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
	tx_ray = mlx_texture_to_image(mlx, tx);
	if (!tx_ray)
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

	// Put player into window
	if (mlx_image_to_window(mlx, player, px, py) < 0)
		error();
	// this is the "actual pointer"
	if (mlx_image_to_window(mlx, ptr, px + DIST, py + DIST) < 0)
		error();

	// this is the "actual ray-pointer"
	//for (int i = 0; i < 60; i++)
	//	if (mlx_image_to_window(mlx, tx_ray, px + DIST, py + DIST) < 0)
	//		error();

	// The screen
	screen = mlx_new_image(mlx, SCR_WIDTH, SCR_HEIGHT);
	if (!screen)
		error();
	if (mlx_image_to_window(mlx, screen, START_PX, 0) < 0)
		error();

	printRect(screen, 0, 0, SCR_WIDTH, SCR_HEIGHT, ft_pixel((int32_t)22, (int32_t)120, (int32_t)255, (int32_t)255));
	printRect(screen, 0, SCR_HEIGHT / 2, SCR_WIDTH, SCR_HEIGHT / 2, ft_pixel((int32_t)0, (int32_t)0, (int32_t)200, (int32_t)255));
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
