#include "stdlib.h"
#include "push_swap.h"

void ft_init(char **argv, t_list **a)
{
	ft_argv_control(argv);
	ft_add_stack(argv, a);
	ft_isunique(*a);
	if (ft_issort(*a))
		exit(0); //exit fonksiyonu yazılacak freelemesi lazım
}

int	main(int argc, char **argv)
{
	if (argc <= 2)
		return (0);
	t_list	*a;
	t_list	*b;
	ft_init(argv, &a);
	if (ft_lstsize(a) > 1 && ft_lstsize(a) <= 5)
		ft_sort(&a, &b, ft_lstsize(a));
	else if(ft_lstsize(a) > 5)
		bubble_sort(&a, &b);
}