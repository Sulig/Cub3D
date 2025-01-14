/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:37:57 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/22 16:46:16 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	*ft_cpy(void *dst, const void *src, size_t n)
{
	char	*des;
	char	*str;
	size_t	len;

	des = (char *) dst;
	str = (char *) src;
	len = 0;
	while (len < n)
	{
		des[len] = str[len];
		len++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*str;
	unsigned char		*des;

	str = (const unsigned char *) src;
	des = (unsigned char *) dst;
	if (src == dst)
		return (dst);
	if (dst < src)
		return (ft_cpy(dst, src, len));
	while (len--)
		des[len] = str[len];
	return (dst);
}
