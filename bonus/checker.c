/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:51:25 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/03/13 17:23:09 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss_rr_rrr(t_list **a, t_list **b, char *instration)
{
	if (cmpstr(instration, "ss") != 0)
		ss(a, b);
	else if (cmpstr(instration, "rr") != 0)
		rr(a, b);
	else if (cmpstr(instration, "rrr") != 0)
		rrr(a, b);
}

void	do_instration(t_list **a, t_list **b, char **all_ins, int i)
{
	while (all_ins[i] != NULL)
	{
		if (cmpstr(all_ins[i], "sa") != 0)
			swap(a);
		else if (cmpstr(all_ins[i], "ra") != 0)
			rotate(a);
		else if (cmpstr(all_ins[i], "rra") != 0)
			reverse_rotate(a);
		else if (cmpstr(all_ins[i], "pb") != 0)
			push(a, b);
		else if (cmpstr(all_ins[i], "sb") != 0)
			swap(b);
		else if (cmpstr(all_ins[i], "rb") != 0)
			rotate(b);
		else if (cmpstr(all_ins[i], "rrb") != 0)
			reverse_rotate(b);
		else if (cmpstr(all_ins[i], "pa") != 0)
			push(b, a);
		else if (cmpstr(all_ins[i], "ss") != 0 || cmpstr(all_ins[i], "rr") != 0
			|| cmpstr(all_ins[i], "rrr") != 0)
			ss_rr_rrr(a, b, all_ins[i]);
		i++;
	}
}

char	**read_all_instration(char *str)
{
	char	*s;

	s = ft_strdup("");
	str = get_next_line(0);
	while (str != NULL)
	{
		if (cmpstr(str, "ra\n") != 0 || cmpstr(str, "sa\n") != 0
			|| cmpstr(str, "pb\n") != 0 || cmpstr(str, "rra\n") != 0
			|| cmpstr(str, "rb\n") != 0 || cmpstr(str, "sb\n") != 0
			|| cmpstr(str, "pa\n") != 0 || cmpstr(str, "rrb\n") != 0
			|| cmpstr(str, "rr\n") != 0 || cmpstr(str, "rrr\n") != 0
			|| cmpstr(str, "ss\n") != 0)
		{
			s = ft_strjoin(s, str);
			free(str);
			str = get_next_line(0);
		}
		else
			find_error1(s, 7);
	}
	if (s != NULL)
		return (ft_split(s, '\n'));
	return (NULL);
}

int	checker(t_list **a)
{
	char	**all_instration;
	char	*str;
	t_list	*tmp;
	t_list	*b;
	int		i;

	b = NULL;
	str = NULL;
	all_instration = read_all_instration(str);
	if (!all_instration)
		return (0);
	i = 0;
	do_instration(a, &b, all_instration, i);
	while (all_instration[i])
	{
		free(all_instration[i]);
		i++;
	}
	free(all_instration);
	tmp = *a;
	ft_lstclear(&b);
	return (checker_sort(&tmp));
}

int	main(int arc, char **arv)
{
	t_list	*a;

	if (arc > 1)
	{
		a = parcing(arv);
		if (checker(&a) == 1)
			write(1, "OK\n", 4);
		else
			write(1, "KO\n", 4);
		ft_lstclear(&a);
	}
	else
		exit(0);
}
