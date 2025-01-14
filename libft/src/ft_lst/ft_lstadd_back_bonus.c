/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:35:01 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/01 18:42:09 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_d;
	t_list	*last;
	t_list	*prev;
	size_t	i;

	i = 0;
	last = ft_lstlast(*lst);
	if (last == NULL && new)
		*lst = new;
	if (last && new)
		last->next = new;
	lst_d = *lst;
	last = *lst;
	while (i < ft_lstsize(lst_d))
	{
		last->pos = i;
		if (i > 0)
		{
			prev = ft_lstgetnode(*lst, i - 1);
			last->prev = prev;
		}
		i++;
		last = last->next;
	}
	*lst = lst_d;
}
