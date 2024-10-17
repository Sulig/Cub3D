/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnodepos_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:50:04 by sadoming          #+#    #+#             */
/*   Updated: 2024/10/01 18:42:09 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

/*
* Get the position of node respect to the list
*/
size_t	ft_lstpos_node(t_list *lst, t_list *node)
{
	size_t	pos;

	pos = 0;
	if (!lst)
		return (0);
	if (!node)
		return (ft_lstsize(lst));
	while (lst)
	{
		if (node == lst)
			return (pos);
		lst = lst->next;
		pos++;
	}
	return (pos);
}

/*
* Get the node in position X
* node1 -> node2 -> node3 (2) -> node2
* * This function will return NULL if pos is > of lstsize
* * If you want to search an especific node->pos
* *	use -> t_list	*ft_search_nodebypos(t_list *lst, size_t pos)
*/
t_list	*ft_lstgetnode(t_list *lst, size_t pos)
{
	size_t	i;

	i = 0;
	if (!lst)
		return (NULL);
	while (i < pos)
	{
		if (lst)
			lst = lst->next;
		i++;
	}
	return (lst);
}

/*
* Search a node with the same pos as indicated,
* No matter if pos is 0 || < of node
* * If pos is > of lstsize it will return NULL
* * If the pos is the same as the lst->pos, it will return lst
*/
t_list	*ft_search_nodebypos(t_list *lst, size_t pos)
{
	if (!lst)
		return (NULL);
	else if (pos < lst->pos)
	{
		while (lst)
		{
			if (lst)
				if (lst->pos == pos)
					return (lst);
			lst = lst->prev;
		}
		return (lst);
	}
	else if (pos > lst->pos)
	{
		while (lst)
		{
			if (lst)
				if (lst->pos == pos)
					return (lst);
			lst = lst->next;
		}
		return (lst);
	}
	return (lst);
}

/*
* Asing the position of each node in list
*/
t_list	*ft_asign_nodepos(t_list *lst)
{
	t_list	*first;
	size_t	pos;

	first = lst;
	pos = 0;
	while (lst)
	{
		lst->pos = pos;
		lst = lst->next;
		pos++;
	}
	return (first);
}
