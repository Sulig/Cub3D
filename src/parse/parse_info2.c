/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:02:26 by andmart2          #+#    #+#             */
/*   Updated: 2024/11/22 13:11:27 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3Dgame.h"

char	*ft_save_info(t_data *data, char *dir, char *info, int line_len)
{
	if (dir == NULL)
		return (ft_substr(info, 0, line_len));
	else
		ft_error(data, "Duplicate info");
	return (NULL);
}

int	ft_is_valid_line(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_if_3(t_data *data, char **color)
{
	int	i;
	int	j;

	i = 0;
	while (color[i])
	{
		j = 0;
		while (color[i][j])
		{
			if (!ft_isdigit(color[i][j]) && color[i][j] != ' ')
				ft_error(data, "Invalid color");
			j++;
		}
		i++;
	}
	if (i != 3)
		ft_error(data, "Invalid color");
	return (1);
}

int	ft_check_rgb(t_data *data, t_map *m)
{
	char	**c;

	c = ft_split(m->f, ',');
	if (!ft_check_if_3(data, c))
		ft_error(data, "Malloc error");
	m->f_rgb[0] = ft_atoi(c[0]);
	m->f_rgb[1] = ft_atoi(c[1]);
	m->f_rgb[2] = ft_atoi(c[2]);
	ft_free_all(c, 3);
	if (m->f_rgb[0] < 0 || m->f_rgb[0] > 255 || m->f_rgb[1] < 0
		|| m->f_rgb[1] > 255 || m->f_rgb[2] < 0 || m->f_rgb[2] > 255)
		return (0);
	c = ft_split(m->c, ',');
	if (!ft_check_if_3(data, c))
		ft_error(data, "Malloc error");
	m->c_rgb[0] = ft_atoi(c[0]);
	m->c_rgb[1] = ft_atoi(c[1]);
	m->c_rgb[2] = ft_atoi(c[2]);
	ft_free_all(c, 3);
	if (m->c_rgb[0] < 0 || m->c_rgb[0] > 255 || m->c_rgb[1] < 0
		|| m->c_rgb[1] > 255 || m->c_rgb[2] < 0 || m->c_rgb[2] > 255)
		return (0);
	return (1);
}

char	*ft_get_map_line(char *str, int width, int i, int j)
{
	char *ret;

	ret = malloc(width + 1);
	if (!ret)
		return (NULL);
	ret[0] = ' ';
	while (i < width && str[j])
	{
		ret[i] = str[j];
		i++;
		j++;
	}
	while (i < width)
	{
		ret[i] = ' ';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}