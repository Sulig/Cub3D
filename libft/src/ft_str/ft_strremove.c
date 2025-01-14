/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:17:11 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/14 13:50:32 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/lenght.h"
#include "../../inc/searchers.h"
#include "../../inc/string_utils.h"
#include "../../inc/memory.h"

char	*ft_strremove(char *str, const char *rem)
{
	char	*result;
	char	*start;
	char	*end;
	size_t	pos;

	if (!str)
		return (NULL);
	if (!rem || !ft_strstr(str, rem))
		return (str);
	if (my_strcmp(str, rem))
	{
		str = ft_free_str(str);
		return (NULL);
	}
	pos = ft_cnttostr(str, rem);
	start = ft_substr(str, 0, pos);
	end = str + pos + ft_strlen(rem);
	result = ft_strjoin(start, end);
	start = ft_free_str(start);
	end = NULL;
	str = ft_free_str(str);
	if (!ft_strstr(result, rem))
		return (result);
	return (ft_strremove(result, rem));
}
