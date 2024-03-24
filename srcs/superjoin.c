#include "../include/push_swap.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
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
	//if (s1)
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

