/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:53:46 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/03/13 00:29:23 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action_case(t_list **b, int max, int i)
{
	if (i == 1)
	{
		while ((*b)->index != max)
		{
			if ((*b)->next->index == max)
				swap(b, "sb");
			else
				rotate(b, "rb");
		}
	}
	else if (i == 2)
	{
		while ((*b)->index != max)
			reverse_rotate(b, "rrb");
	}
}

void	fize_one(t_list **a, t_list **b, int j)
{
	int	i;

	i = 0;
	while (ft_lstsize(*a) > 0)
	{
		if ((*a)->index <= i)
		{
			push(a, b, "pb");
			i++;
		}
		else if ((*a)->index < (i + j))
		{
			push(a, b, "pb");
			rotate(b, "rb");
			i++;
		}
		else
			rotate(a, "ra");
	}
}

void	fize_tow(t_list **a, t_list **b)
{
	int	max;
	int	size_of_part1;

	max = ft_lstsize(*b) - 1;
	while (ft_lstsize(*b) > 0)
	{
		size_of_part1 = ft_lstsize(*b) / 2;
		if (were_is_max(b, 0, size_of_part1, max) == 1)
		{
			action_case(b, max, 1);
			push(b, a, "pa");
		}
		else if (were_is_max(b, 0, size_of_part1, max) == 0)
		{
			action_case(b, max, 2);
			push(b, a, "pa");
		}
		max--;
	}
}

void	sort_less_than_100(t_list **a)
{
	t_list	*b;

	b = NULL;
	fize_one(a, &b, 15);
	fize_tow(a, &b);
}

void	sort_greater_than_100(t_list **a)
{
	t_list	*b;

	b = NULL;
	fize_one(a, &b, 35);
	fize_tow(a, &b);
}
