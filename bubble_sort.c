/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:14:52 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/22 16:33:39 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_list *a)
{
	t_list *tmp = a;
	while (tmp)
	{
		ft_printf("%d\t %d\n", tmp->content, tmp->inx);
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
		tmp->inx = i;
		i++;
	}
	return (head);
}

t_sorted_array bubble_sort_array(int *arr, int size)
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
    t_list *sorted_list = arr_add_to_list(arr, size);
    // print_list(sorted_list);

    t_sorted_array result;
    result.sorted_list = sorted_list;

    return result;
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

void update_inx(t_list **a)
{
	int i = 0;
	while (a)
	{
		(*a)->inx = i;
		*a = (*a)->next;
		i++;
	}
}

int find_middle(t_list *a)
{
	int size = ft_lstsize(a);
	int i;

	if (size % 2 == 0)
		size = size / 2;
	else
		size = (size / 2) + 1;
	i = -1;
	while (++i < size)
		a = a->next;
	return (a->inx);
}
t_list *search_min(t_list *a)
{
	t_list *tmp = a;
	t_list *min = a;
	while (tmp)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

int ischeap(t_list *a)
{
	t_list *min = search_min(a);
	int middle = find_middle(a);
	if (min->inx < middle)
		return 1;
	return 0;
}

void bubble_sort(t_list **a, t_list **b)
{
	int size = ft_lstsize(*a);
	int *arr = list_to_array(*a);
	t_sorted_array tmp;
	tmp = bubble_sort_array(arr, size);
	int cheaps = 0;
	while(ft_lstsize(*a) > 3)
	{
		cheaps = ischeap(*a);
		while(cheaps == 1)
		{
			ft_rotates(a, b, 'a');
			if ((*a)->content == tmp.sorted_list->content)
			{
				ft_pushs(a, b, 'b');
				ft_pop(&tmp.sorted_list);
				cheaps++;
			}
		}
		while (cheaps == 0)
		{
			ft_rrotates(a, b, 'a');
			if ((*a)->content == tmp.sorted_list->content)
			{
				ft_pushs(a, b, 'b');
				ft_pop(&tmp.sorted_list);
				cheaps++;
			}
		}
	}
	ft_sort_three(a);
	while (*b)
		ft_pushs(a, b, 'a');
	// print_list(*a);
}
