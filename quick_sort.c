/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:14:52 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/18 18:06:19 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_list *a)
{
	t_list *tmp = a;
	while (tmp)
	{
		ft_printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
}

t_list *partition(t_list *head, t_list *end, t_list **newHead, t_list **newEnd) {
    t_list *pivot = end;
    t_list *prev = NULL, *current = head, *tail = pivot;

    while (current != pivot) {
        if (current->content < pivot->content) {
            if ((*newHead) == NULL)
                (*newHead) = current;
            prev = current;
            current = current->next;
        } else {
            if (prev)
                prev->next = current->next;
            t_list *tmp = current->next;
            current->next = NULL;
            tail->next = current;
            tail = current;
            current = tmp;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}

t_list *quick_sort_rec(t_list *head, t_list *end) {
    if (!head || head == end)
        return head;

    t_list *newHead = NULL, *newEnd = NULL;

    t_list *pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        t_list *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        newHead = quick_sort_rec(newHead, tmp);

        tmp = ft_lstlast(newHead);
        tmp->next = pivot;
    }

    pivot->next = quick_sort_rec(pivot->next, newEnd);

    return newHead;
}

void quick_sort(t_list **head) 
{
	ft_printf("sıralanmış liste\n");
	print_list(*head);
    (*head) = quick_sort_rec(*head, ft_lstlast(*head));
	ft_printf("sıralanmış liste\n");
	print_list(*head);
}

