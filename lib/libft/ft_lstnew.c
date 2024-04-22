/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:59:08 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/22 14:43:53 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	static	int	inx = 0;
	t_list	*p;

	p = malloc(sizeof(t_list));
	if (!p)
		return (0);
	p->inx = inx++;
	p->content = content;
	p->next = 0;
	return (p);
}
