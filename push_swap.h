/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:00:26 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/25 20:22:21 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/ft_printf/ft_printf.h"
# include "lib/libft/libft.h"

void	ft_pushs(t_list **a, t_list **b, char id);
void	ft_rotates(t_list **a, t_list **b, char id);
void	ft_rrotates(t_list **a, t_list **b, char id);
void	ft_swaps(t_list **a, t_list **b, char id);
int		find_min_nbr(t_list *a);
void	ft_sort(t_list **a, t_list **b, int size);
void	big_sort(t_list **a, t_list **b);
void	rotate3(t_list **a, t_list **b, t_list *tmp);
void	rotate2(t_list **a, t_list **b, t_list *tmp);
void	setrr(t_list **stack);
void	setmoves(t_list **a, t_list **b);
int		get_smallest(t_list **b);
int		get_large(t_list **b);
t_list	*listindex(int index, t_list **stack);
void	rotate1(t_list **a, t_list **b, t_list *tmp);
void	reindex(t_list *stack);
void	print_error(t_list **a, t_list **b);
void	dispose_split_list(char **split);
void	ft_control(t_list **a);
void	ft_add_stack(char **argv, t_list **a);
#endif