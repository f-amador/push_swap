
#include "../include/push_swap.h"


void	ft_diffrot(t_list **ahead, t_list **bhead, int acost, int bcost)
{
	while (acost > 0)
	{
		ft_rx(ahead, 1);
		acost--;
	}
	while (bcost > 0)
	{
		ft_rx(bhead, 0);
		bcost--;
	}
	while (acost < 0)
	{
		ft_rrx(ahead, 1);
		acost++;
	}
	while (bcost < 0)
	{
		ft_rrx(bhead, 0);
		bcost++;
	}
}

void ft_pushtop(t_list **ahead, t_list **bhead, t_list *target)
{
	int acost;
	int bcost;
	if (!target)
		return;
	acost = target->bestfriend->cost;
	bcost = target->cost;

	if ((acost < 0 && bcost < 0) || (acost > 0 && bcost > 0))
		ft_samerot(ahead, bhead, acost, bcost);
	else
		ft_diffrot(ahead, bhead, acost, bcost);
	ft_px(bhead, ahead, 1);
}
t_list	*ft_findsmallest(t_list **bhead)
{
	t_list *tmp;
	t_list *smallest_node;

	tmp = *bhead;
	smallest_node = tmp;
	while (tmp)
	{
		if (tmp->content < smallest_node->content)
			smallest_node = tmp;
		tmp = tmp->next;
	}
	return smallest_node;
}
void	ft_returntoa(t_list **ahead, t_list **bhead)
{
	t_list *node_to_push;

	while ((*bhead))
	{

		node_to_push = ft_findbestpush(bhead);
		if (!node_to_push)
		{
			node_to_push = ft_findsmallest(bhead);
			node_to_push->bestfriend = ft_findsmallest(ahead);
		}
		ft_fillcost(bhead, node_to_push);
		ft_fillcost(ahead, node_to_push->bestfriend);
		ft_pushtop(ahead, bhead, node_to_push);
		ft_update_indices(ahead);
		ft_update_indices(bhead);	
		ft_aoitodo(ahead, bhead);
	}
}
int	ft_issorted(t_list **ahead)
{
	t_list *tmp;

	tmp = *ahead;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
		return (0);
		tmp = tmp->next;
	}
	return (1);
}
