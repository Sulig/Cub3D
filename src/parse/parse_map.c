int     ft_check_map_chars(t_map *m, int i, int j, int *player)
{
    if (m->map[i][j] != ' ' && m->map[i][j] != '0' && m->map[i][j] != '1'
		&& m->map[i][j] != 'N' && m->map[i][j] != 'S'
		&& m->map[i][j] != 'W' && m->map[i][j] != 'E')
		return (0);
	if (m->map[i][j] == 'N' || m->map[i][j] == 'S' || m->map[i][j] == 'W'
		|| m->map[i][j] == 'E')
	{
		if (*player == 1)
			return (0);
		*player = 1;
		ft_init_player_pos(m->p, j, i, m->map[i][j]);
	}
	return (1);
}

void    ft_check_valid_map(t_data *data, t_map *m, int i, int j)
{
    int player;

    player = 0;
    while (i < m->height)
    {
        j = 0;
        while (j < m->width)
        {
            if (m->map[i][j] == ' ')
            {
                if (!ft_check_map_spaces(m, i, j))
                    ft_error(data, "Invalid map");
            }
            if (!ft_check_map_chars(m, i, j, &player))
                ft_error(data, "Invalid map");
            j++;
        }
        i++;
    }
    if (player == 0)
        ft_error(data, "No player detected");
}