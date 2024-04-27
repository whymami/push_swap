/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:01:47 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/27 16:00:34 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/getnextline/get_next_line.h"
# include "../lib/libft/libft.h"

void	ft_handler(t_list **a, t_list **b);
void	ft_control_bonus(char **listed_all, t_list **a);
void	print_error_bonus(t_list **a, t_list **b);
int		issort_bonus(t_list **stack);

void	ft_pushs(t_list **a, t_list **b, char id);
void	ft_rotates(t_list **a, t_list **b, char id);
void	ft_rrotates(t_list **a, t_list **b, char id);
void	ft_swaps(t_list **a, t_list **b, char id);
void	dispose_split_list(char **split);
#endif