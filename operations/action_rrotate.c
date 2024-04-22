/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rrotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:23:39 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/21 15:30:49 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reverse_rotate_a(t_list **a)

{
	t_list	*tmp;
	t_list	*tmp2;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	tmp2 = *a;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	*a = tmp2->next;
	tmp2->next = NULL;
	(*a)->next = tmp;
}

void	ft_reverse_rotate_b(t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	tmp2 = *b;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	*b = tmp2->next;
	tmp2->next = NULL;
	(*b)->next = tmp;
}

void	ft_run_rrr(t_list **a, t_list **b)
{
	ft_reverse_rotate_a(a);
	ft_reverse_rotate_b(b);
}

void	ft_rrotates(t_list **a, t_list **b, char id)
{
	if (id == 'a' && ft_printf("rra\n"))
		ft_reverse_rotate_a(a);
	else if (id == 'b' && ft_printf("rrb\n"))
		ft_reverse_rotate_b(b);
	else if (id == 'r' && ft_printf("rrr\n"))
		ft_run_rrr(a, b);
}
