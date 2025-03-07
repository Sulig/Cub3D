/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:55:30 by sadoming          #+#    #+#             */
/*   Updated: 2024/12/05 16:59:00 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/arrays.h"
#include "../../inc/memory.h"

/*
 * Push `add` into a new array (on last position)
 * And free the original array.
 * - Return org if !add
 * - If !size, push add into a new array (size 1)
 */
void	**arrpush(void **org, void *add)
{
	char	**new_arr;
	size_t	size;
	size_t	i;

	i = -1;
	new_arr = NULL;
	size = arrsize(org);
	if (!add)
		return (org);
	new_arr = ft_calloc(sizeof(char *), size + 2);
	if (!new_arr)
		return (NULL);
	while (++i < size)
		new_arr[i] = ft_memdup(org[i]);
	new_arr[i] = ft_memdup(add);
	org = ft_free_arr(org);
	return ((void **)new_arr);
}
