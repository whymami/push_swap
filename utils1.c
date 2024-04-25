/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:11:40 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/25 19:53:42 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate1(t_list **a, t_list **b, t_list *tmp)
{
	while (tmp->isrr == 1 && tmp->moves)
	{
		ft_rrotates(a, b, 'a');
		tmp->moves--;
	}
	while (tmp->target->isrr == 1 && tmp->target->moves)
	{
		ft_rrotates(a, b, 'b');
		tmp->target->moves--;
	}
	while (tmp->isrr == 0 && tmp->moves)
	{
		ft_rotates(a, b, 'a');
		tmp->moves--;
	}
	while (tmp->target->isrr == 0 && tmp->target->moves)
	{
		ft_rotates(a, b, 'b');
		tmp->target->moves--;
	}
}

void	rotate2(t_list **a, t_list **b, t_list *tmp)
{
	while (tmp->moves && tmp->target->moves)
	{
		ft_rotates(a, b, 'r');
		tmp->moves--;
		tmp->target->moves--;
	}
	while (tmp->moves)
	{
		ft_rotates(a, b, 'a');
		tmp->moves--;
	}
	while (tmp->target->moves)
	{
		ft_rotates(a, b, 'b');
		tmp->target->moves--;
	}
}

void	rotate3(t_list **a, t_list **b, t_list *tmp)
{
	while (tmp->moves && tmp->target->moves)
	{
		ft_rrotates(a, b, 'r');
		tmp->moves--;
		tmp->target->moves--;
	}
	while (tmp->moves)
	{
		ft_rrotates(a, b, 'a');
		tmp->moves--;
	}
	while (tmp->target->moves)
	{
		ft_rrotates(a, b, 'b');
		tmp->target->moves--;
	}
}

t_list	*listindex(int index, t_list **stack)
{
	t_list *tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->inx == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}