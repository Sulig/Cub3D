/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:42:13 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/14 12:33:09 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

void	donothing(void *ptr);

/* MEMORY */
void	*ft_free_ptr(void *ptr);
void	*ft_free_arr(void **arr);

void	*ft_free_str(char *str);
void	*ft_free_arrstr(char **arr);

void	*ft_calloc(size_t count, size_t size);

void	*ft_memdup(void *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_bzero(void *s, size_t n);

#endif
