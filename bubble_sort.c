/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:14:52 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/19 17:46:01 by muguveli         ###   ########.fr       */
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

static int *list_to_array(t_list *a)
{
	int i = 0;
	int *arr = malloc(sizeof(int) * ft_lstsize(a) + 1);

	while (a)
	{
		arr[i] = a->content;
		a = a->next;
		i++;
	}
	return (arr);
}

static t_list *arr_add_to_list(int *arr, int size)
{
	t_list *tmp = NULL;
	t_list *head = NULL;
	int i = 0;

	while (i < size)
	{
		if (!tmp)
		{
			tmp = ft_lstnew(arr[i]);
			head = tmp;
		}
		else
		{
			tmp->next = ft_lstnew(arr[i]);
			tmp = tmp->next;
		}
		i++;
	}
	return (head);
}

static t_list *bubble_sort_array(int *arr, int size)
{
	int i = 0;
	int j = 0;

	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
				ft_swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}

	t_list *tmp = arr_add_to_list(arr, size);
	return (tmp);
}
#include "unistd.h"


int ft_issorted(t_list *a, int *arr) {
    int i = 0;
    while (a && arr[i] != '\0') {
        if (a->content != arr[i])
            return 0;
        a = a->next;
        i++;
    }
    if (a || arr[i] != '\0')
        return 0;
    return 1;
}

//listenin ilk elemanını silen fonksiyon
void ft_pop(t_list **a)
{
	t_list *tmp = *a;
	*a = (*a)->next;
	free(tmp);
}

void bubble_sort(t_list **a, t_list **b)
{
	int size = ft_lstsize(*a);
	int *arr = list_to_array(*a);
	t_list *sorted_list = bubble_sort_array(arr, size);
	while(sorted_list)
	{
		if((*a)->content != sorted_list->content)
			ft_rotate_a(a);
		else
		{
			ft_push_b(a, b);
			ft_pop(&sorted_list);
		}
	}
	while (*b)
		ft_push_a(a, b);
	print_list(*a);
}
