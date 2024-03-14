/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:00:16 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/03/10 19:44:00 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*list_befor_last(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next->next)
		list = list->next;
	return (list);
}

void	swap(t_list **list, char *instruction)
{
	int		i;
	t_list	*tmp;
	t_list	*tmp1;

	i = 0;
	if (!list || !(*list) || !(*list)->next)
		return ;
	tmp = *list;
	tmp1 = (*list)->next;
	tmp->next = tmp1->next;
	tmp1->next = tmp;
	*list = tmp1;
	if (instruction == NULL)
		return ;
	while (instruction[i])
	{
		write(1, &instruction[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	push(t_list **list, t_list **list1, char *instruction)
{
	int		i;
	t_list	*tmp;

	i = 0;
	if (!list || !(*list) || !list1 || !instruction)
		return ;
	tmp = *list;
	*list = (*list)->next;
	tmp->next = *list1;
	*list1 = tmp;
	while (instruction[i])
	{
		write(1, &instruction[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	rotate(t_list **list, char *instruction)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (!list || !(*list) || !(*list)->next)
		return ;
	tmp = *list;
	*list = (*list)->next;
	tmp->next = NULL;
	ft_lstadd_back(list, tmp);
	if (instruction == NULL)
		return ;
	while (instruction[i])
	{
		write(1, &instruction[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	reverse_rotate(t_list **list, char *instruction)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (!list || !(*list) || !(*list)->next)
		return ;
	tmp = list_befor_last(*list);
	ft_lstadd_front(list, tmp->next);
	tmp->next = NULL;
	if (instruction == NULL)
		return ;
	while (instruction[i])
	{
		write(1, &instruction[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
