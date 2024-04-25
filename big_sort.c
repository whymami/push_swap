/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:08:09 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/25 20:12:00 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	laststep(t_list **a, t_list **b)
{
	while (listindex(get_large(b), b)->moves)
	{
		if (listindex(get_large(b), b)->isrr == 1)
			ft_rrotates(a, b, 'b');
		else
			ft_rotates(a, b, 'b');
		listindex(get_large(b), b)->moves--;
	}
	while (*b)
		ft_pushs(a, b, 'a');
}

static t_list	*get_min_moves(t_list **a)
{
	t_list	*tmp;
	t_list	*ret;

	tmp = *a;
	ret = tmp;
	while (tmp)
	{
		if (tmp->target->moves + tmp->moves < ret->target->moves + ret->moves)
			ret = tmp;
		else if (tmp->target->moves + tmp->moves == ret->target->moves
			+ ret->moves)
		{
			if (tmp->target->isrr == ret->target->isrr
				&& ret->isrr != ret->target->isrr)
				ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

static void	gettarget(t_list **a, t_list **b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	while (tmp_a)
	{
		tmp_a->target = listindex(get_smallest(b), b);
		while (tmp_b)
		{
			if (tmp_a->content > tmp_b->content
				&& tmp_a->target->content < tmp_b->content)
				tmp_a->target = tmp_b;
			tmp_b = tmp_b->next;
		}
		if (tmp_a->target->content > tmp_a->content)
			tmp_a->target = listindex(get_large(b), b);
		tmp_b = *b;
		tmp_a = tmp_a->next;
	}
}

void	big_sort(t_list **a, t_list **b)
{
	t_list	*tmp;

	ft_pushs(a, b, 'b');
	ft_pushs(a, b, 'b');
	while (*a)
	{
		gettarget(a, b);
		tmp = get_min_moves(a);
		if (tmp->isrr != tmp->target->isrr)
			rotate1(a, b, tmp);
		else if (tmp->isrr == tmp->target->isrr)
		{
			if (tmp->isrr == 0)
				rotate2(a, b, tmp);
			else
				rotate3(a, b, tmp);
		}
		ft_pushs(a, b, 'b');
	}
	laststep(a, b);
}
