/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:06:57 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/14 13:46:56 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	arrsize(void **s)
{
	size_t	counter;
	char	**sr;

	counter = 0;
	if (!s)
		return (0);
	sr = (char **)s;
	while (sr[counter])
		counter++;
	return (counter);
}

size_t	arrsize_str(char **s)
{
	size_t	counter;

	counter = 0;
	if (!s)
		return (0);
	while (s[counter])
		counter++;
	return (counter);
}
