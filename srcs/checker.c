
#include "../include/push_swap.h"

int ft_strcmp(char *s, char *t)
{
	int i;

	i = 0;
	while (s[i] == t[i])
	{
		i++;
		if (!s[i])
			return (1);
	}
	return (0);
}

size_t	ft_strleng(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s && s[i])
	{
		if (s[i] == 10)
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_strjoing(char *s1, char const *s2)
{
	char	*str;
	size_t	j;
	size_t	i;

	str = (char *)malloc(ft_strleng(s1) + ft_strleng(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && j < ft_strleng(s2))
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	if (s1)
		free(s1);
	return (str);
}

void	ft_buffflusher(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < BUFFER_SIZE && buff[i] != 10)
		i++;
	if (buff[i] == 10 && i < BUFFER_SIZE)
		i++;
	while (i < BUFFER_SIZE)
	{
		buff[j] = buff[i];
		buff[i] = 0;
		i++;
		j++;
	}
	while (j < BUFFER_SIZE)
		buff[j++] = 0;
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	buff[BUFFER_SIZE + 1];

	str = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0 || fd >= FOPEN_MAX)
	{
		if (BUFFER_SIZE > 0)
		{
			ft_buffflusher(buff);
			return (NULL);
		}
	}
	while (buff[0] || read(fd, buff, BUFFER_SIZE) > 0)
	{
		str = ft_strjoing(str, buff);
		ft_buffflusher(buff);
		if (str[ft_strleng(str) - 1] == 10)
			break ;
	}
	return (str);
}


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

t_list *ft_lastnode(t_list **ahead)
{
    t_list *node;

    if (!(*ahead))
        return (NULL);
    node = *ahead;
    while (node->next != NULL)
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
    new_node->bestfriend = NULL;
    new_node->content = res;
    new_node->next = NULL;
    if (*ahead == NULL)
    {
        new_node->prev = NULL;
        *ahead = new_node;
    }
    else
    {
        last_node = *ahead;
        while (last_node->next != NULL)
            last_node = last_node->next;
        last_node->next = new_node;
        new_node->prev = last_node;
    }
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
void ft_rrx(t_list **ahead)
{
    t_list *lastnode;
    t_list *secondlastnode;

    if (ahead == NULL || *ahead == NULL || (*ahead)->next == NULL)
        return;

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
}

void ft_px(t_list **src, t_list **dest)
{
    t_list *tmp;

    if (src == NULL || *src == NULL)
        return;

    tmp = *src;
    *src = (*src)->next;
    if (*src != NULL)
        (*src)->prev = tmp->prev;

    if (*dest != NULL) {
        tmp->next = *dest;
        tmp->prev = (*dest)->prev;
        (*dest)->prev = tmp;
        if ((*dest)->prev != NULL)
            (*dest)->prev->next = *dest;
    } else {
        tmp->next = NULL;
        tmp->prev = NULL;
    }

    *dest = tmp;
}
void ft_rx(t_list **ahead)
{
    t_list *firstnode;
    t_list *lastnode;

    if (ahead == NULL || *ahead == NULL || (*ahead)->next == NULL)
        return;
    firstnode = *ahead;
    *ahead = (*ahead)->next;
    (*ahead)->prev = NULL;
    lastnode = *ahead;
    while (lastnode->next != NULL)
        lastnode = lastnode->next;
    lastnode->next = firstnode;
    firstnode->prev = lastnode;
    firstnode->next = NULL;
}

void ft_sx(t_list **ahead)
{
    t_list *firstnode, *secondnode;

    if (ahead == NULL || *ahead == NULL || (*ahead)->next == NULL)
        return;

    firstnode = *ahead;
    secondnode = (*ahead)->next;
    firstnode->next = secondnode->next;
    if (secondnode->next != NULL)
        secondnode->next->prev = firstnode;

    secondnode->next = firstnode;
    firstnode->prev = secondnode;

    *ahead = secondnode;
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


void ft_ss(t_list **ahead, t_list **bhead)
{
	ft_sx(ahead);
	ft_sx(bhead);
}

void ft_rr(t_list **ahead, t_list **bhead)
{
	ft_rx(ahead);
	ft_rx(bhead);
}

void ft_rrr(t_list **ahead, t_list **bhead)
{
	ft_rrx(ahead);
	ft_rrx(bhead);
}

void ft_moves(t_list **ahead, t_list **bhead)
{
	char *line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strcmp(line, "sa\n"))
			ft_sx(ahead);
		else if (ft_strcmp(line, "sb\n"))
			ft_sx(bhead);
		else if (ft_strcmp(line, "ss\n"))
			ft_ss(ahead, bhead);
		else if (ft_strcmp(line, "ra\n"))
			ft_rx(ahead);
		else if (ft_strcmp(line, "rb\n"))
			ft_rx(bhead);
		else if (ft_strcmp(line, "rr\n"))
			ft_rr(ahead, bhead);
		else if (ft_strcmp(line, "rra\n"))
			ft_rrx(ahead);
		else if (ft_strcmp(line, "rrb\n"))
			ft_rrx(bhead);
		else if (ft_strcmp(line, "rrr\n"))
			ft_rrr(ahead, bhead);
		else if (ft_strcmp(line, "pb\n"))
			ft_px(ahead, bhead);
		else if (ft_strcmp(line, "pa\n"))
			ft_px(bhead, ahead);
		else 
			break;
		printf("NEWMOVE\n");
		t_list *temp = *ahead;
		while (temp != NULL) 
		{
    		printf("%d\n", temp->content);
    		temp = temp->next;
		}
		free(line);
		line = get_next_line(0);
	}
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
		}
	ft_clearlst(ahead);
	free(ahead);
	free(bhead);
	return (write(1, "Acertou miseravi\n", 17));
}

