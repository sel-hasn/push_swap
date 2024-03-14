/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:06:51 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/03/13 16:56:01 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_cmp(int *nbr, int n, int indx);
void	handle_duplication(t_list *list);
void	ft_lstclear(t_list **lst);
int		check_if_sort(t_list *a);
t_list	*ft_lstnew(int data);
int		ft_lstsize(t_list *lst);
void	find_error(char **arv, int i);
long	ft_atoi(char **s, t_list *a, int j);
char	*ft_strjoin(char *s1, char *s2);
int		nbr_index(int *nbr, int data, int size);
char	**freeword(char **str, size_t idx);
char	**ft_split(char *s, char c);
size_t	ft_strlen(const char	*str);
char	*ft_strdup(const char *s1);
void	error_handel(char **nbrs);
t_list	*parcing(char **arv);
t_list	*list_befor_last(t_list *list);
void	swap(t_list **list, char *instruction);
void	push(t_list **list, t_list **list1, char *instruction);
void	reverse_rotate(t_list **list, char *instruction);
void	rotate(t_list **list, char *instruction);
void	sort_three(t_list **a);
void	sort_four(t_list **a);
void	sort_five(t_list **a);
void	sort_less_than_100(t_list **a);
void	sort_greater_than_100(t_list **a);
int		were_is_max(t_list **list, int start, int end, int max);
void	free_all_nbr(char **all_nbr);
void	if_fail(char **arg);
void	if_fail1(char *str);

#endif