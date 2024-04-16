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
			if (tmp->content == tmp2->content && ft_printf("Error\n"))
				exit(1); //exit fonksiyonu yazılacak freelemesi lazım
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

int ft_issort(t_list *a)
{
	t_list *tmp;

	if (!a)
		return (1);
	tmp = a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void ft_init(char **argv, t_list **a)
{
	ft_argv_control(argv);
	ft_add_stack(argv, a);
	ft_isunique(*a);
	if (ft_issort(*a) && ft_printf("ERROR\n"))
		exit (1); //exit fonksiyonu yazılacak freelemesi lazım
}

void ft_sort_three(t_list **a)
{
	int a1;
	int a2;
	int a3;

	a1 = (*a)->content;
	a2 = (*a)->next->content;
	a3 = (*a)->next->next->content;
	if (a1 > a2 && a2 < a3 && a1 < a3) // eğer ilk eleman ortanca elemandan büyükse ve ortanca eleman sondan küçükse ve ilk eleman sondan küçükse
		ft_swap_a(a);
	else if (a1 > a2 && a2 > a3) // eğer ilk eleman ortanca elemandan büyükse ve ortanca eleman sondan büyükse
	{
		ft_swap_a(a);
		ft_reverse_rotate_a(a);
	}
	else if (a1 > a2 && a2 < a3 && a1 > a3) // eğer ilk eleman ortanca elemandan büyükse ve ortanca eleman sondan küçükse ve ilk eleman sondan büyükse
		ft_rotate_a(a);
	else if (a1 < a2 && a2 > a3 && a1 > a3)
	{
		ft_swap_a(a);
		ft_rotate_a(a);
	}
	else if (a1 < a2 && a2 > a3 && a1 < a3) // eğer ilk eleman ortanca elemandan küçükse ve ortanca eleman sondan büyükse ve ilk eleman sondan küçükse
		ft_reverse_rotate_a(a);
}

int find_min_nbr(t_list *a)
{
	int min;

	min = a->content;
	a = a->next;
	while (a)
	{
		if (min > a->content)
			min = a->content;
		a = a->next;
	}
	return (min);
}
void ft_sort_four(t_list **a, t_list **b)
{
	int	min;
	int	i;

	i = 0;
	min = find_min_nbr(*a);
	while (i < 1)
	{
		
		if ((*a)->content == min)
		{
			ft_push_b(a,b);
			i++;
		}
		else
			ft_rotate_a(a);
	}
	ft_sort_three(a);
	ft_push_a(a,b);
}
void ft_sort_five(t_list **a, t_list **b)
{
	int	min;
	int	i;

	min = find_min_nbr(*a);
	i = 0;
	while (i < 2)
	{
		if ((*a)->content == min)
		{
			ft_push_b(a,b);
			i++;
			min = find_min_nbr(*a);
		}
		else
			ft_rotate_a(a);
	}
	ft_sort_three(a);
	while(*b)
		ft_push_a(a,b);
}

void ft_sort(t_list **a, t_list **b, int size)
{
	if (size == 2)
		ft_swap_a(a);
	else if (size == 3)
		ft_sort_three(a);
	else if (size == 4)
		ft_sort_four(a,b);
	else if (size == 5)
		ft_sort_five(a, b);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	t_list	*a;
	t_list	*b;
	ft_init(argv, &a);
	if (ft_lstsize(a) > 1 && ft_lstsize(a) <= 5)
		ft_sort(&a, &b, ft_lstsize(a));
}