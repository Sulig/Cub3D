/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:56:10 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/21 17:54:45 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../New_Libft/inc/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include "../inc/consts.h"

/* TESTING ZONE! */
static void error(void)
{
	ft_printf_fd(2, mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int	start(void)
{
	mlx_t* mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(666, 666, "MLX42", true)))
	{
		ft_printf(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	mlx_texture_t* texture = mlx_load_png(TX_ERROR);
	if (!texture)
        error();

	// Convert texture to a displayable image
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	if (!img)
        error();

	// Display the image
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        error();

	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

/* ############# */

int main(int argc, char **args)
{
	if (argc != 2 || !args)
	{
		ft_printf_fd(2, "%s Error\nIncorrect number of arguments\n", R);
		ft_printf_fd(2, "%s Please introduce ONE file .cub", Y);
		ft_printf_fd(2, " like this example:\n./cub3D map.cub %s \n", D);
		exit(1);
	}
	/* ADD File && Map control condition */
	/* +++++ */

	/* +++++ */
	return (start());
}
