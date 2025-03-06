/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:09:36 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/06 19:23:17 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../../libft/inc/libft.h"
# include "../../MLX42/include/MLX42/MLX42.h"

# include <fcntl.h>
# include <math.h>

# include "consts.h"
# include "cub_structs.h"

/* PRINTING ERRORS */
void		print_err_arfor(int error);
void		print_errmalloc(void);
void		print_err_dupmiss(int error);
void		print_mlxerror(void);
void		print_custom_err(char *err);

/* CHECKERS */
int			check_format(char *file);
int			check_dupmiss(t_map *map);
int			check_colors(t_map *map);
int			check_valid_symbol(t_map *map);
int			check_player_inmap(t_map *m);
void		check_valid_map(t_map *m);

/* PARSER */
t_map		*parse_fileinfo_intovars(t_map *map);

/* DEBUG */
void		ft_print_map_t(char **map);
void		ft_print_stat(t_map *map);

/* MEMORY */
void		free_mlxd(t_mlxd *mlxd);
void		*free_map(t_map *map);
t_map		*new_map(t_map *map, char *file);

/* COLLISIONS */
int			can_move_to(t_game *gm);

/* ACTIONS */
t_game		*resize_window(t_game *gm);
void		rotate(t_game *gm, char direction);
void		translate(t_game *gm, char dir);
void		hook_keyboard(void *param);

/* GAME */
void		start(t_map *map);
t_game		*check_hrzlines(t_game *gm);
t_game		*check_vrtlines(t_game *gm);
void		raycasting(t_game *game);
t_game		*draw_textured_wall(t_game *gm, size_t r);

/* UTILITIES */
char		get_cell(t_map *map, long x, long y, int mapp);
double		dist(double ax, double ay, double bx, double by);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
uint32_t	get_rgba(mlx_texture_t *texture, size_t x, size_t y);
void		printrect(mlx_image_t *paint, size_t x, size_t y, t_rect rect);
void		paint_bg(t_game *game);

#endif
