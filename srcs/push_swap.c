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

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1l;	
	char	*str;

	i = 0;
	j = 0;
	s1l = ft_strlen(s1);
	str = (char *)malloc(s1l + ft_strlen(s2) + 2);
	if (!str)
		return (NULL);
	while (i < s1l)
	{
		str[i] = s1[i];
		i++;
	}
	if (s1l > 0 && s2[0] != ' ')
		str[i++] = ' ';
	while (s2[j] && !(s2[j] == 32 && !s2[j + 1]))
		str[i++] = s2[j++];
	str[i] = 0;
	if (s1)
		free(s1);
	return (str);
}

char	*ft_superjoint(int ac, char *av[])
{
	int		i;
	char	*line;

	i = 1;
	line = NULL;
	while (i < ac)
	{
		line = ft_strjoin(line, av[i]);
		i++;
	}
	return (line);
}

int	ft_checker(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = (str[i] >= '0' && str[i] <= '9');
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') 
					|| str[i] == 32 || str[i] == 45))
			return (0);
		else
		{
			if (str[i] == 32)
				n++;
			i++;
		}
	}
	return (n);
}

t_list 	*ft_lastnode(t_list	**ahead)
{
	t_list	*node;

	if (!(*ahead))
		return (NULL);
	node = *ahead;
	while (node->next != *ahead)
		node = node->next;
	return (node);
}

int ft_listcount(t_list *ahead)
{
	t_list *tmp;
	int res;

	res = 1;
	if (!ahead)
		return (0);
	tmp = ahead;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
		res++;
	}
	return res;
}

void ft_stackadd(int res, t_list **ahead)
{
	t_list *new_node;
	t_list *last_node;

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

	if (ahead == NULL)
		return (0);

	current = ahead;
	while (1)
	{
		check = current->next;
		while (check != NULL)
		{
			if (current->content == check->content)
				return (1);
			check = check->next;
			if (check == ahead)
				break;
		}
		current = current->next;
		if (current == NULL)
			break;
	}
	return (0);
}

int ft_rrx(t_list **ahead, int i)
{
	t_list *lastnode;
	t_list *secondlastnode;

	if (ahead == NULL || *ahead == NULL || (*ahead)->next == NULL)
		return 0;

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
	if (i)
		return (write(1, "rra\n", 4));
	return (write(1, "rrb\n", 4));
}
int ft_px(t_list **src, t_list **dest, int i)
{
    t_list *tmp;
    t_list *last;

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
	{
        tmp->prev = tmp;
    }
    *dest = tmp;
    if (i)
        return (write(1, "pa\n", 3));
    return (write(1, "pb\n", 3));
}
int ft_rx(t_list **ahead, int i)
{
	t_list *firstnode;
	t_list *lastnode;

	if (ahead == NULL || *ahead == NULL || (*ahead)->next == NULL)
		return 0;
	firstnode = *ahead;
	*ahead = (*ahead)->next;
	(*ahead)->prev = NULL;

	lastnode = *ahead;
	while (lastnode->next != NULL)
		lastnode = lastnode->next;
	lastnode->next = firstnode;
	firstnode->prev = lastnode;
	firstnode->next = NULL;
	(*ahead)->prev = firstnode;
	if (i)
		return (write(1, "ra\n", 3));
	return (write(1, "rb\n", 3));
}
int	ft_sx(t_list **ahead, int i)
{
    t_list *firstnode, *secondnode, *lastnode;

    if (ahead == NULL || *ahead == NULL || (*ahead)->next == NULL)
        return (0);
    firstnode = *ahead;
    secondnode = (*ahead)->next;
    lastnode = firstnode->prev; // Save the last node of the list

    firstnode->next = secondnode->next;
    if (secondnode->next != NULL)
        secondnode->next->prev = firstnode;
    secondnode->next = firstnode;
    firstnode->prev = secondnode;

    *ahead = secondnode;
    (*ahead)->prev = lastnode; // Set the prev pointer of the new head to the last node
    if (lastnode != NULL)
        lastnode->next = NULL; // Set the next pointer of the last node to NULL

    if (i)
        return (write(1, "sa\n", 3));
    return (write(1, "sb\n", 3));
}
int ft_ss(t_list **ahead, t_list **bhead)
{
	return (ft_sx(ahead, 1) + ft_sx(bhead, 0));
}

void ft_clearlst(t_list **ahead)
{
	t_list *tmp;
	t_list *next_node;

	if (ahead == NULL || *ahead == NULL)
		return;

	tmp = *ahead;
	while (tmp != NULL)
	{
		next_node = tmp->next;
		free(tmp);
		tmp = next_node;
	}
	*ahead = NULL;
}

void	ft_atol(char *line, t_list **ahead)
{
	int		i;
	int		sig;
	long	res;

	i = 0;
	while (line[i])
	{
		res = 0;
		sig = 1;
		if (line[i] == 32)
			i++;
		if (line[i] == 45)
		{
			sig = -1;
			i++;
		}
		while (line[i] >= '0' && line[i] <= '9')
			res = res * 10 + line[i++] - '0';
		if ((res * sig) > INT_MAX || (res * sig) < INT_MIN)
			return ;
		ft_stackadd(((int)res * sig), ahead);
	}
	if (ft_checkdup(*ahead))
		ft_clearlst(ahead);
}

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

float ft_nodesum(t_list **ahead)
{
	float res;
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

void update_indices(t_list **head)
{
	t_list *node;
	int index;

	index = 0;
	node = *head;
	while (node != NULL && node->next != *head) 
	{
		node->index = index++;
		node = node->next;
	}
}


void ft_fillcost(t_list **head, t_list *target)
{
	int mid;

	mid = (((*head)->prev->index + 1) / 2);
	if (target->index <= mid)
		target->cost = target->index;
	else
		target->cost = (target->index - (*head)->prev->index + 1);
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
				ft_fillcost(bhead, bc);
				ft_fillcost(ahead, bc->bestfriend);
				tmp = ac->content - bc->content;
			}
			ac = ac->next;
		}
		bc = bc->next;
	}
}


int ft_calculatecost(t_list *target)
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
		else
			return((target->cost < 0) * -(target->cost) + (target->bestfriend->cost < 0) 
					* -(target->bestfriend->cost) + (target->cost > 0) * target->cost 
					+ (target->bestfriend->cost > 0) * target->bestfriend->cost);
	}
	return (INT_MAX);
}

t_list	*ft_findbestpush(t_list **ahead, t_list **bhead)
{
	t_list *bestnode;
	t_list *tmp;
	int cost;

	bestnode = *bhead;
	cost = 500;
	tmp = *ahead;
	tmp = *bhead;
	while (tmp)
	{
		cost = ft_calculatecost(tmp);
		if (tmp->bestfriend && cost < bestnode->cost)
			bestnode = tmp;
		tmp = tmp->next;
	}
	return (bestnode);
}
void ft_rr(t_list **ahead, t_list **bhead)
{
	ft_rx(ahead, 1);
	ft_rx(bhead, 0);
}
void ft_pushtop(t_list **ahead, t_list **bhead, t_list *target)
{
	int acost;
	int bcost;
	if (!target)
		return;
	acost = target->bestfriend->cost;
	bcost = target->content;
	if ((target->cost > 0 && target->bestfriend->cost > 0) || (target->cost))
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
	t_list *ac;
	t_list *bc;
	t_list *node_to_push;
	int mid;
	int tmp;
	
	tmp = 250;
	ac = *ahead;
	bc = *bhead;
	mid = (*bhead)->prev->index + 1;
	while ((*bhead))
	{
		node_to_push = ft_findbestpush(ahead, bhead);
		if (!node_to_push)
		{
			node_to_push = ft_findsmallest(bhead);
			node_to_push->bestfriend = ft_findsmallest(ahead);
		}
		ft_pushtop(ahead, bhead, node_to_push);
		update_indices(ahead);
		update_indices(bhead);
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
void	ft_lezsort(t_list **ahead, t_list **bhead)
{

	ft_aoitodo(ahead, bhead);
	ft_returntoa(ahead, bhead);
	while (!ft_issorted(ahead))
		ft_rx(ahead, 1);
}
void	ft_pushtob(t_list **ahead, t_list **bhead)
{
	int i;
	int nnodes;
	float nsum;

	nnodes = (*ahead)->prev->index + 1;
	i = 0;
	nsum = ft_nodesum(ahead);
	while (i < nnodes - 3)
	{
		if ((float)(*ahead)->content < nsum / (float)(*ahead)->prev->index + 1)
		{
			nsum -= ((*ahead)->content);
			ft_px(ahead, bhead, 0);
			update_indices(bhead);
			i++;
		}
		else
			ft_rx(ahead, 1);
	}
	ft_sort3(ahead, (*ahead)->next, (*ahead)->next->next);
	update_indices(ahead);
	ft_lezsort(ahead, bhead);
}

void ft_pushswap(t_list **ahead, t_list **bhead)
{
	int i;
	int nnodes;
	*bhead = NULL;
	i = 0;
	nnodes = ft_listcount(*ahead);
	if (nnodes == 1)
		exit (1);
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
