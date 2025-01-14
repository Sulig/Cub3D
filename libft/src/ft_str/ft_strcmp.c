/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:45:32 by sadoming          #+#    #+#             */
/*   Updated: 2024/04/02 16:52:40 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

/*
 * Compares str & cmp
 * If str reach '\0' => Then cmp is identicall to str
 * Return 0 when encounters a diference
*/
int	my_strcmp(const char *str, const char *cmp)
{
	size_t	cnt;

	cnt = 0;
	if (!str)
	{
		if (!cmp)
			return (1);
		return (0);
	}
	if (ft_strlen((char *)str) != ft_strlen((char *)cmp))
		return (0);
	while (str[cnt])
	{
		if (str[cnt] != cmp[cnt])
			return (0);
		cnt++;
	}
	return (1);
}

/*
 * Compares s1 & s2.
 * Return the diference of ascii char
 * Exemple: if s1 == s2 => 0
 * if s1[0] = 0 & s2[0] = 1 => -1 
*/
int	ft_strcmp(const char *s1, const char *s2)
{
	int		ascii;
	int		counter;

	ascii = 0;
	counter = 0;
	if (s1 == s2)
		return (ascii);
	while (s1[counter] == s2[counter])
		counter++;
	ascii = s1[counter] - s2[counter];
	return (ascii);
}

/*
 * Compares s1 & s2 no more long than n.
 * If diference ocour before n, return (s1[cnt] - s2[cnt])
 * If no diference ocour before n, return (s1[n] - s2[n]);
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	counter;
	int				ascii;

	ascii = 0;
	counter = 0;
	if (n > 0)
	{
		n--;
		while (counter < n && (s1[counter] == s2[counter]))
		{
			if (s1[counter] == '\0' && s2[counter] == '\0')
				break ;
			counter++;
		}
		ascii = s1[counter] - s2[counter];
	}
	if (s1[counter] < 0 || s2[counter] < 0)
		return (ascii * -1);
	else
		return (ascii);
}
