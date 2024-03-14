/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:00:11 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/03/05 22:17:43 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*node;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		node = (*lst)->next;
		free(*lst);
		*lst = node;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	last = ft_lstlast(*lst);
	if (last != NULL)
		last->next = new;
	else
		*lst = new;
}

t_list	*ft_lstnew(int data)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->data = data;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
