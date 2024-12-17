/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:40:39 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/17 18:10:14 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	*free_mlxd(t_mlxd *mlxd)
{
	if (!mlxd)
		return (NULL);
	if (mlxd->tx_no)
		mlx_delete_texture(mlxd->tx_no);
	if (mlxd->tx_so)
		mlx_delete_texture(mlxd->tx_so);
	if (mlxd->tx_we)
		mlx_delete_texture(mlxd->tx_we);
	if (mlxd->tx_ea)
		mlx_delete_texture(mlxd->tx_ea);
	if (mlxd->icon)
		mlx_delete_texture(mlxd->icon);
	if (mlxd->wimg)
		mlx_delete_image(mlxd->mlx, mlxd->wimg);
	if (mlxd->mlx)
		mlx_terminate(mlxd->mlx);
	ft_bzero(mlxd, sizeof(t_mlxd));
	mlxd = ft_free_ptr((void *)mlxd);
	return (NULL);
}

void	*free_map(t_map *map)
{
	map->file = ft_free_arrstr(map->file);
	map->map = ft_free_arrstr(map->map);
	map->tx_no = ft_free_str(map->tx_no);
	map->tx_so = ft_free_str(map->tx_so);
	map->tx_we = ft_free_str(map->tx_we);
	map->tx_ea = ft_free_str(map->tx_ea);
	ft_bzero(map, sizeof(t_map));
	free(map);
	return (NULL);
}

t_map	*new_map(t_map *map, char *file)
{
	char	*rfile;
	char	*tmp;
	int		fd;

	rfile = NULL;
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		print_errmalloc();
	fd = open(file, O_RDONLY);
	tmp = get_next_line(fd);
	if (!tmp)
		ft_printf_fd(2, "%sError\nSomething went wrong!\n", R);
	while (tmp)
	{
		rfile = ft_strjoin_free_fst(rfile, tmp);
		tmp = ft_free_str(tmp);
		tmp = get_next_line(fd);
	}
	map->file = ft_split(rfile, '\n');
	rfile = ft_free_str(rfile);
	if (!map->file)
		print_errmalloc();
	return (map);
}
