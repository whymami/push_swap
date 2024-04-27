/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rrotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:43:16 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/27 15:59:58 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	rra(t_list **a)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *a;
	*a = tmp2;
}

void	rrb(t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *b;
	*b = tmp2;
}

void	ft_rrotates(t_list **a, t_list **b, char id)
{
	if (id == 'a')
		rra(a);
	else if (id == 'b')
		rrb(b);
	else
	{
		rra(a);
		rrb(b);
	}
}
