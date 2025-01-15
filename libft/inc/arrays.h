/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:09:37 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/15 20:07:23 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYS_H
# define ARRAYS_H

# include <stdlib.h>

/* ARRAYS */
size_t	arrsize(void **s);
size_t	arrsize_str(char **s);

void	**arrdup(void **org);
void	**arrpop(void **org, size_t pop);
void	**arrpush(void **org, void *add);

char	**ft_arr_strcreate(size_t heigth, size_t width);
char	**ft_strarrdup(char **to_copy);

#endif
