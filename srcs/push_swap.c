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
	if (i == 1)
		return (write(1, "rra\n", 4));
	else if (i == 0)
		return (write(1, "rrb\n", 4));
	else
	return (0);
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
	if (i == 1)
		return (write(1, "ra\n", 3));
	else if (i == 0)
		return (write(1, "rb\n", 3));
	else
		return (0);

}
int	ft_sx(t_list **ahead, int i)
{
	t_list *firstnode, *secondnode, *lastnode;

	if (ahead == NULL || *ahead == NULL || (*ahead)->next == NULL)
		return (0);
	firstnode = *ahead;
	secondnode = (*ahead)->next;
	lastnode = firstnode->prev; 
	firstnode->next = secondnode->next;
	if (secondnode->next != NULL)
		secondnode->next->prev = firstnode;
	secondnode->next = firstnode;
	firstnode->prev = secondnode;
	*ahead = secondnode;
	(*ahead)->prev = lastnode; 
	if (lastnode != NULL)
		lastnode->next = NULL; 
	if (i == 1)
		return (write(1, "sa\n", 3));
	else if (!i)
		return (write(1, "sb\n", 3));
	return (0);
}
int ft_ss(t_list **ahead, t_list **bhead)
{
	write(1, "ss\n", 3);
	return (ft_sx(ahead, 2) + ft_sx(bhead, 2));
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

void ft_fillcost(t_list **head, t_list *target)
{
	int mid;

	mid = (((*head)->prev->index + 1) / 2);
	if (target->index <= mid)
		target->cost = target->index;
	else
		target->cost = (target->index - (*head)->prev->index - 1);
}


void update_indices(t_list **head)
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


int ft_calculatecost(t_list *target)
{
	if (target->cost == 0)
		return (target->bestfriend->cost);
	if (target->bestfriend->cost == 0)
		return (target->cost);
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
		{
			return((target->cost < 0) * -(target->cost) + (target->bestfriend->cost < 0) * -(target->bestfriend->cost) + (target->cost > 0) * target->cost + (target->bestfriend->cost > 0) * target->bestfriend->cost);
		}
	}
	return (INT_MAX);
}

t_list *ft_findbestpush(t_list **bhead)
{
	t_list *bestnode;
	t_list *tmp;
	int	bestnodecost;
	int	cost;
	
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
			}
		}
		tmp = tmp->next;
	}
	return (bestnode);
}

void ft_rr(t_list **ahead, t_list **bhead)
{
	write(1, "rr\n", 3);
	ft_rx(ahead, 2);
	ft_rx(bhead, 2);
}

void ft_rrr(t_list **ahead, t_list **bhead)
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
	//printf("topa:%d\n, topb:%d\n", (*ahead)->content, (*bhead)->content);
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
		//printf("bestnodea: %d\nbestnodeb:%d\n", node_to_push->bestfriend->content, node_to_push->content);
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
	update_indices(ahead);
	ft_lezsort(ahead, bhead);
}

void ft_pushswap(t_list **ahead, t_list **bhead)
{
	int nnodes;

	*bhead = NULL;
	nnodes = ft_listcount(*ahead);
	if (nnodes == 1)
		exit (1);
	else if (nnodes == 3)
		ft_sort3(ahead, (*ahead)->next, (*ahead)->next->next);
	else
		ft_pushtob(ahead, bhead);
}
/*int	main(int ac, char *av[])
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
}*/
/*-2089414366 -558226795 240849921 -1538159147 116784269 -1595344287 14829070 -2132513932 -1744134982 -300110210 -1317226879 830109297 64464873 2019020817 -1565327051 430128250 1485388978 -784302678 -1028669256 182432648 759119867 67719019 727213273 1256302098 -1142464728 393434592 802475784 -577122963 -1947244840 -1659887096 -1482030674 -442508331 1715885678 -526927120 1471925735 366391751 1266228066 -858933167 2144572324 820510556 1837548102 -1564400977 -1646745881 906724904 1452960502 871268097 384049820 -1586817446 1846351115 1478336865 823770590 -181809736 -1882647153 -450305033 -1584801900 -778097803 -1995093448 -650478184 498531813 612719173 1231067818 737083628 -561250041 -1665313874 -1758804374 1923401658 -272623366 -50863838 2059633160 1876226878 1769649474 397088666 945325877 -713657604 1636227398 -693647773 -654258531 780869759 959088933 -685586024 -89395405 1596878824 -1563982271 490099350 1960285253 -1586437592 -794538155 -1162834380 228387005 -1771138324 -1485677891 1822857363 577720658 -1741577992 1586361226 1292121740 -627038375 822446485 -297367650 -1945579551 810604906 -1129821053 -1434944376 48830442 -277539437 870543580 896037569 1464356396 -687040719 -1765545937 230410022 1288626978 1177277736 2018641271 1786923567 809596727 -348886272 -307251200 -1845035923 -400416442 -1206762380 -2042511886 -356353288 -803939120 -1985052462 -2135334899 -1299882674 216009481 -1189587979 -29883129 752277976 304956066 1206193906 -2063575845 1712939532 -1920118883 468304501 -1861480123 -376789767 35235149 -623454697 1930579679 -1836865096 844881177 75432349 -1992606241 20079449 -766879882 -432417841 -407699576 -1272704566 1238612605 248828379 -2072384174 836094887 -937874891 806976973 211041739 1648970259 -1146244801 -432774992 772079018 -916206641 1107760892 1404333923 856566739 352648988 -2140843666 -1890566135 660862310 -15650165 152638755 -545993439 -662984041 -270938601 1062141305 1096308563 -959807162 105922140 1623872994 -711544826 -159587891 10347529 903501571 -2047501070 -326922358 1192063783 1418944108 -1391699498 1589772670 992299425 -940542031 41435165 1046432990 -521954331 -1599049604 -2102690014 -1468954495 -1123487251 1451103044 1365270145 265958281 655007245 1051679427 -871345980 1277999564 -1969813302 -2041583650 -718376547 1472247201 -1324238274 1098381934 -1741095583 -393561420 -775817038 2124889056 1454016083 -281096700 1430208896 85372290 1908351973 690242896 -416981408 -593626562 891072558 444906560 1185554036 1922010060 -492390143 -593622531 689107701 -2004759911 -1095605363 1053812867 -1578496228 264442723 -1911024045 -1495682296 -1890569429 -1768358035 -1933825059 -1428698590 2081689144 -2034810800 1020590523 -1435442691 1146877497 -2136977316 -1450935997 -130390971 60010030 1878920003 1622776642 -1644922951 723463167 1226202923 2117399408 34010769 -1195237549 -13248181 1706219440 -1803702587 -198522330 -947766149 -231079302 -1435997543 -1455555630 -1145363297 1026441818 227443896 -1402439871 1115279064 1658961290 -811906254 197036395 1733534761 -972405137 1778227288 -1815550169 -849959002 -1248772376 316129813 1871248590 999562003 13000433 84615183 778034798 -99819658 -707526214 1499462669 1306025686 1387375409 1931793257 -1023793025 1123922607 491591011 -1941849376 -1991929849 1344608402 -1223617042 -127955301 -582477365 -1398630570 -1744671815 -1599860353 -1778890570 -309202158 -1063285435 402376775 692305691 -631412621 1244012071 347987394 -563039647 -1998231600 -1520985669 713079933 1941597258 -31641738 1714219637 1158484961 1932302320 1385426132 -1225167442 -1179430731 211319628 1528817157 -628691744 21142510 319721337 -248154972 -927575177 211747462 -2042264674 253489128 1928217966 -783863477 -1612675384 -1283618319 170808428 -925482525 -2118684537 1030974521 -2140511238 498007956 -10323302 -707867564 421423699 -1654206006 1917460326 1159100496 -605924906 502383491 -904356428 964364743 -704453466 -1057562224 917060192 495013798 -544003591 1728189063 956464319 -312404641 -1819209009 -1227278646 67634330 1225878266 2089621266 -1222818580 421652333 -684940470 60900587 126635653 -135006612 2080002026 -246099260 524536258 1948895601 -56498203 -2042311022 -983611986 1308433084 1947790716 -1009100708 -1547126922 487046631 -1695863643 -996405076 108502506 -1997790526 364529433 -1691562376 134476211 287292886 -744701798 -1204368681 -1479034801 3673854 -1164593033 563392070 84797277 1458701318 -474434798 1229058613 -1866835424 -2005775929 -360055478 1654009935 1511495186 2062063006 -458883373 496960260 -854924266 845969515 90642326 1852156722 -349232622 -61908988 649175987 156732705 1819175732 -957561864 -1492475606 1706346481 -1200812403 1026992436 1508295152 2075829536 -1657567000 1282109422 1572358236 342506324 -1664569503 1643304723 2043493311 1743205243 -511706698 1666871760 1888088314 1475533420 1963863282 -294221115 935095546 -319699367 -1291619376 896208198 -1820164104 1599739564 1934968860 1602844879 1326377545 1987890028 490129711 651194486 1551719265 738465924 -1073475750 -1272704193 -2025843943 -1041685252 -370194162 1741548348 887099859 -769988743 -2045060812 1383503416 2064449400 -1421175756 -1012422779 -747204329 1123806647 903644956 -1561217587 765789458 -1573859167 707273682 1138399351 -1789204624 -244309986 1675346638 581327688 915199939 1916131098 -768779871 754947611 657731765 -1824500731 -543947603 -691755989 -1961290798 -342768417 1198019375 -1309947803 -1053124206 -705307639 -190202858 574665559 -2134798439 1115896874 1085053849*/
