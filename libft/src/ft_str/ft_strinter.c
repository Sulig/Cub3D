/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:29:20 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/05 20:12:28 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lenght.h"
#include "../../inc/memory.h"
#include "../../inc/string_utils.h"

static char	*ft_strfill(const char *str, char *to_fill, size_t pos)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < pos)
	{
		to_fill[cnt] = str[cnt];
		cnt++;
	}
	return (to_fill);
}

static char	*ft_strnext(const char *str, char *to_fill, size_t pos)
{
	size_t	cnt;

	cnt = 0;
	while (str[cnt])
	{
		to_fill[pos++] = str[cnt];
		cnt++;
	}
	return (to_fill);
}

/*
 * Pass the position of where you want to integrate
 * the inter in str.
 * Return the str + the inter in position of str
 * if str is NULL, return a strdup of inter
 * if inter is NULL, return a strdup of str
*/
char	*ft_strinter(char *str, char *inter, size_t pos)
{
	size_t	len_s;
	size_t	len_i;
	char	*join;

	len_s = ft_strlen(str);
	len_i = ft_strlen(inter);
	if (len_s == 0)
		return (ft_strdup(inter));
	if (len_i == 0)
		return (ft_strdup(str));
	join = ft_calloc(len_s + len_i + 1, sizeof(char));
	if (!join)
		return (NULL);
	join = ft_strfill(str, join, pos);
	join = ft_strnext(inter, join, pos);
	join = ft_strnext(str + pos, join, ft_strlen(join));
	return (join);
}
