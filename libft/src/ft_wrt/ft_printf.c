/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:01:07 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/01 18:26:24 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/write.h"

static int	ft_switch(char cast, va_list args)
{
	int		ret;

	ret = 0;
	if (cast == 'c')
		ret += ft_putchar(va_arg(args, int));
	else if (cast == 's')
		ret += ft_putstr(va_arg(args, char *));
	else if (cast == 'p')
		ret += ft_putunsig(va_arg(args, unsigned long), cast);
	else if (cast == 'd' || cast == 'i')
		ret += ft_putnbr(va_arg(args, int));
	else if (cast == 'u' || cast == 'x')
		ret += ft_putunsig(va_arg(args, unsigned int), cast);
	else if (cast == 'X')
		ret += ft_putunsig(va_arg(args, unsigned int), cast);
	else
		ret += ft_putchar(cast);
	return (ret);
}

int	ft_printf(char const *cast, ...)
{
	va_list	args;
	int		cnt;
	int		ret;

	va_start(args, cast);
	cnt = -1;
	ret = 0;
	while (cast[++cnt] && ret != -1)
	{
		if (cast[cnt] == '%')
			ret += ft_switch(cast[++cnt], args);
		else if (write(1, &cast[cnt], 1) != -1)
			ret++;
		else
			return (-1);
	}
	va_end(args);
	return (ret);
}
