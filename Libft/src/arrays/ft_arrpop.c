/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:42:13 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/14 13:47:11 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/arrays.h"
#include "../../inc/memory.h"

/*
 * Pop `add` into a new array (on last position)
 * And free the original array.
 * *Free the original if !size || pop >= size of org
 */
void	**arrpop(void **org, size_t pop)
{
	char	**new_arr;
	size_t	size;
	size_t	i;
	size_t	j;

	j = 0;
	i = -1;
	new_arr = NULL;
	size = arrsize(org) - 1;
	if (!size || pop >= arrsize(org))
	{
		org = ft_free_arr(org);
		return (NULL);
	}
	new_arr = ft_calloc(sizeof(char *), size + 1);
	if (!new_arr)
		return (NULL);
	while (org[++i])
		if (i != pop)
			new_arr[j++] = ft_memdup(org[i]);
	org = ft_free_arr(org);
	return ((void **)new_arr);
}
