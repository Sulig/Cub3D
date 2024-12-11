/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test-mess_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:56:10 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/11 19:01:27 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

/* Raycasting */
void	drawrays()
{
	int r, mx, my, mp, dof;
	double rx, ry, ra, xo, yo, disT;
	double lineH, lineO;

	ra = pa - DR * 30; //Angle vision
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;

	// --------------------- RAYCAST ---------------------------->
	for (r = 0; r < RAYS; r++)
	{
		// -- Check Horizontal lines -- //
		dof = 0;
		double distH = 1000000, hx = px, hy = py;
		double aTan = -1 / tan(ra);

		// looking down
		if (ra > PI)
		{
			ry = (((int)py>>6)<<6) -0.0001;
			rx = (py-ry) * aTan + px;
			yo = -CUB_SCALE;
			xo = -yo * aTan;
		}

		// looking up
		if (ra < PI)
		{
			ry = (((int)py>>6)<<6) + CUB_SCALE;
			rx = (py-ry) * aTan + px;
			yo = CUB_SCALE;
			xo = -yo * aTan;
		}

		// looking Forward
		if (ra == 0 || ra == PI)
		{
			rx = px;
			ry = py;
			dof = mapX;
		}

		while (dof < mapX)
		{
			mx = (int)(rx)>>6;
			my = (int)(ry)>>6;
			mp = my * mapX + mx;

			// if the ray hits a wall
			if (mp > 0 && mp < mapX * mapY && map[my][mx] == 1)
			{
				hx = rx;
				hy = ry;
				distH = dist(px, py, hx, hy);
				dof = mapX;
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
		double distV = 1000000, vx = px, vy = py;
		double nTan = -tan(ra);

		// looking left
		if (ra > P2 && ra < P3)
		{
			rx = (((int)px>>6)<<6) -0.0001;
			ry = (px-rx) * nTan + py;
			xo = -CUB_SCALE;
			yo = -xo * nTan;
		}

		// looking right
		if (ra < P2 || ra > P3)
		{
			rx = (((int)px>>6)<<6) + CUB_SCALE;
			ry = (px-rx) * nTan + py;
			xo = CUB_SCALE;
			yo = -xo * nTan;
		}

		// up-down
		if (ra == 0 || ra == PI)
		{
			rx = px;
			ry = py;
			dof = mapY;
		}

		while (dof < mapY)
		{
			mx = (int)(rx)>>6;
			my = (int)(ry)>>6;
			mp = my * mapX + mx;

			// if the ray hits a wall
			if (mp > 0 && mp < mapX * mapY && map[my][mx] == 1)
			{
				vx = rx;
				vy = ry;
				distV = dist(px, py, vx, vy);
				dof = mapY;
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

			double deltaX = rx - px;
			double deltaY = ry - py;
			double theta = atan2(deltaY, deltaX);

			//More brighter
			color = ft_pixel((int32_t)255, (int32_t)20, (int32_t)20, (int32_t)255);

			// Check if wall is East or West ->
			if (theta > -PI / 2 && theta < P2)	// East <=
			{
				wallc = ft_pixel((int32_t)20, (int32_t)199, (int32_t)20, (int32_t)255);
				current = tx_ea;
			}
			else								// West =>
			{
				wallc = ft_pixel((int32_t)199, (int32_t)20, (int32_t)199, (int32_t)255);
				current = tx_we;
			}
		}
		else
		{
			rx = hx;
			ry = hy;
			disT = distH;

			double deltaX = rx - px;
			double deltaY = ry - py;
			double theta = atan2(deltaY, deltaX);

			//More darker
			color = ft_pixel((int32_t)66, (int32_t)20, (int32_t)20, (int32_t)255);

			// Check if wall is North or South ->
			if (theta > 0 && theta < PI)	// South
			{
				wallc = ft_pixel((int32_t)66, (int32_t)66, (int32_t)66, (int32_t)255);
				current = tx_so;
			}
			else							// North
			{
				wallc = ft_pixel((int32_t)199, (int32_t)20, (int32_t)20, (int32_t)255);
				current = tx_no;
			}
		}

		// Move the rays textures (into minimap) where ray has collided to a wall
		//tx_ray->instances[r].x = rx;
		//tx_ray->instances[r].y = ry;
		//..........................

		// -- Let the 3D beggins!
		double ca = pa - ra;

		if (ca < 0)
			ca += 2 * PI;
		if (ca > 2 * PI)
			ca -= 2 * PI;
		disT = disT * cos(ca); // Fix fisheye

		lineH = (mapS * SCR_WIDTH) / disT;	// (mapSize * window width) / disT		// line height
		if (lineH > SCR_HEIGHT)
			lineH = SCR_HEIGHT;
		lineO = SCR_HEIGHT / 2 - lineH / 2;	// window height / 2 - lineH / 2	// line offset

		// Print every line casted, no texture
		// ----- mlx-img, --------- X ----------, ---------------- Y -------------------, width, -- height --, color
		//printRect(screen, SCR_HEIGHT + r * scale, (SCR_HEIGHT / 2) - (lineH + lineO) / 2, scale, lineH + lineO, color);

		// Draw Wall pixel per pixel with a solid color
		// The 2 versions are working correctly
		/* // V1
		for (int y = 0; y < lineH; y++)
			for (int x = 0; x < scale; x++)
				printRect(screen, SCR_HEIGHT + r * scale, (SCR_HEIGHT / 2) - (lineH + lineO) / 2, x, y + lineO, wallc);
		*/
		/* // V2
		for (int y = 0; y <= (lineH + lineO); y++)
			for (int x = 0; x <= scale; x++)
				printRect(screen, (SCR_HEIGHT + r * scale) + x, ((SCR_HEIGHT / 2) - (lineH + lineO) / 2) + y, 1, 1, wallc);
		*/

		//------------------> Texture it -------------------->

		double wallX;
		if (distV < distH)
			wallX = fmod(vy, CUB_SCALE) / CUB_SCALE;  // Vertical
		else
			wallX = fmod(hx, CUB_SCALE) / CUB_SCALE;  // Horizontal

		int drawStart = ((SCR_HEIGHT / 2) - (lineH + lineO) / 2); // Centrar y aplicar offset

		for (int y = 0; y < (lineH + lineO); y++)
		{
			int texY = (y * current->height) / (lineH + lineO);
			for (int x = 0; x < scale; x++)
			{
				int texX = wallX * current->width;
				color = get_rgba(current, texX, texY);
				printRect(screen, (SCR_HEIGHT + r * scale) + x, drawStart + y, 1, 1, color);
			}
		}

		//****************************************************

		ra += DR;
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
	}
}

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
