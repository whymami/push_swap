/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:18:55 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/21 15:31:39 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_swap_a(t_list **a)
{
	t_list	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
}

static void	ft_swap_b(t_list **b)
{
	t_list	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;
}

static void	ft_run_ss(t_list **a, t_list **b)
{
	ft_swap_a(a);
	ft_swap_b(b);
}

void ft_swaps(t_list **a, t_list **b, char id)
{
	if (id == 'a' && ft_printf("sa\n"))
		ft_swap_a(a);
	else if (id == 'b' && ft_printf("sb\n"))
		ft_swap_b(b);
	else if (id == 'e' && ft_printf("ss\n"))
		ft_run_ss(a, b);
}