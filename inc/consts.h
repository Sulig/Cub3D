/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:49:31 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/29 13:51:21 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTS_H
# define CONSTS_H

/*		 ## SCREEN ##		*/
# define WIDTH	1920
# define HEIGHT	1080
/*		## SCREEN END ##	*/

/*		 ## IMAGES ##		*/
/* THE SO-LONG BAT */
# define BAT    "./assets/Bat/Bat.png"
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
/* --- */

/* TEST TEXTURES */
# define TX_FLOOR	"./assets/textures/so-long/floor-diamond.png"
# define TX_COLOR	"./assets/textures/so-long/justacolor.png"
/* --- */

/* THE TEXTURES TO USE */
# define NO TX_ERR
# define EA TX_ERG
# define WE TX_ERROR
# define SO TX_ERA
/* ----------------- */
/*		## TEXTURES END ##	*/

#endif
