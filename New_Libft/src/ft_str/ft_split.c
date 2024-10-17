/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:30:58 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/14 13:49:10 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lenght.h"
#include "../../inc/memory.h"
#include "../../inc/string_utils.h"

static void	*ft_free_split(size_t size, char **words)
{
	while (size--)
		free(words[size]);
	free(words);
	words = NULL;
	return (NULL);
}

static size_t	ft_words(const char *s, char c)
{
	int		cnt;
	size_t	words;

	cnt = 0;
	words = 0;
	while (s[cnt])
	{
		if (s[cnt] != c)
			if (s[cnt + 1] == c || s[cnt + 1] == '\0')
				words++;
		cnt++;
	}
	return (words);
}

static char	**ft_sep(const char *s, char c, char **words)
{
	int		cnt;
	int		ln;
	size_t	sep;

	cnt = 0;
	sep = 0;
	while (s[cnt])
	{
		if (s[cnt] != c)
		{
			ln = 0;
			while (s[cnt] != c && s[cnt])
			{
				++cnt;
				ln++;
			}
			words[sep++] = ft_substr(s, cnt - ln, ln);
			if (words[sep -1] == NULL)
				return (NULL);
			cnt--;
		}
		cnt++;
	}
	return (words);
}

/*
* Creates an array of *char with `c`into `s`
* The more `c` in `s`, more positions into array
* Ej: "Hello world, it's me" -> [Hello][world,][it's][me]
*/
char	**ft_split(const char *s, char c)
{
	char	**words;

	words = ft_calloc(ft_words(s, c) + 1, sizeof(char *));
	if (!s || !words)
		return (NULL);
	if (ft_sep(s, c, words) == 0)
		return (ft_free_split(ft_words(s, c), words));
	return (words);
}
