/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:00:16 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/03/06 10:35:01 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*list_befor_last(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next->next)
		list = list->next;
	return (list);
}

void	swap(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp1;

	if (!list || !(*list) || !(*list)->next)
		return ;
	tmp = *list;
	tmp1 = (*list)->next;
	tmp->next = tmp1->next;
	tmp1->next = tmp;
	*list = tmp1;
}

void	push(t_list **list, t_list **list1)
{
	t_list	*tmp;

	if (!list || !(*list) || !list1)
		return ;
	tmp = *list;
	*list = (*list)->next;
	tmp->next = *list1;
	*list1 = tmp;
}

void	rotate(t_list **list)
{
	t_list	*tmp;

	if (!list || !(*list) || !(*list)->next)
		return ;
	tmp = *list;
	*list = (*list)->next;
	tmp->next = NULL;
	ft_lstadd_back(list, tmp);
}

void	reverse_rotate(t_list **list)
{
	t_list	*tmp;

	if (!list || !(*list) || !(*list)->next)
		return ;
	tmp = list_befor_last(*list);
	ft_lstadd_front(list, tmp->next);
	tmp->next = NULL;
}
