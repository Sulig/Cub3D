/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_structs_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:48:59 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/15 20:25:06 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCTS_BONUS_H
# define CUB_STRUCTS_BONUS_H

# include "game_bonus.h"

/* MLX DATA */
/*
	- mlx -> The MLX
	- wing -> The image where will ocour the render of game
	- icon -> The Icon game
	- tx_no, _so, _we & _ea -> Set and convert textures loaded from file
	- tx_ac -> The Actual texture to apply to the wall
*/
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
/*
	- width -> Rect width
	- height -> Rect height
	- fill -> Rect fill color (int32)
*/
typedef struct s_rect
{
	size_t	width;
	size_t	height;
	int32_t	fill;
}			t_rect;

/* MINIMAP */
typedef struct s_point
{
	size_t	x;
	size_t	y;
}			t_point;

typedef struct s_view_area
{
	t_point	start;
	t_point	end;
}			t_view_area;

typedef struct s_draw_params
{
	t_rect	rect;
	int		map_x;
	int		map_y;
}			t_draw_params;

/* PLAYER DATA */
/*
	- px	-> Player X Position
	- py	-> Player Y Position
	- pdx	-> Player Delta X
	- pdy	-> Player Delta Y
	- pa	-> Player Angle
	-----
	- ipx	-> Player X Position in Map
	- ipy	-> Player Y Position in Map
	-----
*/
typedef struct s_ply
{
	double	px;
	double	py;
	double	new_px;
	double	new_py;
	double	pdx;
	double	pdy;
	double	pa;
	long	ipx;
	long	ipy;
	long	ipx_add_xo;
	long	ipx_sub_xo;
	long	ipy_add_yo;
	long	ipy_sub_yo;
}			t_ply;

/* MAP & FILE DATA */
/*
	- file	-> Data file attached to program
	- map	-> 2D Map
	- tx_no, _so, _we & _ea -> The textures loaded from file
	- pla	-> Player Focuss ("NSWE")
	-----
	- height	-> Max height of map
	- width		-> Max width of map
	- size		-> height * width of map
	-----
	- f_rgb & c_rgb -> Color background (Sky & Floor)
	-----
	- has_player	-> Counts num of players
	- ply			-> Attach to player_struct
*/
typedef struct s_map
{
	char	**file;
	char	**map;
	char	*tx_no;
	char	*tx_so;
	char	*tx_we;
	char	*tx_ea;
	char	pla;
	size_t	height;
	size_t	width;
	size_t	size;
	int		f_rgb[3];
	int		c_rgb[3];
	int		has_player;
	t_ply	ply;
}			t_map;

/* RAYCAST DATA */
typedef struct s_ray
{
	size_t	dof_x;
	size_t	dof_y;
	size_t	mx;
	size_t	my;
	size_t	mp;
	double	hx;
	double	hy;
	double	vx;
	double	vy;
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
	double	scale;
	double	delta_x;
	double	delta_y;
	double	htan;
	double	vtan;
	double	theta;
}			t_ray;

/* DATA OF A CUB-RECT TEXTURED */
typedef struct s_tex
{
	double	wall_x;
	double	x;
	double	y;
	int		tx;
	int		ty;
	t_rect	rc;
}		t_tex;

/* THE PRINCIPAL STRUCTURE */
typedef struct s_game
{
	t_mlxd		*mlxd;
	t_map		*map;
	t_ply		ply;
	t_ray		ray;
	t_tex		tex;
	int32_t		c_flr;
	int32_t		c_sky;
	size_t		scr_w;
	size_t		scr_h;
	int32_t		msp_x;
	int32_t		msp_y;
	int			door;
	int			gost;
}			t_game;

#endif
