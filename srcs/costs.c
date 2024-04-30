
#include "../include/push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	ft_calculatecost(t_list *target)
{
	if (target->bestfriend)
	{
		if (target->cost > 0 && target->bestfriend->cost > 0)
		{
			if (target->cost > target->bestfriend->cost)
				return (target->cost);
			else
				return (target->bestfriend->cost);
		}
		else if (target->cost < 0 && target->bestfriend->cost < 0)
		{
			if (target->cost < target->bestfriend->cost)
				return (-(target->cost));
			else
				return (-(target->bestfriend->cost));
		}
		return (ft_abs(target->cost) + ft_abs(target->bestfriend->cost));
	}
	return (INT_MAX);
}

t_list	*ft_findbestpush(t_list **ahead, t_list **bhead)
{
	long		bestnodecost;
	long		cost;
	t_list	*bestnode;
	t_list	*tmp;

	bestnode = NULL;
	bestnodecost = INT_MAX;
	cost = INT_MAX;
	tmp = *bhead;
	while (tmp)
	{
		if (tmp->bestfriend)
		{
			ft_fillcost(ahead, tmp->bestfriend);
			ft_fillcost(bhead, tmp);
			cost = ft_calculatecost(tmp);
			//printf("Bnode:%d Index:%d Cost:%d\nAnode:%d Index:%d Cost:%d\nTotalCost:%ld\n", tmp->content, tmp->index, tmp->cost, tmp->bestfriend->content, tmp->bestfriend->index, tmp->bestfriend->cost, cost);
			if (cost < bestnodecost)
			{
				bestnode = tmp;
				bestnodecost = cost;
			}
		}
		tmp = tmp->next;
	}
	return (bestnode);
}

void	ft_rr(t_list **ahead, t_list **bhead)
{
	write(1, "rr\n", 3);
	ft_rx(ahead, 2);
	ft_rx(bhead, 2);
}

void	ft_rrr(t_list **ahead, t_list **bhead)
{
	write(1, "rrr\n", 4);
	ft_rrx(ahead, 2);
	ft_rrx(bhead, 2);
}

void	ft_samerot(t_list **ahead, t_list **bhead, int acost, int bcost)
{
	if (acost > 0)
	{
		while (acost && bcost)
		{
			acost--;
			bcost--;
			ft_rr(ahead, bhead);
		}
		while (acost)
		{
			ft_rx(ahead, 1);
			acost--;
		}
		while (bcost--)
			ft_rx(bhead, 0);
	}
	else
	{
		while (acost && bcost)
		{
			acost++;
			bcost++;
			ft_rrr(ahead, bhead);
		}
		while (acost++)
			ft_rrx(ahead, 1);
		while (bcost++)
			ft_rrx(bhead, 0);
	}
}
