/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:21:43 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/21 15:42:29 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_rotate_a(t_list **a)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp2 = *a;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
}

static void	ft_rotate_b(t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp2 = *b;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
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