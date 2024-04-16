/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:27:03 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/16 11:33:45 by muguveli         ###   ########.fr       */
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
}

void ft_run_ss(t_list **a, t_list **b)
{
	ft_swap_a(a);
	ft_swap_b(b);
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
}

void ft_run_rr(t_list **a, t_list **b)
{
	ft_rotate_a(a);
	ft_rotate_b(b);
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
}

void ft_run_rrr(t_list **a, t_list **b)
{
	ft_reverse_rotate_a(a);
	ft_reverse_rotate_b(b);
}