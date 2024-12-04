/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:02:07 by andmart2          #+#    #+#             */
/*   Updated: 2024/12/04 20:26:18 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game.h"

void	ft_readfile(int fd, t_map *m, int j)
{
	char	*line;
	int		i;

	i = 0;
	m->file = ft_calloc(sizeof(char *), (j + 1));
	line = get_next_line(fd);
	while (line > 0)
	{
		line = ft_expand_tabs(line);
		line = ft_strjoinfree(line, NULL);
		m->file[i] = ft_strdup(line);
		free(line);
		if (!m->file[i])
			ft_error(data, "Malloc error");
		i++;
		line = get_next_line(fd);
	}
	free(line);
}

void	ft_check_file(t_data *data, char *map, t_map *m)
{
	int	fd;
	int	i;

	if (ft_strcmp(ft_strrchr(map, '.'), ".cub") != 0)
		ft_error(data, "File is not .cub");
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error(data, "Error opening file");
	i = ft_count_lines(fd);
	close(fd);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error(data, "Error opening file");
	ft_readfile(data, fd, m, i);
	close(fd);
}

char	*ft_get_fc(t_data *data, char *dir, char *str, char c)
{
	int		i;
	int		j;
	char	*ret;

	if (dir != NULL)
		ft_error(data, "Duplicate info");
	i = 0;
	j = 0;
	if (str[i] && str[i] == c)
		i++;
	else
		return (NULL);
	while (str[i] && str[i] == ' ')
		i++;
	ret = malloc(ft_strlen(str) - i + 1);
	while (str[i])
	{
		ret[j] = str[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

int	ft_find_info(t_data *data, t_map *m, int j, int line_len)
{
	while (m->file[j])
	{
		m->file[j] = ft_clean_line(m->file[j]);
		line_len = ft_strlen(m->file[j]);
		if (!ft_strncmp(m->file[j], "NO", 2))
			m->no = ft_save_info(data, m->no, m->file[j], line_len);
		else if (!ft_strncmp(m->file[j], "SO", 2))
			m->so = ft_save_info(data, m->so, m->file[j], line_len);
		else if (!ft_strncmp(m->file[j], "WE", 2))
			m->we = ft_save_info(data, m->we, m->file[j], line_len);
		else if (!ft_strncmp(m->file[j], "EA", 2))
			m->ea = ft_save_info(data, m->ea, m->file[j], line_len);
		else if (!ft_strncmp(m->file[j], "F", 1))
			m->f = ft_get_fc(data, m->f, m->file[j], 'F');
		else if (!ft_strncmp(m->file[j], "C", 1))
			m->c = ft_get_fc(data, m->c, m->file[j], 'C');
		else if (!ft_is_valid_line(m->file[j]))
			return (0);
		j++;
		if (m->no && m->so && m->we && m->ea && m->f && m->c)
			break ;
	}
	if (!m->no || !m->so || !m->we || !m->ea || !m->f || !m->c)
		return (0);
	return (j);
}

void	ft_parse_info(t_data *data, t_map *m)
{
	int i;

	i = ft_find_info(data, m, 0, 0);
	if (i == 0)
		ft_error(data, "Couldn't find info/Wrong info");
	if (!ft_check_rgb(data, m))
		ft_error(data, "RGB format error");
	if (!ft_check_texts(data, m))
		ft_error(data, "Permission denied for textures");
	while (m->file[i] && m->file[i][0] && m->file[i][0] == '\n')
		i++;
	ft_find_map_limits(data, m, i);
	ft_get_map(data, m, &i, 0);
}
