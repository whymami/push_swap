/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:54:40 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/18 16:23:45 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_three(t_list **a)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = (*a)->content;
	a2 = (*a)->next->content;
	a3 = (*a)->next->next->content;
	if (a1 > a2 && a1 < a3)
		ft_swap_a(a);
	else if (a1 < a2 && a1 > a3)
		ft_reverse_rotate_a(a);
	else if (a1 > a2 && a1 > a3 && a2 < a3)
		ft_rotate_a(a);
	else if (a1 > a2 && a1 > a3 && a2 > a3)
	{
		ft_swap_a(a);
		ft_reverse_rotate_a(a);
	}
	else if (a1 < a2 && a1 < a3 && a2 > a3)
	{
		ft_swap_a(a);
		ft_rotate_a(a);
	}
}

static void	ft_sort_four(t_list **a, t_list **b)
{
	int	min;
	int	i;

	i = 0;
	min = find_min_nbr(*a);
	while (i < 1)
	{
		if ((*a)->content == min)
		{
			ft_push_b(a, b);
			i++;
		}
		else
			ft_rotate_a(a);
	}
	ft_sort_three(a);
	ft_push_a(a, b);
}

static void	ft_sort_five(t_list **a, t_list **b)
{
	int	min;
	int	i;

	min = find_min_nbr(*a);
	i = 0;
	while (i < 2)
	{
		if ((*a)->content == min)
		{
			ft_push_b(a, b);
			i++;
			min = find_min_nbr(*a);
		}
		else
			ft_rotate_a(a);
	}
	ft_sort_three(a);
	while (*b)
		ft_push_a(a, b);
}

void	ft_sort(t_list **a, t_list **b, int size)
{
	if (size == 2)
		ft_swap_a(a);
	else if (size == 3)
		ft_sort_three(a);
	else if (size == 4)
		ft_sort_four(a, b);
	else if (size == 5)
		ft_sort_five(a, b);
}
