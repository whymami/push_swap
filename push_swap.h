/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:00:26 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/16 11:27:49 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"


void ft_swap_a(t_list **a);
void ft_swap_b(t_list **b);
void ft_run_ss(t_list **a, t_list **b);
void ft_push_a(t_list **a, t_list **b);
void ft_push_b(t_list **a, t_list **b);
void ft_rotate_a(t_list **a);
void ft_rotate_b(t_list **b);
void ft_run_rr(t_list **a, t_list **b);
void ft_reverse_rotate_a(t_list **a);
void ft_reverse_rotate_b(t_list **b);
void ft_run_rrr(t_list **a, t_list **b);

#endif