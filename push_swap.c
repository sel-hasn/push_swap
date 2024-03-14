/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:59:36 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/03/13 17:22:56 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **a)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 1)
		return ;
	if (size == 3 || size == 2)
		sort_three(a);
	else if (size == 4)
		sort_four(a);
	else if (size == 5)
		sort_five(a);
	else if (size <= 100)
		sort_less_than_100(a);
	else if (size > 100)
		sort_greater_than_100(a);
}

int	main(int arc, char **arv)
{
	t_list	*a;
	t_list	*tmp;

	if (arc > 1)
	{
		a = parcing(arv);
		tmp = a;
		if (check_if_sort(tmp) == 1)
		{
			ft_lstclear(&a);
			exit(0);
		}
		sort(&a);
		ft_lstclear(&a);
	}
	else
		exit(0);
}
