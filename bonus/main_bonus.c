/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:00:22 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/27 18:25:08 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "unistd.h"
#include <stdlib.h>

char	**arg_join(char **argv)
{
	int		i;
	char	**listed_all;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (argv[++i])
		tmp = ft_strjoin(tmp, argv[i]);
	listed_all = ft_split(tmp, ' ');
	free(tmp);
	return (listed_all);
}

void	only_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-')
			return ;
	print_error_bonus(NULL, NULL);
}

void	int_check(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		ft_atoi(argv[i]);
		only_space(argv[i]);
	}
}

void	arg_check(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			print_error_bonus(NULL, NULL);
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != ' '
				&& argv[i][j] != '-' && argv[i][j] != '+')
				print_error_bonus(NULL, NULL);
			if (argv[i][j] == '-' || argv[i][j] == '+')
				if ((argv[i][j + 1] < '0' || argv[i][j + 1] > '9') || (argv[i][j
						- 1] >= '0' && argv[i][j - 1]))
					print_error_bonus(NULL, NULL);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
	char	**listed_all;

	if (argc < 2)
		return (0);
	int_check(argv);
	arg_check(argv, argc);
	a = malloc(sizeof(t_list *));
	b = malloc(sizeof(t_list *));
	listed_all = arg_join(argv);
	ft_control_bonus(listed_all, a);
	dispose_split_list(listed_all);
	ft_handler(a, b);
	if (issort_bonus(a, b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear(a, b);
	free(a);
	free(b);
}
