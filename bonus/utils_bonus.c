/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:51:45 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/27 16:00:35 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_add_stack(char **argv, t_list **a)
{
	int	i;

	i = -1;
	while (argv[++i])
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
}

static void	ft_isunique(t_list *a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->content == tmp2->content)
				print_error_bonus(&a, NULL);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

int	issort_bonus(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_control_bonus(char **listed_all, t_list **a)
{
	ft_add_stack(listed_all, a);
	ft_isunique(*a);
}

void	print_error_bonus(t_list **a, t_list **b)
{
	if (a != NULL && b != NULL)
	{
		ft_lstclear(a, b);
		free(a);
		free(b);
	}
	ft_printf("Error\n");
	exit(1);
}
