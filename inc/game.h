/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:09:36 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/04 20:24:29 by sadoming         ###   ########.fr       */
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

/* start.c */
void	start(t_map *map);

#endif
