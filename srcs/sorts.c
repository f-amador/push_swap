
#include "../include/push_swap.h"

int	ft_sort3(t_list **ahead, t_list *node2, t_list *node3)
{

	if ((*ahead)->content > node2->content)
	{
		if (node2->content < node3->content)
		{	
			if ((*ahead)->content < node3->content)
				return (ft_sx(ahead, 1));
				else
			return (ft_rx(ahead, 1));
		}
		else 
		return (ft_sx(ahead, 1), ft_rrx(ahead, 1));
	}
	else 
	{
		if (node2->content > node3->content)
		{
			if ((*ahead)->content < node3->content)
				return (ft_sx(ahead, 1), ft_rx(ahead, 1));
			else 
			return (ft_rrx(ahead, 1));
		}
	}
	return (1);
}

long ft_nodesum(t_list **ahead)
{
	long res;
	t_list	*current;

	current = *ahead;
	res = 0;
	while (current != NULL)
	{
		res += current->content;
		current = current->next;
	}
	return res;
}

void ft_fillcost(t_list **head, t_list *target)
{
	int mid;

	mid = (((*head)->prev->index + 1) / 2);
	if (target->index <= mid)
		target->cost = target->index;
	else
		target->cost = (target->index - (*head)->prev->index - 1);
}


void ft_update_indices(t_list **head)
{
	t_list *node;
	int index;

	index = 0;
	node = *head;
	while (node) 
	{	
		node->index = index;	
		ft_fillcost(head, node);
		index++;
		node = node->next;
	}
}


void	ft_aoitodo(t_list **ahead, t_list **bhead)
{
	t_list *ac;
	t_list *bc;
	long long tmp;

	bc = *bhead;
	while (bc)
	{
		tmp = 214748364711;
		ac = *ahead;
		while (ac)
		{
			if (ac->content - bc->content > 0 && tmp > ac->content - bc->content)
			{
				bc->bestfriend = ac;
				tmp = ac->content - bc->content;
			}
			ac = ac->next;
		}
		bc = bc->next;
	}
}



