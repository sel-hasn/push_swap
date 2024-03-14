/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:59:46 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/03/05 15:56:19 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long	max_min_handel(long n)
{
	if (n > 2147483647 || n < -2147483648)
	{
		write (2, "Error\n", 7);
		exit (5);
	}
	return (n);
}

long	ft_atoi(char *s)
{
	long	r;
	long	sing;
	int		i;

	r = 0;
	sing = 1;
	i = 0;
	if (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sing = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		r = r * 10 + (s[i] - 48);
		i++;
	}
	return (max_min_handel(r * sing));
}

int	ft_cmp(int *nbr, int n, int indx)
{
	int	i;

	i = 0;
	if (indx == 0)
		return (1);
	while (i < indx)
	{
		if (nbr[i] == n)
			return (0);
		i++;
	}
	return (1);
}

int	nbr_index(int *nbr, int data, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (nbr[i] == data)
			return (i);
		i++;
	}
	return (i);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
