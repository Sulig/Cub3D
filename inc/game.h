/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:09:36 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/22 14:50:49 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../New_Libft/inc/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# include "consts.h"



    /* STRUCTS */
/* NECESSARY FOR MLX */

/* PLAYER */
typedef struct s_lcn
{
	size_t		x;
	size_t		y;
}				t_lcn;
typedef struct s_player
{
    mlx_texture_t   *ply_tx;
    mlx_image_t     *player;
	//t_map		*map;
	t_lcn		act;
}				t_player;

typedef struct s_data
{
    mlx_t   *mlx; // MLX Struct
    mlx_image_t *wimg; //Window Image
    t_player    *ply; //Player
}               t_data;
    /* ------- */

#endif
