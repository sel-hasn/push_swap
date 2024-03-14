/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:49:27 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/03/10 10:22:38 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

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
t_list	*ft_lstnew(int data);
int		ft_lstsize(t_list *lst);
void	find_error(char **arv, int i);
void	find_error1(char *s, int i);
long	ft_atoi(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		nbr_index(int *nbr, int data, int size);
char	**ft_split(char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char	*str);
char	*ft_strdup(const char *s1);
void	error_handel(char **nbrs);
t_list	*parcing(char **arv);
t_list	*list_befor_last(t_list *list);
void	swap(t_list **list);
void	push(t_list **list, t_list **list1);
void	reverse_rotate(t_list **list);
void	rotate(t_list **list);
char	*get_next_line(int fd);
char	*line(char *s);
char	*rest_of_str(char *s);
char	*read_line(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_newline1(char *s);
char	*ft_strdup1(const char *s);
char	*ft_strjoin1(char *s1, char *s2);
char	*ft_substr1(char const *s, unsigned int start, size_t len);
void	free_all_nbr(char **all_nbr);
char	**freeword(char **str, size_t idx);
void	if_fail(char **arg);
void	if_fail1(char *str);
int		checker_sort(t_list **a);
int		cmpstr(char *s1, char *s2);
void	ss(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);
void	rr(t_list **a, t_list **b);

#endif