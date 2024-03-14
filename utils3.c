/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:31 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/03/10 18:33:40 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sort(t_list *a)
{
	while (a->next != NULL)
	{
		if ((a->index) > (a->next->index))
			return (0);
		a = a->next;
	}
	return (1);
}

int	were_is_max(t_list **list, int start, int end, int max)
{
	int		i;
	t_list	*tmp;

	tmp = *list;
	i = 0;
	while (i < start)
	{
		tmp = tmp->next;
		i++;
	}
	while (i <= end)
	{
		if (tmp->index == max)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	free_all_nbr(char **all_nbr)
{
	int	i;

	i = 0;
	if (!all_nbr)
		return ;
	while (all_nbr[i] != NULL)
	{
		free(all_nbr[i]);
		i++;
	}
	free(all_nbr);
}

void	if_fail(char **arg)
{
	if (!arg)
		exit(11);
}

void	if_fail1(char *str)
{
	if (!str)
		exit(12);
}
