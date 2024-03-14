/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:59:46 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/03/10 15:54:39 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	max_min_handel(long n, t_list *a, char **s)
{
	if (n > 2147483647 || n < -2147483648)
	{
		free_all_nbr(s);
		ft_lstclear(&a);
		write (2, "Error\n", 7);
		exit (5);
	}
	return (n);
}

long	ft_atoi(char **s, t_list *a, int j)
{
	long	r;
	long	sing;
	long	tmp;
	int		i;

	r = 0;
	sing = 1;
	i = 0;
	if (s[j][i] == ' ' || (s[j][i] >= 9 && s[j][i] <= 13))
		i++;
	if (s[j][i] == '-' || s[j][i] == '+')
	{
		if (s[j][i] == '-')
			sing = -1;
		i++;
	}
	while (s[j][i] >= '0' && s[j][i] <= '9')
	{
		tmp = r;
		r = r * 10 + (s[j][i] - 48);
		if (tmp > r)
			max_min_handel(tmp, a, s);
		i++;
	}
	return (max_min_handel(r * sing, a, s));
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
