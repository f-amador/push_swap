
#include "../include/push_swap.h"

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
		return ((target->cost < 0) * -(target->cost)
			+ (target->bestfriend->cost < 0)
			* -(target->bestfriend->cost) + (target->cost > 0) * target->cost
			* + (target->bestfriend->cost > 0) * target->bestfriend->cost);
	}
	return (INT_MAX);
}

t_list	*ft_findbestpush(t_list **bhead)
{
	int		bestnodecost;
	int		cost;
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
			cost = ft_calculatecost(tmp);
			if (cost < bestnodecost)
			{
				bestnode = tmp;
				bestnodecost = cost;
				if (bestnodecost <= 1)
					break ;
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
