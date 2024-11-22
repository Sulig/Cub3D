/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:32:46 by andmart2          #+#    #+#             */
/*   Updated: 2024/11/22 13:32:53 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3Dgame.h"

void	ft_init_player(t_player *p)
{
	p->dir = '\0';
	p->pos_x = 0.0;
	p->pos_y = 0.0;
	p->dir_x = 0.0;
	p->dir_y = 0.0;
	p->plane_x = 0.0;
	p->plane_y = 0.0;
	p->rotate = 0;
	p->move_x = 0;
	p->move_y = 0;
	p->has_moved = 0;
}

void	ft_init_map(t_data *data, t_map *m)
{
	m->no = NULL;
	m->so = NULL;
	m->we = NULL;
	m->ea = NULL;
	m->f = NULL;
	m->c = NULL;
	m->map = NULL;
	m->file = NULL;
	m->height = 0;
	m->width = 0;
	m->p = data->p;
}

void	ft_init_tray(t_ray *r)
{
	r->camera_x = 0.0;
	r->delta_x = 0.0;
	r->delta_y = 0.0;
	r->dir_x = 0.0;
	r->dir_y = 0.0;
	r->side_x = 0.0;
	r->side_y = 0.0;
	r->wall_dist = 0.0;
	r->wall_x = 0.0;
	r->side = 0;
	r->map_x = 0;
	r->map_y = 0;
	r->step_x = 0;
	r->step_y = 0;
	r->line_h = 0;
	r->draw_start = 0;
	r->draw_end = 0;
}

void	ft_init_tdata(t_data *data)
{
	data->height = HEIGHT;
	data->width = WIDTH;
	data->mlx = NULL;
	data->win = NULL;
	data->p = malloc(sizeof(t_player));
	if (!data->p)
		ft_error(data, "Malloc error");
	data->m = malloc(sizeof(t_map));
	if (!data->m)
		ft_error(data, "Malloc error");
	ft_init_player(data->p);
	ft_init_map(data, data->m);
}