/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:45:23 by andmart2          #+#    #+#             */
/*   Updated: 2024/11/27 13:35:34 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3Dgame.h"

int	ft_rotate_lr(t_data *data, double rotspeed)
{
	t_player	*p;
	double		tmp_x;

	p = data->p;
	tmp_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rotspeed) - p->dir_y * sin(rotspeed);
	p->dir_y = tmp_x * sin(rotspeed) + p->dir_y * cos(rotspeed);
	tmp_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rotspeed) - p->plane_y * sin(rotspeed);
	p->plane_y = tmp_x * sin(rotspeed) + p->plane_y * cos(rotspeed);
	return (1);
}

int	ft_rotate_player(t_data *data, double rotate)
{
	int		moved;
	double	rotspeed;

	rotspeed = (double)(ROTSPEED * rotate);
	moved = 0;
	moved += ft_rotate_lr(data, rotspeed);
	return (moved);
}