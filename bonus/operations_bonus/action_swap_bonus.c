/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_swap_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:43:37 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/27 16:00:00 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	sa(t_list **a)
{
	t_list	*tmp;
	int		temp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	temp = tmp->content;
	tmp->content = tmp->next->content;
	tmp->next->content = temp;
}

void	sb(t_list **b)
{
	t_list	*tmp;
	int		temp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	temp = tmp->content;
	tmp->content = tmp->next->content;
	tmp->next->content = temp;
}

void	ft_swaps(t_list **a, t_list **b, char id)
{
	if (id == 'a')
		sa(a);
	else if (id == 'b')
		sb(b);
	else
	{
		sa(a);
		sb(b);
	}
}
