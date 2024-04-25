#include "stdlib.h"
#include "push_swap.h"

void only_space(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-')
			return ;
	exit(1);
	return ;
}

void int_check(char **argv, int argc)
{
	int i;
	if (argc < 2)
		return ;
	i = 0;
	while (argv[++i])
	{
		ft_atoi(argv[i]);
		only_space(argv[i]);
	}
}
void arg_check(char **argv, int argc)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if(argv[i][j] == '\0')
			exit(1);
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != ' '
				&& argv[i][j] != '-' && argv[i][j] != '+')
				exit(1);
			if (argv[i][j] == '-' || argv[i][j] == '+')
				if ((argv[i][j + 1] < '0' || argv[i][j + 1] > '9') ||
					(argv[i][j - 1] >= '0' && argv[i][j - 1]))
					exit(1);
			j++;
		}
		i++;
	}
}

char	**arg_join(char **argv)
{
	int		i;
	char	**listed_all;
	char	*tmp;

	i = 1;
	tmp = NULL;
	while (argv[i])
	{
		tmp = ft_strjoin(tmp, argv[i]);
		i++;
	}
	listed_all = ft_split(tmp, ' ');
	free(tmp);
	return (listed_all);
}

void print_list(t_list *a)
{
	t_list *tmp;

	tmp = a;
	while (tmp)
	{
		ft_printf("content: %d\t index: %d\t target->index: %d\t target->content: %d\n", tmp->content, tmp->inx, tmp->target->inx, tmp->target->content);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	t_list	**a;
	t_list	**b;
	char	**arg_list;

	int_check(argv, argc);
	arg_check(argv, argc);
	a = malloc(sizeof(t_list *));
	b = malloc(sizeof(t_list *));
	arg_list = arg_join(argv);
	ft_add_stack(arg_list, a);
	ft_sort(a, b, ft_lstsize(*a));
	free(*a);
	free(*b);
}