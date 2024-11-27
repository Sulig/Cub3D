/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:45:11 by andmart2          #+#    #+#             */
/*   Updated: 2024/11/27 12:46:10 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3Dgame.h"

void	ft_init_player_pos(t_player *p, int x, int y, char c)
{
	p->dir = c;
	p->pos_x = (double)x + 0.5;
	p->pos_y = (double)y + 0.5;
	ft_init_player_dir(p);
}

void	ft_init_player_dir_ns(t_player *p)
{
	if (p->dir == 'N')
	{
		p->dir_x = 0;
		p->dir_y = -1;
		p->plane_x = 0.66;
		p->plane_y = 0;
	}
	else if (p->dir == 'S')
	{
		p->dir_x = 0;
		p->dir_y = 1;
		p->plane_x = -0.66;
		p->plane_y = 0;
	}
}

void	ft_init_player_dir(t_player *p)
{
	if (p->dir == 'N' || p->dir == 'S')
		ft_init_player_dir_ns(p);
	else if (p->dir == 'E')
	{
		p->dir_x = 1;
		p->dir_y = 0;
		p->plane_x = 0;
		p->plane_y = 0.66;
	}
	else if (p->dir == 'W')
	{
		p->dir_x = -1;
		p->dir_y = 0;
		p->plane_x = 0;
		p->plane_y = -0.66;
	}
}