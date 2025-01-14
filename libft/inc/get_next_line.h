/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:00:27 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/01 13:12:07 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

int		gnl_contains(const char *str, char in);
size_t	gnl_strlen(const char *s);
size_t	gnl_cnt_tojump(const char *str);
char	*gnl_free(char *to_free, char *tmp);
char	*gnl_strlcpy(const char *s1, size_t len);
char	*gnl_join(char *s1, const char *s2);
char	*gnl_strcut(char *str);
char	*ft_get_readed(int fd, char *store);

char	*get_next_line(int fd);

#endif
