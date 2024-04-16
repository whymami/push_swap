/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:27:03 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/16 13:37:52 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap_a(t_list **a)
{
	t_list *tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
	ft_printf("sa\n");
}

void ft_swap_b(t_list **b)
{
	t_list *tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp =  (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;
	ft_printf("sb\n");
}

void ft_run_ss(t_list **a, t_list **b)
{
	ft_swap_a(a);
	ft_swap_b(b);
	ft_printf("ss\n");
}

void ft_push_a(t_list **a, t_list **b)
{
	t_list *tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	ft_printf("pa\n");
}

void ft_push_b(t_list **a, t_list **b)
{
	t_list *tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	ft_printf("pb\n");
}

void ft_rotate_a(t_list **a)
{
	t_list *tmp;
	t_list *tmp2;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp2 = *a;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	ft_printf("ra\n");
}

void ft_rotate_b(t_list **b)
{
	t_list *tmp;
	t_list *tmp2;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp2 = *b;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	ft_printf("rb\n");
}

void ft_run_rr(t_list **a, t_list **b)
{
	ft_rotate_a(a);
	ft_rotate_b(b);
	ft_printf("rr\n");
}

void ft_reverse_rotate_a(t_list **a)
{
	t_list *tmp;
	t_list *tmp2;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	tmp2 = *a;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	*a = tmp2->next;
	tmp2->next = NULL;
	(*a)->next = tmp;
	ft_printf("rra\n");
}

void ft_reverse_rotate_b(t_list **b)
{
	t_list *tmp;
	t_list *tmp2;

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

void ft_run_rrr(t_list **a, t_list **b)
{
	ft_reverse_rotate_a(a);
	ft_reverse_rotate_b(b);
	ft_printf("rrr\n");
}