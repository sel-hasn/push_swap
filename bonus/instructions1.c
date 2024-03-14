/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:07:09 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/03/10 18:42:45 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
