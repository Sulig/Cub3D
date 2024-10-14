/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:29:11 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/14 12:38:20 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
 * Duplicates any pointer.
 * * Return NULL if !s1
 */
void	*ft_memdup(void *s1)
{
	char	*cpy;
	char	*sr;
	size_t	len;

	len = 0;
	sr = (char *)s1;
	if (!sr)
		return (NULL);
	while (sr[len])
		len++;
	cpy = malloc(len + 1);
	if (!cpy)
		return (NULL);
	len = 0;
	while (sr[len])
	{
		cpy[len] = sr[len];
		len++;
	}
	cpy[len] = '\0';
	return ((void *)cpy);
}
