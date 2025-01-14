/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:57:36 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/01 17:05:12 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/searchers.h"

/*
 * Search where ocours needle in haystack
 * if !needle -> return the haystack
 * if coincidence, return where are the first char
 * if no coincidence, return  NULL
*/
char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	cnt;
	size_t	cntn;

	if (!needle)
		return ((char *) haystack);
	if (!haystack)
		return (NULL);
	cnt = 0;
	while (haystack[cnt] != '\0')
	{
		cntn = 0;
		while (haystack[cnt] == needle[cntn] && haystack[cnt])
		{
			++cnt;
			++cntn;
		}
		if (needle[cntn] == '\0')
			return ((char *) haystack + (cnt - cntn));
		cnt = cnt - cntn + 1;
	}
	return (NULL);
}

/*
 * Search where ocours needle in haystack in no more than X len
 * if !needle -> return the haystack
 * if coincidence, return where are the first char
 * if no coincidence, return  NULL
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cnt;
	size_t	cntn;

	if (needle[0] == 0 || haystack == needle)
		return ((char *) haystack);
	cnt = 0;
	while (cnt < len && haystack[cnt] != '\0')
	{
		cntn = 0;
		while (cnt < len && haystack[cnt] == needle[cntn] && haystack[cnt])
		{
			++cnt;
			++cntn;
		}
		if (needle[cntn] == '\0')
			return ((char *) haystack + (cnt - cntn));
		cnt = cnt - cntn + 1;
	}
	return (NULL);
}

/*
 * Search where ocours to_search in arr
 * if !to_search || !arr -> return 0
 * if coincidence, return the arr pos on encountered
 * if no coincidence, return arr len
*/
size_t	ft_search_str(char **arr, char *to_search)
{
	size_t	i;

	i = 0;
	if (!arr || !to_search)
		return (0);
	while (arr[i] && !ft_strstr(arr[i], to_search))
		i++;
	return (i);
}
