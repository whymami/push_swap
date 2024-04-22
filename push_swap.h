/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:00:26 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/22 15:14:25 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"

typedef struct sorted_array 
{
    t_list *sorted_list;
}   t_sorted_array;


void	ft_pushs(t_list **a, t_list **b, char id);
void	ft_rotates(t_list **a, t_list **b, char id);
void	ft_rrotates(t_list **a, t_list **b, char id);
void	ft_swaps(t_list **a, t_list **b, char id);

int find_min_nbr(t_list *a);
void ft_sort(t_list **a, t_list **b, int size);
int ft_isint(long n);
void ft_add_stack(char **argv, t_list **a);
void ft_argv_control(char **argv);
void ft_add_stack(char **argv, t_list **a);
void ft_isunique(t_list *a);
int ft_issort(t_list *a);
void	ft_sort_three(t_list **a);

void bubble_sort(t_list **a, t_list **b);

#endif