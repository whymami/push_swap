/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:46:02 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/27 16:00:01 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	use_action(char *action, t_list **a, t_list **b)
{
	if (ft_strncmp(action, "sa\n", 3) == 0)
		ft_swaps(a, b, 'a');
	else if (ft_strncmp(action, "sb\n", 3) == 0)
		ft_swaps(a, b, 'b');
	else if (ft_strncmp(action, "ss\n", 3) == 0)
		ft_swaps(a, b, 's');
	else if (ft_strncmp(action, "pa\n", 3) == 0)
		ft_pushs(a, b, 'a');
	else if (ft_strncmp(action, "pb\n", 3) == 0)
		ft_pushs(a, b, 'b');
	else if (ft_strncmp(action, "ra\n", 3) == 0)
		ft_rotates(a, b, 'a');
	else if (ft_strncmp(action, "rb\n", 3) == 0)
		ft_rotates(a, b, 'b');
	else if (ft_strncmp(action, "rr\n", 3) == 0)
		ft_rotates(a, b, 'r');
	else if (ft_strncmp(action, "rra\n", 4) == 0)
		ft_rrotates(a, b, 'a');
	else if (ft_strncmp(action, "rrb\n", 4) == 0)
		ft_rrotates(a, b, 'b');
	else if (ft_strncmp(action, "rrr\n", 4) == 0)
		ft_rrotates(a, b, 'r');
	else
		print_error_bonus(a, b);
}

void	ft_handler(t_list **a, t_list **b)
{
	char	*action;

	action = get_next_line(0);
	if (!action)
		return ;
	while (action)
	{
		use_action(action, a, b);
		free(action);
		action = get_next_line(0);
	}
}
