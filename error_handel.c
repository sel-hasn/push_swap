/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:26:39 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/03/10 10:06:01 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_error(char **arv, int i)
{
	free_all_nbr(arv);
	write (2, "Error\n", 7);
	exit(i);
}

void	sort_nbr(int *nbr, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < (size - 1))
	{
		if (nbr[i] > nbr[i + 1])
		{
			tmp = nbr[i];
			nbr[i] = nbr[i + 1];
			nbr[i + 1] = tmp;
			i = 0;
		}
		else if (nbr[i] < nbr[i + 1])
			i++;
	}
}

void	indexing(t_list *list, int *nbr, int size)
{
	int	i;

	i = 0;
	sort_nbr(nbr, size);
	while (list)
	{
		list->index = nbr_index(nbr, list->data, size);
		list = list->next;
	}
}

void	error_handel(char **nbrs)
{
	int	i;
	int	j;

	i = 0;
	while (nbrs[i] != NULL)
	{
		j = 0;
		if (nbrs[i][j] == '-' || nbrs[i][j] == '+')
			j++;
		while (nbrs[i][j])
		{
			if (nbrs[i][j] >= '0' && nbrs[i][j] <= '9')
				j++;
			else
				find_error(nbrs, 2);
		}
		if ((nbrs[i][j - 1] == '-' || nbrs[i][j - 1] == '+')
		&& nbrs[i][j] == '\0')
			find_error(nbrs, 3);
		i++;
	}
}

void	handle_duplication(t_list *list)
{
	t_list	*tmp;
	int		*nbr;
	int		i;
	int		j;

	tmp = list;
	i = ft_lstsize(list);
	nbr = malloc(sizeof(int) * i);
	j = 0;
	while (list)
	{
		if (ft_cmp(nbr, list->data, j) == 0)
		{
			free(nbr);
			ft_lstclear(&list);
			write (2, "Error\n", 6);
			exit (4);
		}
		nbr[j] = list->data;
		j++;
		list = list->next;
	}
	indexing(tmp, nbr, j);
	free(nbr);
}
