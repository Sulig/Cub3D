/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:09:36 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/10 17:23:46 by sadoming         ###   ########.fr       */
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
void	print_err_arfor(int error);
void	print_errmalloc(void);
void	print_mlxerror(void);
void	print_err_dupmiss(int error);
void	print_other_err(char *err);

/* CHECKERS */
int	check_format(char *file);
int check_dupmiss(t_map *map);

/* PARSER */
t_map	*parse_fileinfo_intovars(t_map *map);

/* Utils for see what i'm saving */
void	ft_print_map_t(char **map);
void	ft_print_stat(t_map *map);

/* Manage Memory of map */
void	*free_map(t_map *map);
t_map	*new_map(t_map *map, char *file);

/* start.c */
void	start(t_map *map);

#endif
