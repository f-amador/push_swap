#include "../include/push_swap.h"

void	ft_sort(t_list **ahead)
{
	t_list	*node_to_push;

	node_to_push = ft_findsmallest(ahead);
	ft_fillcost(ahead, node_to_push);
	if (node_to_push->cost > 0)
	{
		while (node_to_push->cost)
		{
			ft_rx(ahead, 1);
			node_to_push->cost -= 1;
		}
	}
	else
	{
		while (node_to_push->cost)
		{
			ft_rrx(ahead, 1);
			node_to_push->cost += 1;
		}
	}
}

void	ft_lezsort(t_list **ahead, t_list **bhead)
{
	ft_aoitodo(ahead, bhead);
	ft_returntoa(ahead, bhead);
	ft_update_indices(ahead);
	if (!ft_issorted(ahead))
		ft_sort(ahead);
}

int	ft_getmax(t_list **head)
{
	int		max;
	t_list	*tmp;

	max = (*head)->content;
	tmp = (*head)->next;
	while (tmp)
	{
		if (tmp->content < max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_getmin(t_list **head)
{
	int		min;
	t_list	*tmp;

	min = (*head)->content;
	tmp = (*head)->next;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_pushtob(t_list **ahead, t_list **bhead)
{
	int	i;
	int	nnodes;

	nnodes = (*ahead)->prev->index + 1;
	i = 0;
	while (i < nnodes - 3)
	{
		if (ft_issorted(ahead))
			break ;
		ft_px(ahead, bhead, 0);
		i++;
	}
	ft_sort3(ahead, (*ahead)->next, (*ahead)->next->next);
	ft_update_indices(ahead);
	ft_update_indices(bhead);
	ft_lezsort(ahead, bhead);
}
