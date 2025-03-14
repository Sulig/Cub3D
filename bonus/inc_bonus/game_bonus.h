/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:09:36 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/15 19:54:40 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_BONUS_H
# define GAME_BONUS_H

# include "../../libft/inc/libft.h"
# include "../../MLX42/include/MLX42/MLX42.h"

# include <fcntl.h>
# include <math.h>

# include "consts_bonus.h"
# include "cub_structs_bonus.h"

/* PRINTING ERRORS */
void		print_err_arfor(int error);
void		print_errmalloc(void);
void		print_mlxerror(void);
void		print_err_dupmiss(int error);
void		print_other_err(char *err);

/* CHECKERS */
int			check_format(char *file);
int			check_dupmiss(t_map *map);
int			check_colors(t_map *map);
void		ft_check_valid_map(t_map *m);

/* PARSER */
t_map		*parse_fileinfo_intovars(t_map *map);

/* MEMORY */
void		free_mlxd(t_mlxd *mlxd);
void		*free_map(t_map *map);
t_map		*new_map(t_map *map, char *file);

/* COLLISIONS */
int			can_move_to(t_game *gm);

/* ACTIONS */
t_game		*hook_rotation(t_game *gm, int action);
t_game		*resize_window(t_game *gm);
t_game		*bonus_actions(t_game *gm);
void		rotate(t_game *gm, char direction);
void		translate(t_game *gm, char dir);
void		hook_keyboard(void *param);

/* GAME */
void		start(t_map *map);
t_game		*check_hrzlines(t_game *gm);
t_game		*check_vrtlines(t_game *gm);
void		raycasting(t_game *game);
void		printmap(t_game *gm);

/* UTILITIES */
int			ft_is_valid_neighbor(char c);
char		get_cell(t_map *map, long x, long y, int mapp);
double		dist(double ax, double ay, double bx, double by);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
uint32_t	get_rgba(mlx_texture_t *texture, size_t x, size_t y);
void		printrect(mlx_image_t *paint, size_t x, size_t y, t_rect rect);
void		paint_bg(t_game *game);

#endif
