/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:12:32 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/01 17:23:58 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lenght.h"

/*
 * Cut the str on char cut.
 * Modes ->
 *		in mode '<', cut [0] to [cut]
 *		in mode '>', cut [cut] to [len of str]
 *
 * Exclude ->
 *		if 'y' || 'Y' exclude the cut char ([X] to [cut + 1])
 *		else, include the cut char on the str ([X] to [cut])
*/
char	*ft_strcut(char *str, char cut, char mode, char exc)
{
	if (!str)
		return (NULL);
	if (mode == '<')
	{
		if (exc == 'y' || exc == 'Y')
			str[ft_cnttoch_out(str, cut)] = '\0';
		else
			str[ft_cnttoch_in(str, cut)] = '\0';
	}
	else if (mode == '>')
	{
		if (exc == 'y' || exc == 'Y')
			return (str + ft_cnttoch_in(str, cut));
		else
			return (str + ft_cnttoch_out(str, cut));
	}
	return (str);
}
