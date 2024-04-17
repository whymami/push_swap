/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:14:52 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/17 20:30:55 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_mid(t_list *a)
{
	int mid = ft_lstsize(a) / 2;
	t_list *tmp = a;
	while(mid--)
		tmp = tmp->next;
	return (tmp->content);
}


static void partition(t_list **a, t_list **b, int pivot, int size) {
    int i = 0;

    while (i < size) {
        if ((*a)->content >= pivot)
            ft_push_b(a, b);
        else
            ft_rotate_a(a);
        i++;
    }
}

void quick_sort(t_list **a, t_list **b, int size) {
    if (!a || !*a || size <= 1)
        return;

    int pivot = find_mid(*a);
    partition(a, b, pivot, ft_lstsize(*a));
	quick_sort(a, b, ft_lstsize(*a));
	quick_sort(b, a, ft_lstsize(*b));
}