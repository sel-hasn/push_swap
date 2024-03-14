/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:23 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/03/09 15:13:31 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	if_fail1(char *str)
{
	if (!str)
		exit(EXIT_FAILURE);
}

void	free_all_nbr(char **all_nbr)
{
	int	i;

	i = 0;
	if (!all_nbr)
		return ;
	while (all_nbr[i] != NULL)
		free(all_nbr[i++]);
	free(all_nbr);
}

void	if_fail(char **arg)
{
	if (!arg)
		exit(EXIT_FAILURE);
}

int	cmpstr(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	return (0);
}

int	checker_sort(t_list **a)
{
	int	i;

	i = 0;
	if (!a || !(*a))
		return (0);
	while (*a)
	{
		if (i == (*a)->index)
			i++;
		else
			return (0);
		*a = (*a)->next;
	}
	return (1);
}
