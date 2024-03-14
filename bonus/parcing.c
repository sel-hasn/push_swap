/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:59:24 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/03/09 17:43:13 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**alloc_arv(char **arv)
{
	int		i;
	int		j;
	char	**argv;

	i = 0;
	j = 1;
	while (arv[i] != NULL)
		i++;
	argv = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (arv[j] != NULL)
	{
		argv[i] = ft_strdup(arv[j]);
		if (!argv[i])
		{
			freeword(argv, i);
			return (NULL);
		}
		i++;
		j++;
	}
	argv[i] = NULL;
	return (argv);
}

void	find_empty_str(char **arv)
{
	int	i;
	int	j;

	i = 0;
	while (arv[i])
	{
		j = 0;
		while (arv[i][j])
		{
			if (arv[i][j] != ' ')
				break ;
			j++;
		}
		if (arv[i][j] == '\0')
		{
			find_error(arv, 1);
		}
		i++;
	}
}

char	*get_all_nbr(char **arv)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	find_empty_str(arv);
	str = ft_strdup("");
	while (arv[i] != NULL)
	{
		tmp = ft_strjoin(ft_strdup(" "), arv[i]);
		if (i > 0)
			str = ft_strjoin(str, tmp);
		else if (i == 0)
			str = ft_strjoin(str, arv[i]);
		if (!str)
			return (free_all_nbr(arv), free(str), free(tmp), NULL);
		free(tmp);
		free(arv[i]);
		i++;
	}
	free(arv);
	return (str);
}

t_list	*parcing(char **arv)
{
	int		i;
	char	*str;
	char	**all_nbr;
	t_list	*list;

	i = 0;
	arv = alloc_arv(arv);
	if_fail(arv);
	str = get_all_nbr(arv);
	if_fail1(str);
	all_nbr = ft_split(str, ' ');
	if_fail(all_nbr);
	error_handel(all_nbr);
	while (all_nbr[i] != NULL)
	{
		if (i == 0)
			list = ft_lstnew(ft_atoi(all_nbr[i]));
		else
			ft_lstadd_back(&list, ft_lstnew(ft_atoi(all_nbr[i])));
		i++;
	}
	free_all_nbr(all_nbr);
	handle_duplication(list);
	return (list);
}
