/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:01:55 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/27 18:24:07 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdlib.h"

static void	only_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-')
			return ;
	print_error(NULL, NULL);
}

static void	int_check(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		ft_atoi(argv[i]);
		only_space(argv[i]);
	}
}

static void	arg_check(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			print_error(NULL, NULL);
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != ' '
				&& argv[i][j] != '-' && argv[i][j] != '+')
				print_error(NULL, NULL);
			if (argv[i][j] == '-' || argv[i][j] == '+')
				if ((argv[i][j + 1] < '0' || argv[i][j + 1] > '9') || (argv[i][j
						- 1] >= '0' && argv[i][j - 1]))
					print_error(NULL, NULL);
			j++;
		}
		i++;
	}
}

static char	**arg_join(char **argv)
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

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
	char	**arg_list;

	if (argc < 2)
		return (0);
	int_check(argv);
	arg_check(argv, argc);
	a = malloc(sizeof(t_list *));
	b = malloc(sizeof(t_list *));
	arg_list = arg_join(argv);
	ft_add_stack(arg_list, a);
	dispose_split_list(arg_list);
	ft_control(a);
	ft_sort(a, b, ft_lstsize(*a));
	ft_lstclear(a, b);
	free(a);
	free(b);
}
