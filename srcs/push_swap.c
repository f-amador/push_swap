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

void ft_pushswap(t_list **ahead, t_list **bhead)
{
	int nnodes;

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

int	main(int ac, char *av[])
{
	char *line;
	t_list **ahead;
	t_list **bhead;

	ahead = (t_list **)malloc(sizeof(t_list *));
	if (!ahead)
		return (1);
	bhead = (t_list **)malloc(sizeof(t_list *));
	if (!bhead)
		return (1);
	*ahead = NULL;
	*bhead = NULL;
	if (ac > 1)
	{
		line = ft_superjoint(ac, av);
		if (ft_checker(line))
		{
			ft_atol(line, ahead);
			if (!(*ahead))
				write(2, "Error\n", 6);
		}
		else
			write(2, "Error\n", 6);
		free(line);
		if (*ahead)
			ft_pushswap(ahead, bhead);
		ft_clearlst(ahead);
		ft_clearlst(bhead);
	}
	else 
		write(2, "Error\n", 6);

	free(ahead);
	free(bhead);
	return (0);
}
