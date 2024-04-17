/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:51:40 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/17 13:53:18 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_run_rr(t_list **a, t_list **b)
{
	ft_rotate_a(a);
	ft_rotate_b(b);
	ft_printf("rr\n");
}

void	ft_run_rrr(t_list **a, t_list **b)
{
	ft_reverse_rotate_a(a);
	ft_reverse_rotate_b(b);
	ft_printf("rrr\n");
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
	ft_printf("rrb\n");
}
