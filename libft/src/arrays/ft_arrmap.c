/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:58:35 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/14 16:53:54 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/arrays.h"
#include "../../inc/memory.h"

/*
 * Make a copy of org
 * *Return NULL if !org || !size of org
 */
void	**arrmap(void **org)
{
	char	**copy;
	size_t	cnt;

	cnt = 0;
	if (!org || !arrsize(org))
		return (NULL);
	copy = ft_calloc(sizeof(char *), arrsize(org) + 1);
	if (!copy)
		return (NULL);
	while (org[cnt])
	{
		copy[cnt] = ft_memdup(org[cnt]);
		cnt++;
	}
	return ((void **)copy);
}
