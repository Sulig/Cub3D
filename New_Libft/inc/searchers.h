/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchers.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:35:51 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/01 17:55:56 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHERS_H
# define SEARCHERS_H

/* SEARCHERS */
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

size_t	ft_cnttostr(const char *haystack, const char *needle);
size_t	ft_cnttostr_end(const char *haystack, const char *needle);
size_t	ft_search_str(char **arr, char *to_search);

size_t	ft_chinstr(char *str, char ch);
size_t	ft_strinstr(const char *haystack, const char *needle);

#endif
