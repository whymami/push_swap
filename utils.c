/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:46:04 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/25 19:52:47 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_nbr(t_list *a)
{
	int	min;

	min = a->content;
	a = a->next;
	while (a)
	{
		if (min > a->content)
			min = a->content;
		a = a->next;
	}
	return (min);
}

void	reindex(t_list *stack)
{
	int		i;
	t_list	*tmp;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		tmp->inx = i;
		i++;
		tmp = tmp->next;
	}
}

void	setrr(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->inx <= ft_lstlast(*stack)->inx / 2)
			tmp->isrr = 0;
		else
			tmp->isrr = 1;
		tmp = tmp->next;
	}
}

void	setmoves(t_list **a, t_list **b)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *a;
	tmp2 = *b;
	while (tmp1)
	{
		if (tmp1->isrr == 0)
			tmp1->moves = tmp1->inx;
		else
			tmp1->moves = ft_lstlast(*a)->inx - tmp1->inx + 1;
		tmp1 = tmp1->next;
	}
	if (tmp2)
	{
		while (tmp2)
		{
			if (tmp2->isrr == 0)
				tmp2->moves = tmp2->inx;
			else
				tmp2->moves = ft_lstlast(*b)->inx - tmp2->inx + 1;
			tmp2 = tmp2->next;
		}
	}
}
