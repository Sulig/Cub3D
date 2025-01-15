/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consts_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:49:31 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/15 20:25:33 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTS_BONUS_H
# define CONSTS_BONUS_H

/*		 ## SCREEN ##		*/
# define TITLE		"CUB3D BONUS"
# define WIN_WIDTH	1080
# define WIN_HEIGHT	1080

/*		 ## MINI MAP ##		*/
# define MAP_WINDOW_X		50
# define MAP_WINDOW_Y		50

# define MINMAP_CELL_H		26
# define MINMAP_CELL_W		26
# define VIEW_RADIUS		5
/*		## MINI MAP END ##		*/

# define ICON		"./assets/textures/so-long/exit.png"
/*		## SCREEN END ##	*/

/*		 ## MATH CONSTS ##		*/
# define PI			3.14159265358
# define P2			1.570796327
# define P3			4.71238898
# define DR			0.0174533
# define RAYS		60
# define RAYS_SUB	30
# define VEL		5
# define ANGLE_D	0.1

# define CUB_SCALE	64
/*	## MATH CONSTS END ##	*/

/*		 ## ACTIONS CONSTS ##		*/
# define ROT_LEFT	'>'
# define ROT_RIGHT	'<'
# define MOV_UP		'0'
# define MOV_DOWN	'1'
# define MOV_LEFT	'2'
# define MOV_RIGHT	'3'
# define HORZ		'H'
# define VERT		'V'
/*	## ACTIONS CONSTS END ##	*/

/*		 ## ERRORS CONSTS ##		*/
# define BAD_PLY_NUM	"The file don't have/or have multiple player/s!\n"
# define PLY_TRSNMAP	"Player have traspased to an unexistent ubication\n"
/*	## ERRORS CONSTS END ##	*/

/* OTHERS */
# define DOOR			'D'
# define WALLS			"1D"
# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1

#endif
