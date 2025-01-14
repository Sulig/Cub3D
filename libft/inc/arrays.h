/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:09:37 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/14 13:47:15 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYS_H
# define ARRAYS_H

# include <stdlib.h>

/* ARRAYS */
size_t	arrsize(void **s);
size_t	arrsize_str(char **s);

void	**arrmap(void **org);
void	**arrpop(void **org, size_t pop);
void	**arrpush(void **org, void *add);

char	**ft_strarrdup(char **to_copy);

#endif
