/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:42:13 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/28 13:20:11 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/arrays.h"
#include "../../inc/memory.h"

/* Pop an element from an array
 * - Return a new array without the element
 * ** Free the original if !size || size >= arrsize(org)
 * *** `size` is the size of the new array
 * *** (If size is 0, the array will be freed)
 * ** Return Original if pop >= arrsize(org)
 * *** `pop` is the index of the element to pop
 * ** Return NULL if !new_arr (Memory Allocation Error)
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
	if (!size || size >= arrsize(org))
	{
		org = ft_free_arr(org);
		return (NULL);
	}
	if (pop >= arrsize(org))
		return (org);
	new_arr = ft_calloc(sizeof(char *), size + 1);
	if (!new_arr)
		return (NULL);
	while (org[++i])
		if (i != pop)
			new_arr[j++] = ft_memdup(org[i]);
	org = ft_free_arr(org);
	return ((void **)new_arr);
}
