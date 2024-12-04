/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:12:11 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/04 20:26:15 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game.h"

int	check_format(char *file)
{
	char	*format;

	if (open(file, O_RDONLY) == -1)
		print_err_arfor(2);
	format = ft_strstr(file, ".cub");
	if (!format)
		print_err_arfor(1);
	format = NULL;
	return (1);
}
