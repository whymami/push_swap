#include "stdlib.h"
#include "push_swap.h"

int	ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}
int ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void ft_argv_control(char **argv)
{	
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		if (ft_strlen(argv[i]) == 0 && ft_printf("Error\n"))
			exit(1);
		while (argv[i][++j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') && ft_isdigit(argv[i][j + 1]))
				j++;
			if((!ft_isdigit(argv[i][j])) && ft_printf("Error\n"))
				exit(1);
		}
	}
}
int ft_isint(long n)
{
	if ((n > 2147483647 || n < -2147483648) && ft_printf("Error\n"))
		exit(1);
	return (1);
}

void ft_add_stack(char **argv, t_list **a)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_isint(ft_atoi(argv[i])))
			ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2 && ft_printf("Error\n"))
		return (0);
	ft_argv_control(argv);
	t_list *a;

	ft_add_stack(argv, &a);
	ft_printf("a: %d\n", a->content);

	ft_printf("OK\n");
}