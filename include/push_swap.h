/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framador <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:25:05 by framador          #+#    #+#             */
/*   Updated: 2024/03/09 19:55:01 by framador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_list
{
	long					content;
	int					cost;
	int					index;
	struct s_list		*bestfriend;
	struct s_list		*next;
	struct s_list		*prev;
}	t_list;

char	*ft_superjoint(int ac, char *av[]);
char	*ft_strjoin(char *s1, char *s2);

int		ft_getmax(t_list **head);
int		ft_listcount(t_list *ahead);
int		ft_calculatecost(t_list *target);
int		ft_checkdup(t_list *ahead);
int		ft_checker(char *str);
int		ft_rrx(t_list **ahead, int i);
int		ft_px(t_list **src, t_list **dest, int i);
int		ft_rx(t_list **ahead, int i);
int		ft_sx(t_list **ahead, int i);
int		ft_ss(t_list **ahead, t_list **bhead);
int		ft_issorted(t_list **ahead);
int		ft_getmin(t_list **head);
int		ft_getmax(t_list **head);
int		ft_sort3(t_list **ahead, t_list *node2, t_list *node3);

long	ft_nodesum(t_list **ahead);

void	ft_fillcost(t_list **head, t_list *target);
void	ft_lezsort(t_list **ahead, t_list **bhead);
void	ft_clearlst(t_list **ahead);
void	ft_samerot(t_list **ahead, t_list **bhead, int acost, int bcost);
void	ft_rrr(t_list **ahead, t_list **bhead);
void	ft_rr(t_list **ahead, t_list **bhead);
void	ft_stackadd(int res, t_list **ahead);
void	ft_atol(char *line, t_list **ahead);
void	ft_pushtob(t_list **ahead, t_list **bhead);
void	ft_pushswap(t_list **ahead, t_list **bhead);
void	ft_pushtop(t_list **ahead, t_list **bhead, t_list *target);
void	ft_diffrot(t_list **ahead, t_list **bhead, int acost, int bcost);
void	ft_update_indices(t_list **head);
void	ft_aoitodo(t_list **ahead, t_list **bhead);
void    ft_returntoa(t_list **ahead, t_list **bhead);

t_list	*ft_findsmallest(t_list **bhead);
t_list	*ft_findsmallest(t_list **bhead);
t_list	*ft_lastnode(t_list **ahead);
t_list	*ft_findbestpush(t_list **ahead, t_list **bhead);

size_t	ft_strlen(char *s);

void	ft_clearlst(t_list **ahead);

#endif
