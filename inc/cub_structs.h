/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:48:59 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/04 19:48:42 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCTS_H
# define CUB_STRUCTS_H

# include "game.h"

/* MLX DATA */
typedef struct s_mlxd
{
	mlx_t			*mlx;
	mlx_image_t		*wimg;
	mlx_texture_t	*icon;
	mlx_texture_t	*tx_no;
	mlx_texture_t	*tx_so;
	mlx_texture_t	*tx_we;
	mlx_texture_t	*tx_ea;
	mlx_texture_t	*tx_ac;
}					t_mlxd;

/* RECTANGLE STRUCT */
typedef struct s_rect
{
	size_t	width;
	size_t	height;
	int32_t	fill;
}			t_rect;

/* MAP & FILE DATA */
typedef struct s_map
{
	char	**file;
	char	**map;
	char	*tx_no;
	char	*tx_so;
	char	*tx_we;
	char	*tx_ea;
	size_t	height;
	size_t	width;
	size_t	size;
	int		f_rgb[3];
	int		c_rgb[3];
}			t_map;

/* PLAYER DATA */
/*
	- px	-> Player X Position
	- py	-> Player Y Position
	- pdx	-> Player Delta X
	- pdy	-> Player Delta Y
	- pa	-> Player Angle
	-----
	- plx_inmap	-> Player X Position in Map
	- ply_inmap	-> Player Y Position in Map
	-----
	- ipx_add & sub _xo -> This is necessary for collisions in X
	- ipy_add & sub _yo -> This is necessary for collisions in Y
*/
typedef struct s_ply
{
	double	px;
	double	py;
	double	pdx;
	double	pdy;
	double	pa;
	int		plx_inmap;
	int		ply_inmap;
	int		ipx_add_xo;
	int		ipx_sub_xo;
	int		ipy_add_yo;
	int		ipy_sub_yo;
}			t_ply;

/* RAYCAST DATA */
typedef struct s_raycast
{
	double	mx;
	double	my;
	double	mp;
	double	dof;
	double	rx;
	double	ry;
	double	ra;
	double	xo;
	double	yo;
	double	dis_h;
	double	dis_v;
	double	dist;
	double	line_h;
	double	line_o;
	double	line_t;
	double	delta_x;
	double	delta_y;
	double	theta;
}			t_raycast;

/* DATA OF A CUB-RECT TEXTURED */
typedef struct s_cubtex
{
	double	wall_x;
	int		draw_start;
	int		tex_x;
	int		tex_y;
	int32_t	texcol;
}		t_cubtex;

/* THE PRINCIPAL STRUCTURE */
typedef struct s_game
{
	t_mlxd		mlxd;
	t_map		*map;
	t_ply		ply;
	t_raycast	raycast;
	t_cubtex	cubtex;
	int32_t		c_flr;
	int32_t		c_sky;
}			t_game;

#endif
