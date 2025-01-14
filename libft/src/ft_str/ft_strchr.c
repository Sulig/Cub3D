/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:40:59 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/01 16:36:40 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
 * Search the first ocurrence of c in s.
 * Return the s + the pos where encountered the c
 * Or NULL if not.
*/
char	*ft_strchr(const char *s, int c)
{
	int		len;
	int		pos;

	len = 0;
	if (!s)
		return (NULL);
	while (s[len])
		len++;
	pos = 0;
	while (pos <= len)
	{
		if ((unsigned char) s[pos] == (unsigned char) c)
			return ((char *) s + pos);
		pos++;
	}
	return (NULL);
}

/*
 * Search the last ocurrence of c in s.
 * Return the s + the pos where encountered the last c
 * Or NULL if not.
*/
char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = 0;
	if (!s)
		return (NULL);
	while (s[len] != '\0')
		len++;
	while (len >= 0)
	{
		if ((unsigned char) s[len] == (unsigned char) c)
			return ((char *) s + len);
		len--;
	}
	return (NULL);
}

/*
 * Search where ocours needle in haystack, search on start to end
 * Example: "hi 0 len 0" "0" -> 3
 * if !haystack || !needle -> return 0
*/
size_t	ft_cnttostr(const char *haystack, const char *needle)
{
	size_t	cnt;
	size_t	cntn;

	if (!haystack || !needle)
		return (0);
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
			return (cnt - cntn);
		cnt = cnt - cntn + 1;
	}
	return (cnt);
}

static long	ft_strlen(const char *str)
{
	long	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

/*
 * Search where ocours needle in haystack, search on end to start
 * Example: "hi 0 len 0" "0" -> 9
 * if !haystack || !needle -> return 0
*/
size_t	ft_cnttostr_end(const char *haystack, const char *needle)
{
	long	cnt;
	size_t	cntn;

	if (!haystack || !needle)
		return (0);
	cnt = ft_strlen(haystack) - 1;
	while (cnt >= 0)
	{
		cntn = 0;
		while (haystack[cnt] == needle[cntn] && haystack[cnt])
		{
			++cnt;
			++cntn;
		}
		if (needle[cntn] == '\0')
			return (cnt - cntn);
		cnt = cnt - cntn - 1;
	}
	return (cnt);
}
