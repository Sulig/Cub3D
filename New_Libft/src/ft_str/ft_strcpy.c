/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:07:49 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/14 13:47:03 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lenght.h"
#include "../../inc/memory.h"

/*
* Duplicates the *char
*/
char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	len;

	len = ft_strlen(s1);
	if (!len)
		return (NULL);
	cpy = malloc(len + 1);
	if (!cpy)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		cpy[len] = s1[len];
		len++;
	}
	cpy[len] = '\0';
	return (cpy);
}

/*
* Remplace the `dst`for `str`
* This will free `dst`
* * if `str` is NULL, return NULL
*/
char	*ft_strremplace(char *dst, const char *str)
{
	dst = ft_free_str(dst);
	if (!ft_strlen(str))
		return (NULL);
	dst = ft_strdup(str);
	return (dst);
}

/*
* Duplicates the *char to `len`
*/
char	*ft_strcpyl(const char *s1, size_t len)
{
	char	*cpy;
	size_t	cnt;

	if (!s1 || len <= 0)
		return (NULL);
	cpy = malloc(len + 1);
	if (!cpy)
		return (NULL);
	cnt = 0;
	while (cnt < len)
	{
		cpy[cnt] = s1[cnt];
		cnt++;
	}
	cpy[len] = '\0';
	return (cpy);
}

/*
* Duplicates an array of *char
*/
char	**ft_strarrdup(char **to_copy)
{
	char	**copy;
	size_t	cnt;

	cnt = 0;
	copy = ft_calloc(sizeof(char *), arrsize_str(to_copy) + 1);
	if (!copy)
		return (NULL);
	if (to_copy)
	{
		while (to_copy[cnt])
		{
			copy[cnt] = ft_strdup(to_copy[cnt]);
			cnt++;
		}
	}
	return (copy);
}
