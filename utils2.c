/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:31:26 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/25 20:06:24 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_large(t_list **b)
{
	t_list	*tmp;
	int		large;
	int		index;

	tmp = *b;
	large = tmp->content;
	index = tmp->inx;
	while (tmp)
	{
		if (tmp->content > large)
		{
			large = tmp->content;
			index = tmp->inx;
		}
		tmp = tmp->next;
	}
	return (index);
}

int	get_smallest(t_list **b)
{
	t_list	*tmp;
	int		smallest;
	int		index;

	tmp = *b;
	smallest = tmp->content;
	index = tmp->inx;
	while (tmp)
	{
		if (tmp->content < smallest)
		{
			smallest = tmp->content;
			index = tmp->inx;
		}
		tmp = tmp->next;
	}
	return (index);
}

void	print_error(t_list **a, t_list **b)
{
	if (a != NULL && b != NULL)
		ft_lstclear(a, b);
	ft_printf("Error\n");
	exit(1);
}

void	dispose_split_list(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}
