#include "../include/push_swap.h"

int	ft_listcount(t_list *ahead)
{
	t_list	*tmp;
	int		res;

	res = 1;
	if (!ahead)
		return (0);
	tmp = ahead;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		res++;
	}
	return (res);
}

void	ft_stackadd(int res, t_list **ahead)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = res;
	new_node->bestfriend = NULL;
	new_node->next = NULL;
	if (*ahead == NULL)
	{
		new_node->index = 0;
		new_node->prev = new_node;
		*ahead = new_node;
	}
	else
	{
		last_node = (*ahead)->prev;
		new_node->index = (last_node->index) + 1;
		last_node->next = new_node;
		new_node->prev = last_node;
		(*ahead)->prev = new_node;
	}
	new_node->cost = INT_MAX;
}

int	ft_checkdup(t_list *ahead)
{
	t_list	*current;
	t_list	*check;

	current = ahead;
	while (current)
	{
		check = current->next;
		while (check != NULL)
		{
			if (current->content == check->content)
				return (1);
			check = check->next;
			if (check == ahead)
				break ;
		}
		current = current->next;
	}
	return (0);
}

int	ft_rrx(t_list **ahead, int i)
{
	t_list	*lastnode;
	t_list	*secondlastnode;

	if (*ahead == NULL || (*ahead)->next == NULL)
		return (0);
	lastnode = *ahead;
	while (lastnode->next != NULL)
	{
		secondlastnode = lastnode;
		lastnode = lastnode->next;
	}
	secondlastnode->next = NULL;
	lastnode->next = *ahead;
	(*ahead)->prev = lastnode;
	*ahead = lastnode;
	if (i == 1)
		return (write(1, "rra\n", 4));
	else if (i == 0)
		return (write(1, "rrb\n", 4));
	else
		return (0);
}

int	ft_px(t_list **src, t_list **dest, int i)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *src;
	*src = (*src)->next;
	if (*src != NULL)
		(*src)->prev = tmp->prev;
	tmp->next = *dest;
	if (*dest != NULL)
	{
		last = (*dest)->prev;
		tmp->prev = last;
		(*dest)->prev = tmp;
		if (last != NULL)
			last->next = NULL;
	}
	else
		tmp->prev = tmp;
	*dest = tmp;
	if (i)
		return (write(1, "pa\n", 3));
	return (write(1, "pb\n", 3));
}
