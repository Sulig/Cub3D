/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:15:53 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/01 16:19:18 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	if (!s || s == NULL)
		return (0);
	while (s[counter])
		counter++;
	return (counter);
}

/*
*	Counts the chars to reach `c`
*	* if `i` is 1 -> include char `c` into count
*	* if `i` is 0 -> do not include char `c` into count
*/
size_t	ft_cnttoch(const char *str, char c, int i)
{
	size_t	cnt;

	cnt = 0;
	if (!str)
		return (0);
	while (str[cnt] && str[cnt] != c)
		cnt++;
	if (str[cnt] == c && i)
		cnt++;
	return (cnt);
}

/*
*	Counts the chars to reach `c` and include char `c` into count
*/
size_t	ft_cnttoch_in(const char *str, char c)
{
	size_t	cnt;

	cnt = 0;
	if (!str)
		return (0);
	while (str[cnt] && str[cnt] != c)
		cnt++;
	if (str[cnt] == c)
		cnt++;
	return (cnt);
}

/*
*	Counts the chars to reach `c` and do not include char `c` into count
*/
size_t	ft_cnttoch_out(const char *str, char c)
{
	size_t	cnt;

	cnt = 0;
	if (!str)
		return (0);
	while (str[cnt] && str[cnt] != c)
		cnt++;
	return (cnt);
}
