/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:19:53 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/27 16:00:41 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_push_a(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if ((*b) == NULL)
		return ;
	tmp2 = (*b);
	tmp = (*b)->next;
	tmp2->next = (*a);
	(*a) = tmp2;
	(*b) = tmp;
	reindex((*a));
	reindex((*b));
	setrr(a);
	setrr(b);
	setmoves(a, b);
}

static void	ft_push_b(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if ((*a) == NULL)
		return ;
	tmp2 = (*a);
	tmp = (*a)->next;
	tmp2->next = (*b);
	(*b) = tmp2;
	(*a) = tmp;
	reindex((*a));
	reindex((*b));
	setrr(a);
	setrr(b);
	setmoves(a, b);
}

void	ft_pushs(t_list **a, t_list **b, char id)
{
	if (id == 'a' && ft_printf("pa\n"))
		ft_push_a(a, b);
	else if (id == 'b' && ft_printf("pb\n"))
		ft_push_b(a, b);
	else if (id == 's' && ft_printf("ss\n"))
	{
		ft_push_a(a, b);
		ft_push_b(a, b);
	}
}
