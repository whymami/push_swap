/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:02:28 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/25 13:25:48 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_argv_control(char **argv)
{	
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		if (ft_strlen(argv[i]) == 0 && ft_printf("null geldi\n"))
			exit(1);
		while (argv[i][++j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+' || argv[i][j] == ' ') && ft_isdigit(argv[i][j + 1]))
				j++;
			if((!ft_isdigit(argv[i][j])) && ft_printf("rakam değil\n"))
				exit(1);
		}
	}
}

void ft_add_stack(char **argv, t_list **a)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (ft_isint(ft_atoi(argv[i])))
			ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
	}
}

void ft_isunique(t_list *a)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->content == tmp2->content && ft_printf("sıralı\n"))
				exit(1); //exit fonksiyonu yazılacak freelemesi lazım
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

int ft_issort(t_list *a)
{
	t_list *tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

