/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:09:36 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/16 17:31:15 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../New_Libft/inc/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# include <fcntl.h>
# include <math.h>

# include "consts.h"
# include "cub_structs.h"

/* PRINTING ERRORS */
void		print_err_arfor(int error);
void		print_errmalloc(void);
void		print_mlxerror(void);
void		print_err_dupmiss(int error);
void		print_other_err(char *err);

/* CHECKERS */
int			check_format(char *file);
int			check_dupmiss(t_map *map);
int         check_colors(t_map *map);

/*CHECK_MAP.C*/

int         ft_is_valid_neighbor(char c);
int         ft_check_map_spaces(t_map *m, int i, int j);
int         ft_check_map_chars(t_map *m, int i, int j, int *player);
void        ft_check_valid_map(t_map *m, int player);

/* PARSER */
t_map		*parse_fileinfo_intovars(t_map *map);

/* Utils for see what i'm saving */
void		ft_print_map_t(char **map);
void		ft_print_stat(t_map *map);

/* Manage Memory of map */
void		*free_map(t_map *map);
t_map		*new_map(t_map *map, char *file);

/* GAME */
void		start(t_map *map);
t_game		*check_hrzlines(t_game *gm);
t_game		*check_vrtlines(t_game *gm);
void		raycasting(t_game *game);

/* UTILITIES */
double		dist(double ax, double ay, double bx, double by);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
uint32_t	get_rgba(mlx_texture_t *texture, size_t x, size_t y);
void		printrect(mlx_image_t *paint, size_t x, size_t y, t_rect rect);
void		paint_bg(t_game game);

#endif
