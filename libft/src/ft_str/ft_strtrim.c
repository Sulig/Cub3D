/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:16:49 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/01 17:03:05 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lenght.h"
#include "../../inc/memory.h"
#include "../../inc/searchers.h"
#include "../../inc/string_utils.h"

/*
 * Trim the `*set` off of `*s1`
 * Returns a new str with the result
 * if !s1 || s1 == "" -> return NULL
 * if !set || set == "" -> return a duplicate of s1
*/
char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	ln;
	size_t	cnt;

	if (!ft_strlen(s1))
		return (NULL);
	if (!ft_strlen(set))
		return (ft_substr(s1, 0, ft_strlen(s1)));
	ln = 0;
	while (s1[ln])
	{
		if (!ft_strchr(set, s1[ln]))
			break ;
		ln++;
	}
	cnt = ft_strlen(s1);
	while (--cnt)
		if (!ft_strchr(set, s1[cnt]))
			break ;
	return (ft_substr(s1, ln, (cnt - ln) + 1));
}

static char	*trim_inside(char *input, size_t start, size_t end)
{
	char	*cut_st;
	char	*cut_ed;
	char	*result;

	result = NULL;
	cut_st = ft_strcpyl(input, start);
	cut_ed = ft_strdup(input + end);
	result = ft_strjoin(cut_st, cut_ed);
	if (!ft_strlen(result))
		result = ft_free_str(result);
	cut_st = ft_free_str(cut_st);
	cut_ed = ft_free_str(cut_ed);
	input = ft_free_str(input);
	return (result);
}

/*
 * Trim the extra char `trim` inside the input
*/
char	*ft_strtrim_inside(char *input, char trim)
{
	size_t	i;
	size_t	pos;
	char	*result;

	i = 0;
	if (!ft_strlen(input))
		return (NULL);
	result = ft_strdup(input);
	while (result[i])
	{
		if (result[i] == trim)
		{
			pos = i;
			while (result[i] && result[i] == trim)
				i++;
			result = trim_inside(result, pos, i);
			i = 0;
		}
		i++;
	}
	return (ft_strdup(result));
}
