/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:52:24 by sadoming          #+#    #+#             */
/*   Updated: 2024/04/10 19:22:24 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_H
# define WRITE_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/* PRINT && WRITE */
int		ft_putchar(char ch);
int		ft_putnbr(int nbr);
int		ft_putstr(char *str);
int		ft_putendl(char *s);
int		ft_putunsig(size_t nbr, char cast);
int		ft_printf(char const *str, ...);

int		ft_putchar_fd(char ch, int fd);
int		ft_putnbr_fd(int nbr, int fd);
int		ft_putstr_fd(char *str, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putunsig_fd(size_t nbr, char cast, int fd);
int		ft_printf_fd(int fd, char const *str, ...);

#endif
