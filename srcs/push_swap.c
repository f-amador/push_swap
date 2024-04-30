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

void ft_pushswap(t_list **ahead, t_list **bhead)
{
	int nnodes;

	nnodes = ft_listcount(*ahead);
	if (nnodes == 1)
		return ;
	else if (nnodes == 2)
	{
		if (ft_issorted(ahead))
			return ;
		ft_rx(ahead, 1);
		return ;
	}
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
-1060297706 563075913 -1435250169 -1373224343 875917615 -996475543 1382987290 -880603089 1955419747 -730071431 1152138060 -432369545 -2021695108 -11608797 -442254694 1125795487 2078505982 -1857752879 -1205965691 -1374775675 -1310682170 1402776860 -2028346227 -1759727240 -1626313940 460049798 -100182695 -1924592802 218970877 1927886084 1926071273 -1558195825 -1331106856 839662783 -2033586581 1537341407 -791382484 1261595206 1612836209 -1163155321 1094202071 -1828587040 -1301049596 775885053 282203116 1691763921 -1958767024 196428790 -1996647551 340230421 -728949057 -827938833 -328784247 -1904597784 -1238735578 -2048262076 1537607824 -459998632 -1872859536 1229555237 54307613 -2005894828 -1447003745 -2049768524 1325203892 1643989971 -1104788029 333488745 1528948698 1524044315 -988925154 464569419 -1810401773 729317907 -493838488 -539233966 -1312227575 -497386763 318128961 773087943 2027856138 -858694010 1436964204 243659195 458666725 1950476867 -1490720701 587126521 -1038601991 -442622970 -532885082 1749509763 -1316838899 1912187954 -1057113392 355884738 1863134263 -2013145425 -2057772064 1169032349
