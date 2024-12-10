/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:51:53 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/10 17:22:59 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

/* Print custom error on invalid args or file extension
*	- For invalid number args	-> 0
*	- For invalid/error file	-> 1
*	- For invalid extension		-> 2
*/
void	print_err_arfor(int error)
{
	ft_printf_fd(2, R);
	if (!error)
		ft_printf_fd(2, "Error\nIncorrect number of arguments\n");
	else if (error == 1)
	{
		ft_printf_fd(2, "Error\nThis file don't exist!\n");
		exit(EXIT_FAILURE);
	}
	if (error == 2)
		ft_printf_fd(2, "Error\nInvalid Extension\n");
	ft_printf_fd(2, "%s Please introduce ONE file .cub", Y);
	ft_printf_fd(2, " like this example:\n./cub3D map.cub %s\n", D);
	exit(EXIT_FAILURE);
}

void	print_errmalloc(void)
{
	ft_printf_fd(STDERR_FILENO, RR);
	ft_printf_fd(2, "Insuficient Memory or Malloc Error");
	ft_printf_fd(2, D);
	exit(EXIT_FAILURE);
}

void	print_mlxerror(void)
{
	ft_printf_fd(2, mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

/* Print custom error on invalid info
*	- For missing info		-> 0
*	- For duplicate info	-> 1
*	- For invalid info		-> 2
*/
void	print_err_dupmiss(int error)
{
	ft_printf_fd(2, R);
	if (!error)
		ft_printf_fd(2, "Error\nSome info is missing!\n");
	else if (error == 1)
		ft_printf_fd(2, "Error\nSome info is duplicated!\n");
	else if (error == 2)
		ft_printf_fd(2, "Error\nInvalid info encountered!\n");
	ft_printf_fd(2, D);
	exit(EXIT_FAILURE);
}

void	print_other_err(char *err)
{
	ft_printf_fd(2, R);
	ft_printf_fd(2, err);
	ft_printf_fd(2, D);
	exit(EXIT_FAILURE);
}
