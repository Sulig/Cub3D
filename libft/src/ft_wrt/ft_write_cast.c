/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_cast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:55:45 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/01 18:26:24 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/converter.h"
#include "../../inc/write.h"

int	ft_putchar(char ch)
{
	int	ret;

	ret = write(1, &ch, 1);
	return (ret);
}

int	ft_putstr(char *str)
{
	int		ret;
	int		cnt;

	ret = 0;
	cnt = -1;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[++cnt])
	{
		if (write(1, &str[cnt], 1) == -1)
			return (-1);
		ret++;
	}
	return (ret);
}

int	ft_putendl(char *s)
{
	int		len;

	len = 0;
	while (s[len])
	{
		if (write(1, &s[len], 1) == -1)
			return (-1);
		len++;
	}
	if (write(1, "\n", 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_putnbr(int nbr)
{
	char	*str;
	int		ret;

	str = ft_itoa(nbr);
	ret = ft_putstr(str);
	free(str);
	return (ret);
}

int	ft_putunsig(size_t nbr, char cast)
{
	char	*str;
	int		ret;
	int		save;

	save = 0;
	if (cast == 'p')
		save = ft_putstr("0x");
	if (save == -1)
		return (save);
	str = ft_unsig_tobase(nbr, cast);
	ret = ft_putstr(str);
	free(str);
	if (ret == -1)
		return (ret);
	return (ret + save);
}
