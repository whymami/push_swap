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

int	main(int argc, char **argv)
{
	if (argc <= 2 && ft_printf("Error\n"))
		return (0);
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	int i;
	i = 0;
	int j;
	while (argv[++i])
	{
		j = -1;
		if (ft_strlen(argv[i]) == 0 && ft_printf("Error\n"))
			return (0);
		while (argv[i][++j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') && ft_isdigit(argv[i][j + 1]))
				j++;
			if((!ft_isdigit(argv[i][j])) && ft_printf("Error\n"))
				return (0);
		}
	}
	ft_printf("OK\n");
}