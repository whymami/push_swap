/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:46:04 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/25 13:57:11 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min_nbr(t_list *a)
{
	int min;

	min = a->content;
	a = a->next;
	while (a)
	{
		if (min > a->content)
			min = a->content;
		a = a->next;
	}
	return (min);
}

int ft_isint(long n)
{
	if ((n > 2147483647 || n < -2147483648) && ft_printf("int değil\n"))
		exit(1);
	return (1);
}

void	reindex(t_list *stack)
{
	int		i;
	t_list	*tmp;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		tmp->inx = i;
		i++;
		tmp = tmp->next;
	}
}