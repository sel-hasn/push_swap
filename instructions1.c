/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:07:09 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/03/10 19:42:36 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **a, t_list **b)
{
	swap(a, NULL);
	swap(b, NULL);
	write (1, "ss\n", 4);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a, NULL);
	rotate(b, NULL);
	write(1, "rr\n", 1);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a, NULL);
	reverse_rotate(b, NULL);
	write(1, "rrr\n", 1);
}
