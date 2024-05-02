/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framador <framador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:35:08 by framador          #+#    #+#             */
/*   Updated: 2024/03/09 21:19:10 by framador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_pushswap(t_list **ahead, t_list **bhead)
{
	int	nnodes;

	nnodes = ft_listcount(*ahead);
	if (nnodes == 1)
		return ;
	else if (nnodes == 2)
	{
		if (ft_issorted(ahead))
			return ;
		ft_rx(ahead, 1);
		return ;
	}
	else if (nnodes == 3)
		ft_sort3(ahead, (*ahead)->next, (*ahead)->next->next);
	else
		ft_pushtob(ahead, bhead);
}

void	ft_error(t_list **ahead, t_list **bhead, char *line)
{
	write(2, "Error\n", 6);
	ft_clearlst(ahead, bhead, line);
}

void	ft_samerot(t_list **ahead, t_list **bhead, int acost, int bcost)
{
	if (acost > 0)
	{
		while (acost && bcost)
		{
			ft_rr(ahead, bhead);
			acost--;
			bcost--;
		}
		while (acost--)
			ft_rx(ahead, 1);
		while (bcost--)
			ft_rx(bhead, 0);
	}
	else
		ft_samerot2(ahead, bhead, acost, bcost);
}

void	ft_pushinit(t_list **ahead, t_list **bhead, int ac, char *av[])
{
	char	*line;

	line = ft_superjoint(ac, av);
	if (ft_checker(line))
	{
		ft_atol(line, ahead, bhead);
		if (!(*ahead))
			ft_error(ahead, bhead, line);
	}
	else
		ft_error(ahead, bhead, line);
	if (*ahead)
		ft_pushswap(ahead, bhead);
	ft_clearlst(ahead, bhead, line);
}

int	main(int ac, char *av[])
{
	t_list	**ahead;
	t_list	**bhead;

	ahead = (t_list **)malloc(sizeof(t_list *));
	if (!ahead)
		return (1);
	bhead = (t_list **)malloc(sizeof(t_list *));
	if (!bhead)
		return (1);
	*ahead = NULL;
	*bhead = NULL;
	if (ac > 1)
		ft_pushinit(ahead, bhead, ac, av);
	ft_clearlst(ahead, bhead, NULL);
	return (0);
}
