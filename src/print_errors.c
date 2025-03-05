/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:51:53 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/05 16:27:01 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/game.h"

/* Print custom error on invalid args or file extension
*	- For invalid number args	-> 0
*	- For invalid extension		-> 1
*	- For invalid/error file	-> 2
*/
void	print_err_arfor(int error)
{
	ft_printf_fd(2, R);
	if (!error)
		ft_printf_fd(2, BAD_ARGS);
	else if (error == 1)
		ft_printf_fd(2, BAD_EXT);
	else if (error == 2)
	{
		ft_printf_fd(2, BAD_FILE);
		exit(EXIT_FAILURE);
	}
	ft_printf_fd(2, "%s Please introduce ONE file .cub", Y);
	ft_printf_fd(2, " like this example:\n./cub3D map.cub %s\n", D);
	exit(EXIT_FAILURE);
}

/* Print Malloc error */
void	print_errmalloc(void)
{
	ft_printf_fd(STDERR_FILENO, RR);
	ft_printf_fd(2, MALLOC_ERROR);
	ft_printf_fd(2, D);
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
		ft_printf_fd(2, BAD_MISS);
	else if (error == 1)
		ft_printf_fd(2, BAD_DUP);
	else if (error == 2)
		ft_printf_fd(2, BAD_INFO);
	ft_printf_fd(2, D);
	exit(EXIT_FAILURE);
}

/* Print MLX error */
void	print_mlxerror(void)
{
	ft_printf_fd(2, mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

/* Print Custom Error */
void	print_custom_err(char *err)
{
	ft_printf_fd(2, R);
	ft_printf_fd(2, err);
	ft_printf_fd(2, D);
	exit(EXIT_FAILURE);
}
