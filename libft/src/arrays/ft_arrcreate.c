/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:03:48 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/15 20:07:02 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/arrays.h"
#include "../../inc/memory.h"

char	**ft_arr_strcreate(size_t heigth, size_t width)
{
	char	**new_arr;

	if (!heigth || !width)
		return (NULL);
	new_arr = ft_calloc(heigth, sizeof(char *));
	if (!new_arr)
		return (NULL);
	while (--heigth)
	{
		new_arr[heigth] = ft_calloc(width, sizeof(char));
		if (!new_arr)
		{
			new_arr = ft_free_arr (new_arr);
			return (NULL);
		}
	}
	return (new_arr);
}
