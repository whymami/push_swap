/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:00:26 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/19 14:22:38 by muguveli         ###   ########.fr       */
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

int find_min_nbr(t_list *a);
void ft_sort(t_list **a, t_list **b, int size);
int ft_isint(long n);
void ft_add_stack(char **argv, t_list **a);
void ft_argv_control(char **argv);
void ft_add_stack(char **argv, t_list **a);
void ft_isunique(t_list *a);
int ft_issort(t_list *a);

void bubble_sort(t_list **a, t_list **b);

#endif