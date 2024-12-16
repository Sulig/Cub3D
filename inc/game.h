/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:09:36 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/16 19:58:17 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../New_Libft/inc/libft.h"
# include "consts.h"
# include "cub_structs.h"
# include <fcntl.h>
# include <math.h>

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

/*CHECK_MAP.C*/

int			ft_is_valid_neighbor(char c);
int			ft_check_map_spaces(t_map *m, size_t i, size_t j);
int			ft_check_map_chars(t_map *m, size_t i, size_t j, int *player);
void		ft_check_valid_map(t_map *m, int player);

/* PARSER */
t_map		*parse_fileinfo_intovars(t_map *map);

/* DEBUG */
void		ft_print_map_t(char **map);
void		ft_print_stat(t_map *map);
void		printmap(t_game *gm);

/* MEMORY */
void		*free_map(t_map *map);
t_map		*new_map(t_map *map, char *file);

/*KEY_HOOK.C*/
void		hook_keyboard(void *param);
void		handle_key_translation(t_game *game, int key_forward,
				int key_backward);
void		handle_key_movement(t_game *game, int key, float angle_offset,
				float direction);
void		handle_key_rotation(t_game *game, int key, float angle_delta);

/* GAME */
void		start(t_map *map);
void		free_mlxd(t_mlxd *mlxd);
t_game		*check_hrzlines(t_game *gm);
t_game		*check_vrtlines(t_game *gm);
void		raycasting(t_game *game);

/* UTILITIES */
double		dist(double ax, double ay, double bx, double by);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
uint32_t	get_rgba(mlx_texture_t *texture, size_t x, size_t y);
void		printrect(mlx_image_t *paint, size_t x, size_t y, t_rect rect);
void		paint_bg(t_game *game);

#endif
