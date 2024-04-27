/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:02:28 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/27 18:22:20 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				print_error(&a, NULL);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

static int	issort(t_list **stack)
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

void	ft_control(t_list **a)
{
	ft_isunique(*a);
	if (issort(a))
		exit(0);
}

void	ft_add_stack(char **argv, t_list **a)
{
	int	i;

	i = -1;
	while (argv[++i])
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
}
