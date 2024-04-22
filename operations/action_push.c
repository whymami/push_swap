/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:19:53 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/21 15:42:25 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_push_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

static void	ft_push_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}

void	ft_pushs(t_list **a, t_list **b, char id)
{
	if (id == 'a' && ft_printf("pa\n"))
		ft_push_a(a, b);
	else if (id == 'b' && ft_printf("pb\n"))
		ft_push_b(a, b);
}