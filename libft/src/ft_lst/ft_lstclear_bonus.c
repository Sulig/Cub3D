/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:40:50 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/01 18:42:09 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

static void	ft_nexttonull(t_list *tonull, int cnt)
{
	while (cnt > 1)
	{
		tonull = tonull->next;
		cnt--;
	}
	tonull->next = NULL;
	tonull->prev = NULL;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	int		cnt;
	t_list	*t_free;

	cnt = ft_lstsize(*lst);
	while (cnt > 0)
	{
		t_free = *lst;
		ft_nexttonull(t_free, cnt);
		t_free = ft_lstlast(t_free);
		if (t_free->content)
			(*del)(t_free->content);
		t_free->content = NULL;
		free(t_free);
		cnt--;
	}
	*lst = NULL;
}
