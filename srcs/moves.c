#include "../include/push_swap.h"

int	ft_rx(t_list **ahead, int i)
{
	t_list	*firstnode;
	t_list	*lastnode;

	lastnode = (*ahead)->prev;
	firstnode = *ahead;
	*ahead = (*ahead)->next;
	lastnode->next = firstnode;
	firstnode->prev = lastnode;
	firstnode->next = NULL;
	(*ahead)->prev = firstnode;
	if (i == 1)
		return (write(1, "ra\n", 3));
	else if (i == 0)
		return (write(1, "rb\n", 3));
	else
		return (0);
}

int	ft_sx(t_list **ahead, int i)
{
	t_list	*firstnode;
	t_list	*secondnode;
	t_list	*lastnode;

	firstnode = *ahead;
	secondnode = (*ahead)->next;
	lastnode = firstnode->prev;
	firstnode->next = secondnode->next;
	secondnode->next->prev = firstnode;
	secondnode->next = firstnode;
	firstnode->prev = secondnode;
	*ahead = secondnode;
	(*ahead)->prev = lastnode;
	if (i == 1)
		return (write(1, "sa\n", 3));
	else if (!i)
		return (write(1, "sb\n", 3));
	return (0);
}

int	ft_ss(t_list **ahead, t_list **bhead)
{
	write(1, "ss\n", 3);
	return (ft_sx(ahead, 2) + ft_sx(bhead, 2));
}

void	ft_clearlst(t_list **ahead, t_list **bhead, char *line)
{
	t_list	*tmp;
	t_list	*next_node;

	tmp = *ahead;
	if (line)
		free(line);
	line = NULL;
	while (tmp)
	{
		next_node = tmp->next;
		free(tmp);
		tmp = next_node;
	}
	free(bhead);
	free(ahead);
	exit(0);
}

void	ft_atol(char *line, t_list **ahead, t_list **bhead)
{
	int		i;
	long	sig;
	long	res;

	i = 0;
	while (line[i])
	{
		res = 0;
		sig = 1;
		while (line[i] == 32)
			i++;
		if (line[i] == 45)
			sig = (line[i++] * 0 - 1);
		else if (line[i] == 43)
			i++;
		while (line[i] >= '0' && line[i] <= '9')
		{
			res = res * 10 + line[i++] - '0';
			if ((res * sig) > INT_MAX || (res * sig) < INT_MIN)
				ft_error(ahead, bhead, line);
		}
		ft_stackadd(((int)res * sig), ahead);
	}
	if (ft_checkdup(*ahead))
		ft_error(ahead, bhead, line);
}
