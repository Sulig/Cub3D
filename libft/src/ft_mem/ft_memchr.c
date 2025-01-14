/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:30:31 by sadoming          #+#    #+#             */
/*   Updated: 2024/02/22 16:44:59 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			pos;

	str = (unsigned char *) s;
	pos = 0;
	if (n == 0)
		return (0);
	while (pos < n -1)
	{
		if (str[pos] == (unsigned char)c)
			return (str + pos);
		pos++;
	}
	if (str[pos] == (unsigned char) c)
		return (str + pos);
	else
		return (0);
}
