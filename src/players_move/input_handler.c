/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:45:33 by andmart2          #+#    #+#             */
/*   Updated: 2024/11/27 12:16:53 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3Dgame.h"

int	ft_key_pressed(int key, t_data *data)
{
	if (key == ESC)
		ft_exit(data);
	if (key == LEFTK)
		data->p->rotate = -1;
	if (key == RIGHTK)
		data->p->rotate = 1;
	if (key == W)
		data->p->move_y = 1;
	if (key == A)
		data->p->move_x = -1;
	if (key == S)
		data->p->move_y = -1;
	if (key == D)
		data->p->move_x = 1;
	return (0);
}

int	ft_key_released(int key, t_data *data)
{
	if (key == ESC)
		ft_exit(data);
	if (key == LEFTK && data->p->rotate <= 1)
		data->p->rotate = 0;
	if (key == RIGHTK && data->p->rotate >= -1)
		data->p->rotate = 0;
	if (key == W && data->p->move_y == 1)
		data->p->move_y = 0;
	if (key == A && data->p->move_x == -1)
		data->p->move_x = 0;
	if (key == S && data->p->move_y == -1)
		data->p->move_y = 0;
	if (key == D && data->p->move_x == 1)
		data->p->move_x = 0;
	return (0);
}

void	ft_listen_for_input(t_data *data)
{
	mlx_hook(data->win, 2, (1L << 0), ft_key_pressed, data);
	mlx_hook(data->win, 3, (1L << 1), ft_key_released, data);
}