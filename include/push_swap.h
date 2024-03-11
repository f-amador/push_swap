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
	int					content;
	int					cost;
	int					index;
	struct s_list		*bestfriend;
	struct s_list		*next;
	struct s_list		*prev;
}	t_list;

char	*ft_superjoint(int ac, char *av[]);
char	*ft_strjoin(char *s1, char *s2);

int		ft_checkdup(t_list *ahead);
int		ft_checker(char *str);

void	ft_stackadd(int res, t_list **ahead);
void	ft_atol(char *line, t_list **ahead);
t_list	*ft_lastnode(t_list **ahead);

size_t	ft_strlen(char *s);

void	ft_clearlst(t_list **ahead);

#endif
