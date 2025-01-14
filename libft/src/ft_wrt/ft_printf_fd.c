/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:27:49 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/01 18:27:09 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/write.h"

static int	ft_switch_fd(int fd, char cast, va_list args)
{
	int		ret;

	ret = 0;
	if (cast == 'c')
		ret += ft_putchar_fd(va_arg(args, int), fd);
	else if (cast == 's')
		ret += ft_putstr_fd(va_arg(args, char *), fd);
	else if (cast == 'p')
		ret += ft_putunsig_fd(va_arg(args, unsigned long), cast, fd);
	else if (cast == 'd' || cast == 'i')
		ret += ft_putnbr_fd(va_arg(args, int), fd);
	else if (cast == 'u' || cast == 'x')
		ret += ft_putunsig_fd(va_arg(args, unsigned int), cast, fd);
	else if (cast == 'X')
		ret += ft_putunsig_fd(va_arg(args, unsigned int), cast, fd);
	else
		ret += ft_putchar_fd(cast, fd);
	return (ret);
}

/*
* Writes anything into a file descriptor
*/
int	ft_printf_fd(int fd, char const *cast, ...)
{
	va_list	args;
	int		cnt;
	int		ret;

	va_start(args, cast);
	cnt = -1;
	ret = 0;
	if (fd >= 0)
	{
		while (cast[++cnt] && ret != -1)
		{
			if (cast[cnt] == '%')
				ret += ft_switch_fd(fd, cast[++cnt], args);
			else if (write(fd, &cast[cnt], 1) != -1)
				ret++;
			else
				return (-1);
		}
	}
	va_end(args);
	return (ret);
}
