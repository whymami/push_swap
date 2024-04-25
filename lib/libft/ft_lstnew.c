/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:59:08 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/25 19:58:01 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	static int	inx;
	t_list		*p;

	p = malloc(sizeof(t_list));
	if (!p)
		return (0);
	p->inx = inx++;
	p->content = content;
	p->next = NULL;
	p->isrr = -1;
	p->moves = -1;
	p->target = NULL;
	return (p);
}
