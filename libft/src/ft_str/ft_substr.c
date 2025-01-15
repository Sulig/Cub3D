/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:52:22 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/15 20:26:36 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lenght.h"

/* Creates a new *char cuted by `start` and `len` */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	cnt;
	size_t	ln;
	char	*sub;

	ln = ft_strlen(s);
	if (start > ln)
		start = ln;
	if (len >= ft_strlen(s + start))
		len = ft_strlen(s) - start;
	sub = malloc(len + 1);
	if (sub == 0)
		return (0);
	cnt = 0;
	while (cnt < len && s[start])
	{
		sub[cnt] = s[start];
		start++;
		cnt++;
	}
	sub[cnt] = '\0';
	return (sub);
}

/* Creates a new *char cuted by `start` and `len` */
char	*my_substr(char *s, size_t start, size_t len)
{
	size_t	cnt;
	char	*sub;

	if (start >= ft_strlen(s))
		start = 0;
	if (len >= ft_strlen(s + start))
		len = ft_strlen(s) - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	cnt = 0;
	while (cnt < len && s[start])
	{
		sub[cnt] = s[start];
		start++;
		cnt++;
	}
	sub[cnt] = '\0';
	return (sub);
}
