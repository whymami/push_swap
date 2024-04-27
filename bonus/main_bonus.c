
#include "push_swap_bonus.h"
#include <stdlib.h>
#include "unistd.h"

void	print_error(t_list **a, t_list **b)
{
	if (a != NULL && b != NULL)
		ft_lstclear(a, b);
	ft_printf("Error\n");
	exit(1);
}

void sa(t_list **a)
{
    t_list  *tmp;
    int     temp;

    if (!*a || !(*a)->next)
        return ;
    tmp = *a;
    temp = tmp->content;
    tmp->content = tmp->next->content;
    tmp->next->content = temp;
}

void sb(t_list **b)
{
    t_list  *tmp;
    int     temp;

    if (!*b || !(*b)->next)
        return ;
    tmp = *b;
    temp = tmp->content;
    tmp->content = tmp->next->content;
    tmp->next->content = temp;
}

void   ft_swaps(t_list **a, t_list **b, char id)
{
    if (id == 'a')
        sa(a);
    else if (id == 'b')
        sb(b);
    else
    {
        sa(a);
        sb(b);
    }
}

void pa(t_list **a, t_list **b)
{
    t_list  *tmp;

    if (!*b)
        return ;
    tmp = *b;
    *b = (*b)->next;
    tmp->next = *a;
    *a = tmp;
}

void pb(t_list **a, t_list **b)
{
    t_list  *tmp;

    if (!*a)
        return ;
    tmp = *a;
    *a = (*a)->next;
    tmp->next = *b;
    *b = tmp;
}

void ft_pushs(t_list **a , t_list **b, char id)
{
    if (id == 'a' )
        pa(a, b);
    else if (id == 'b')
        pb(a, b);
}

void ra(t_list **a)
{
    t_list  *tmp;
    t_list  *tmp2;

    if (!*a || !(*a)->next)
        return ;
    tmp = *a;
    tmp2 = *a;
    *a = (*a)->next;
    while (tmp2->next)
        tmp2 = tmp2->next;
    tmp2->next = tmp;
    tmp->next = NULL;
}

void rb(t_list **b)
{
    t_list  *tmp;
    t_list  *tmp2;

    if (!*b || !(*b)->next)
        return ;
    tmp = *b;
    tmp2 = *b;
    *b = (*b)->next;
    while (tmp2->next)
        tmp2 = tmp2->next;
    tmp2->next = tmp;
    tmp->next = NULL;
}

void ft_rotates(t_list **a, t_list **b, char id)
{
    if (id == 'a')
        ra(a);
    else if (id == 'b')
        rb(b);
    else
    {
        ra(a);
        rb(b);
        ft_printf("rr\n");
    }
}

void rra(t_list **a)
{
    t_list  *tmp;
    t_list  *tmp2;

    if (!*a || !(*a)->next)
        return ;
    tmp = *a;
    while (tmp->next->next)
        tmp = tmp->next;
    tmp2 = tmp->next;
    tmp->next = NULL;
    tmp2->next = *a;
    *a = tmp2;
}

void rrb(t_list **b)
{
    t_list  *tmp;
    t_list  *tmp2;

    if (!*b || !(*b)->next)
        return ;
    tmp = *b;
    while (tmp->next->next)
        tmp = tmp->next;
    tmp2 = tmp->next;
    tmp->next = NULL;
    tmp2->next = *b;
    *b = tmp2;
}

void ft_rrotates(t_list **a, t_list **b, char id)
{
    if (id == 'a')
        rra(a);
    else if (id == 'b')
        rrb(b);
    else
    {
        rra(a);
        rrb(b);
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

void	ft_add_stack(char **argv, t_list **a)
{
	int	i;

	i = -1;
	while (argv[++i])
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
}

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

static void	ft_isunique(t_list *a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->content == tmp2->content)
				print_error(&a, NULL);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

static int	issort(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	print_error(stack, NULL);
    return (0);
}

void	ft_control(t_list **a)
{
	ft_isunique(*a);
	issort(a);
}

int	ft_strncmp(const char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (dest[i] && src[i] && dest[i] == src[i] && i < n - 1)
		i++;
	return ((unsigned char)dest[i] - (unsigned char)src[i]);
}

void use_action(char *action, t_list **a, t_list **b)
{
    if (ft_strncmp(action, "sa\n", 3) == 0)
        ft_swaps(a, b, 'a');
    else if (ft_strncmp(action, "sb\n", 3) == 0)
        ft_swaps(a, b, 'b');
    else if (ft_strncmp(action, "ss\n", 3) == 0)
        ft_swaps(a, b, 's');
    else if (ft_strncmp(action, "pa\n", 3) == 0)
        ft_pushs(a, b, 'a');
    else if (ft_strncmp(action, "pb\n", 3) == 0)
        ft_pushs(a, b, 'b');
    else if (ft_strncmp(action, "ra\n", 3) == 0)
        ft_rotates(a, b, 'a');
    else if (ft_strncmp(action, "rb\n", 3) == 0)
        ft_rotates(a, b, 'b');
    else if (ft_strncmp(action, "rr\n", 3) == 0)
        ft_rotates(a, b, 'r');
    else if (ft_strncmp(action, "rra\n", 4) == 0)
        ft_rrotates(a, b, 'a');
    else if (ft_strncmp(action, "rrb\n", 4) == 0)
        ft_rrotates(a, b, 'b');
    else if (ft_strncmp(action, "rrr\n", 4) == 0)
        ft_rrotates(a, b, 'r');
    else
        print_error(a, b);
}

void   ft_handler(t_list **a, t_list **b)
{
    char *action;

    action = get_next_line(0);
    if (!action)
        return ;
    while (action)
    {
        use_action(action, a, b);
        free(action);
        action = get_next_line(0);
    }
}

int finish(t_list **a)
{
    t_list  *tmp;

    tmp = *a;
    while (tmp->next)
    {
        if (tmp->content > tmp->next->content)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int    main(int argc, char **argv)
{
    t_list	**a;
    t_list	**b;
    char    **listed_all;

    if (argc < 2)
        return (0);

    int_check(argv);
	arg_check(argv, argc);
    a = malloc(sizeof(t_list *));
    b = malloc(sizeof(t_list *));
    listed_all = arg_join(argv);
    ft_add_stack(listed_all, a);
    //dispose_split gelecek;
    ft_control(a);
    ft_handler(a, b);
    if (finish(a))
        ft_printf("OK\n");
    else
        ft_printf("KO\n");

    
}