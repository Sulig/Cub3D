/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:30:11 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/14 13:48:11 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/arrays.h"

/*
*	Does this change *ptr into NULL?
*/
void	donothing(void *ptr)
{
	if (ptr)
		ptr = NULL;
}

void	*ft_free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
	return (NULL);
}

void	*ft_free_arr(void **arr)
{
	size_t	size;

	size = arrsize(arr);
	if (size)
		while (size--)
			arr[size] = ft_free_ptr(arr[size]);
	if (arr)
		free(arr);
	arr = NULL;
	return (NULL);
}

void	*ft_free_str(char *str)
{
	if (str)
		free(str);
	str = NULL;
	return (NULL);
}

void	*ft_free_arrstr(char **arr)
{
	size_t	size;

	size = arrsize_str(arr);
	if (size)
		while (size--)
			arr[size] = ft_free_str(arr[size]);
	if (arr)
		free(arr);
	arr = NULL;
	return (NULL);
}
