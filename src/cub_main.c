/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:56:10 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/29 14:38:43 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

/* TESTING ZONE! */
static mlx_image_t *bat, *floor, *wall;
static int			vel = 7;

static int mapS = 64;
static int map[]=
{
	1,1,1,1,1,1,1,1,
	1,0,1,0,0,0,0,1,
	1,0,1,0,0,0,0,1,
	1,0,1,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,1,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1
};

static void error(void)
{
	ft_printf_fd(2, mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	printmap(mlx_t *mlx)
{
	int y = 0, x = 0;

	for (int s = 0; s < mapS; s++)
	{
		if (map[s] == 0)
			if (mlx_image_to_window(mlx, floor, x * mapS, y * mapS) < 0)
        		error();
		if (map[s] == 1)
			if (mlx_image_to_window(mlx, wall, x * mapS, y * mapS) < 0)
        		error();
		x++;
		if ((s + 1) % 8 == 0 && s)
		{
			x = 0;
			y++;
		}
	}
}

/*this function will be called for every frame
* this is for detecting key_inputs
*/
void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
	{
		bat->instances[0].y -= vel;
		ft_printf_fd(1, "Key pressed: %i\n", MLX_KEY_UP);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	{
		bat->instances[0].y += vel;
		ft_printf_fd(1, "Key pressed: %i\n",MLX_KEY_DOWN);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	{
		bat->instances[0].x -= vel;
		ft_printf_fd(1, "Key pressed: %i\n",MLX_KEY_LEFT);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
		bat->instances[0].x += vel;
		ft_printf_fd(1, "Key pressed: %i\n",MLX_KEY_RIGHT);
	}
}

void	start(void)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true)))
		error();

	/**/ /**/ /**/ /**/ /**/ /**/ /**/
	mlx_texture_t* texture = mlx_load_png(BAT);
	if (!texture)
        error();
	// Convert texture to a displayable image
	bat = mlx_texture_to_image(mlx, texture);
	if (!bat)
        error();
	/**/
	mlx_texture_t* textur = mlx_load_png(TX_ERGR);
	if (!textur)
        error();
	// Convert texture to a displayable image
	floor = mlx_texture_to_image(mlx, textur);
	if (!floor)
        error();
	/**/
	mlx_texture_t* textu = mlx_load_png(TX_ERROR);
	if (!textu)
        error();
	// Convert texture to a displayable image
	wall = mlx_texture_to_image(mlx, textu);
	if (!wall)
        error();
	/**/ /**/ /**/ /**/ /**/ /**/ /**/

	//print map
	printmap(mlx);

	// Put bat into window
	if (mlx_image_to_window(mlx, bat, 232, 232) < 0)
        error();

	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
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
		/* Put this to run if map is correct -> */
			start(/*t_map*/); // The idea will be passing the map into a struct
		/* I will change (exit) to respective function,
		*  so exit failure ocours if something went wrong,
		*  instead of function returning "EXIT_FAILURE"
		*/
	/* +++++ */
	return (0);
}
