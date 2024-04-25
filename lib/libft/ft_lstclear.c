/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:56:33 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/25 19:10:18 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **a, t_list **b)
{
	t_list	*tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	while (*b)
	{
		tmp = (*b)->next;
		free(*b);
		*b = tmp;
	}
	free(*a);
	free(*b);
}
