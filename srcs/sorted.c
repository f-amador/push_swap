#include "../include/push_swap.h"

void	ft_lezsort(t_list **ahead, t_list **bhead)
{
	ft_aoitodo(ahead, bhead);
	ft_returntoa(ahead, bhead);
	while (!ft_issorted(ahead))
		ft_rx(ahead, 1);
}

int ft_getmax(t_list **head)
{
	int max;
	t_list *tmp;

	max = (*head)->content;
	tmp = (*head)->next;
	while(tmp)
	{
		if (tmp->content < max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}


int ft_getmin(t_list **head)
{
	int min;
	t_list *tmp;

	min = (*head)->content;
	tmp = (*head)->next;
	while(tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_pushtob(t_list **ahead, t_list **bhead)
{
	int i;
	int nnodes;

	nnodes = (*ahead)->prev->index + 1;
	i = 0;
	while (i < nnodes - 3)
	{
		ft_px(ahead, bhead, 0);
		i++;
	}
	ft_sort3(ahead, (*ahead)->next, (*ahead)->next->next);
	ft_update_indices(ahead);
	ft_update_indices(bhead);
	ft_lezsort(ahead, bhead);
}


