/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:21:43 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/25 17:32:39 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_rotate_a(t_list **a)
{
	t_list	*tmp;

	tmp = (*a)->next;
	ft_lstlast((*a))->next = (*a);
	(*a)->next = NULL;
	(*a) = tmp;
}

static void	ft_rotate_b(t_list **b)
{
	t_list	*tmp;

	tmp = (*b)->next;
	ft_lstlast((*b))->next = (*b);
	(*b)->next = NULL;
	(*b) = tmp;
}

void	ft_run_rr(t_list **a, t_list **b)
{
	ft_rotate_a(a);
	ft_rotate_b(b);
}

void	ft_rotates(t_list **a, t_list **b, char id)
{
	if (id == 'a' && ft_printf("ra\n"))
		ft_rotate_a(a);
	else if (id == 'b' && ft_printf("rb\n"))
		ft_rotate_b(b);
	else if (id == 'r' && ft_printf("rr\n"))
		ft_run_rr(a, b);
}