/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:15:44 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/03/11 15:15:02 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **a)
{
	if ((*a)->index == 2)
		rotate(a, "ra");
	else if ((*a)->next->index == 2)
		reverse_rotate(a, "rra");
	if ((*a)->index > (*a)->next->index)
		swap(a, "sa");
}

void	sort_four(t_list **a)
{
	t_list	*b;

	b = NULL;
	if ((*a)->next->next->next->index == 3)
		reverse_rotate(a, "rra");
	else if ((*a)->next->next->index == 3)
	{
		rotate(a, "ra");
		rotate(a, "ra");
	}
	else if ((*a)->next->index == 3)
		rotate(a, "ra");
	push(a, &b, "pb");
	sort_three(a);
	push(&b, a, "pa");
	rotate(a, "ra");
}

void	sort_five(t_list **a)
{
	t_list	*b;

	b = NULL;
	if ((*a)->next->next->next->next->index == 4)
		reverse_rotate(a, "rra");
	else if ((*a)->next->next->next->index == 4)
	{
		reverse_rotate(a, "rra");
		reverse_rotate(a, "rra");
	}
	else if ((*a)->next->next->index == 4)
	{
		rotate(a, "ra");
		rotate(a, "ra");
	}
	else if ((*a)->next->index == 4)
		rotate(a, "ra");
	push(a, &b, "pb");
	sort_four(a);
	push(&b, a, "pa");
	rotate(a, "ra");
}
