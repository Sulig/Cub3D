/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:56:10 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/16 19:24:56 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../New_Libft/inc/libft.h"

int main(int argc, char **args)
{
	if (argc != 2 || !args)
	{
		ft_printf_fd(2, "%s Error\nIncorrect number of arguments\n", R);
		ft_printf_fd(2, "%s Please introduce ONE file .cub", Y);
		ft_printf_fd(2, " like this example:\n./cub3D map.cub %s \n", D);
		exit(1);
	}
	exit(0);
	return (0);
}
