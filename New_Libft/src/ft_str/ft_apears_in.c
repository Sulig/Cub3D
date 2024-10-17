/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apears_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:57:29 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/01 17:12:23 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
* How many times appears `ch` in `str`
*/
size_t	ft_chinstr(char *str, char ch)
{
	size_t	len;
	size_t	times_ap;

	len = 0;
	times_ap = 0;
	if (!str)
		return (0);
	while (str[len])
	{
		if (str[len] == ch)
			times_ap++;
		len++;
	}
	if (!times_ap && !str[len])
		return (1);
	return (times_ap);
}

/*
* How many times appears `needle` in `haystack`
*/
size_t	ft_strinstr(const char *haystack, const char *needle)
{
	size_t	cnt;
	size_t	cntn;
	size_t	times_ap;

	if (!haystack || !needle)
		return (0);
	cnt = 0;
	times_ap = 0;
	while (haystack[cnt] != '\0')
	{
		cntn = 0;
		while (haystack[cnt] == needle[cntn] && haystack[cnt])
		{
			++cnt;
			++cntn;
		}
		if (needle[cntn] == '\0')
			times_ap++;
		cnt = cnt - cntn + 1;
	}
	return (times_ap);
}
