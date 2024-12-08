/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:49:31 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/03 19:57:26 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTS_H
# define CONSTS_H

/*		 ## SCREEN ##		*/
# define WIN_WIDTH	900
# define WIN_HEIGHT	900

# define SCR_WIDTH	900
# define SCR_HEIGHT	900

# define START_PX	0
# define START_PY	0
/*		## SCREEN END ##	*/

/*		 ## MATH CONSTS ##		*/
# define PI			3.14159265358
# define P2			1.570796327		// PI / 2
# define P3			4.71238898		// 3 * PI / 2
# define DR			0.0174533		// Value of a Dregree
# define RAYS		60
# define DIST		66
# define VEL		5

# define COLL_SIZE	25
# define CUB_SCALE	64
/*	## MATH CONSTS END ##	*/

/*		 ## IMAGES ##		*/
# define BAT		"./assets/sprites/Bat/Bat.png"
# define TRIANGLE	"./assets/sprites/Triangle_Pl.png"
# define DIAMOND	"./assets/sprites/diamond.png"
/* ----------------- */
/*		## IMAGES END ##	*/

/*		 ## TEXTURES ##		*/
/* ERROR TEXTURES */
# define TX_ERROR	"./assets/textures/error-tile-colors/error-tile.png"
# define TX_ERA		"./assets/textures/error-tile-colors/error-tile_ALPHA.png"
# define TX_ERR		"./assets/textures/error-tile-colors/error-tile_RED.png"
# define TX_ERG		"./assets/textures/error-tile-colors/error-tile_GREEN.png"
# define TX_ERC		"./assets/textures/error-tile-colors/error-tile_CYAN.png"
# define TX_ERY		"./assets/textures/error-tile-colors/error-tile_YELOW.png"
# define TX_ERGR	"./assets/textures/error-tile-colors/error-tile_GREY.png"
# define TX_ERRRGB	"./assets/textures/error-tile_anim/error-tile_0.png"
/* --- */

/* TEST TEXTURES */
# define TX_FLOOOR	"./assets/textures/so-long/Floor_v4.png"
# define TX_FLOOR	"./assets/textures/so-long/floor-diamond.png"
# define TX_COLOR	"./assets/textures/so-long/justacolor.png"
# define TX_TILE	"./assets/textures/so-long/Tile.png"
/* --- */

/* THE TEXTURES TO USE */
# define NO TX_FLOOOR
# define EA TX_ERG
# define WE TX_ERROR
# define SO TX_TILE
/* ----------------- */
/*		## TEXTURES END ##	*/

#endif
