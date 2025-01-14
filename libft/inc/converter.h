/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:50:02 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/01 13:47:08 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# include <stdlib.h>

/* CONVERSIONS */
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
size_t	ft_atos(const char *str);

char	*ft_itoa(int n);
char	*ft_itoa_unsig(size_t n, char *base);
char	*ft_unsig_tobase(size_t num, char base);

int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_toupper_all(char *str);
char	*ft_tolower_all(char *str);
char	*ft_strcapitalize(char *str);

#endif
