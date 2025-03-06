/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:49:31 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/06 16:23:53 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTS_H
# define CONSTS_H

# include "error_messages.h"

/*		 ## SCREEN ##		*/
# define TITLE		"CUB3D"
# define WIN_WIDTH	1080
# define WIN_HEIGHT	1080

# define ICON		"./assets/textures/error-tile_anim/error-tile_0.png"
/*		## SCREEN END ##	*/

/*		 ## MATH CONSTS ##		*/
# define PI			3.14159265358
# define P2			1.570796327
# define P3			4.71238898

# define DR			0.0174533
# define FOV		1.04719755

# define RAYS		60

# define FVIEW		60
# define HEIGHT		1.6

# define VEL		5
# define ANGLE_D	0.1

# define CUB_SCALE	64
/*	## MATH CONSTS END ##	*/

/*		 ## ACTIONS CONSTS ##		*/
# define ROT_LEFT	'>'
# define ROT_RIGHT	'<'
# define MOV_UP		'W'
# define MOV_DOWN	'S'
# define MOV_LEFT	'A'
# define MOV_RIGHT	'D'
# define HORZ		'H'
# define VERT		'V'
/*	## ACTIONS CONSTS END ##	*/

/* OTHERS */
# define MAP_CHARS		"01NSWE \t"
# define PLY_CHARS		"NSWE"
# define FLOOR			'0'
# define WALL			'1'

# define MAX			4294967294

# define FALSE			0
# define TRUE			1

# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1
/*	## END ##	*/

#endif
