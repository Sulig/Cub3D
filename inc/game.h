/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:09:36 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/05 14:28:22 by sadoming         ###   ########.fr       */
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

/**/
void	print_err_arfor(int error);
void	print_errmalloc(void);

/* CHECKERS */
int	check_format(char *file);

/* Utils for see what i'm saving */
void	ft_print_map_t(char **map);
void	ft_print_stat(t_map *map);

/* Manage Memory of map */
void	*free_map(t_map *map);
t_map	*new_map(t_map *map, char *file);

/* start.c */
void	start(t_map *map);

#endif
