/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:49:31 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/08 20:04:21 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTS_H
# define CONSTS_H

/*		 ## SCREEN ##		*/
# define TITLE		"CUB3D"
# define WIN_WIDTH	900
# define WIN_HEIGHT	900

# define SCR_WIDTH	900
# define SCR_HEIGHT	900

# define MINMAP_W	333
# define MINMAP_H	250
# define MINMAP_CW	15
# define MINMAP_CH	15

# define ICON		"./assets/textures/error-tile_anim/error-tile_0.png"
/*		## SCREEN END ##	*/

/*		 ## MATH CONSTS ##		*/
# define PI			3.14159265358
# define P2			1.570796327
# define P3			4.71238898
# define DR			0.0174533
# define RAYS		60
# define VEL		5
# define ANGLE_D	0.1

# define COLL_SIZE	20
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

/**/
# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1

#endif
