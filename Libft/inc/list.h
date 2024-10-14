/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:19:16 by sadoming          #+#    #+#             */
/*   Updated: 2024/07/03 17:16:22 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct s_list
{
	size_t			pos;
	void			*content;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

/* LIST UTILS */
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
size_t	ft_lstsize(t_list *lst);
size_t	ft_lstpos_node(t_list *lst, t_list *node);
t_list	*ft_lstgetnode(t_list *lst, size_t pos);
t_list	*ft_search_nodebypos(t_list *lst, size_t pos);
t_list	*ft_asign_nodepos(t_list *lst);

#endif
