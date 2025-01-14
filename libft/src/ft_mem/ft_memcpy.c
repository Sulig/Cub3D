/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:24:07 by sadoming          #+#    #+#             */
/*   Updated: 2024/03/25 12:25:34 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*des;
	char	*str;
	size_t	len;

	des = (char *) dst;
	str = (char *) src;
	len = 0;
	if (src == 0 && dst == 0)
		return (0);
	while (len < n)
	{
		des[len] = str[len];
		len++;
	}
	return (dst);
}
