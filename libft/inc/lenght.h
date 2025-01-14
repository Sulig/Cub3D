/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:16:34 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/14 13:47:15 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LENGHT_H
# define LENGHT_H

# include <stdlib.h>

/* LENGHT */
size_t	arrsize(void **s);
size_t	arrsize_str(char **s);

size_t	ft_cnttoch(const char *str, char c, int i);
size_t	ft_cnttoch_in(const char *str, char c);
size_t	ft_cnttoch_out(const char *str, char c);

size_t	ft_cnttostr(const char *haystack, const char *needle);
size_t	ft_cnttostr_end(const char *haystack, const char *needle);
size_t	ft_search_str(char **arr, char *to_search);

size_t	ft_numlen(size_t n, int base);

size_t	ft_strlen(const char *s);

#endif
