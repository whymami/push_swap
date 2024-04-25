/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:54:40 by muguveli          #+#    #+#             */
/*   Updated: 2024/04/25 16:53:47 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_list **a)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = (*a)->content;
	a2 = (*a)->next->content;
	a3 = (*a)->next->next->content;
	if (a1 > a2 && a1 < a3)
		ft_swaps(a, NULL, 'a');
	else if (a1 < a2 && a1 > a3)
		ft_rrotates(a, NULL, 'a');
	else if (a1 > a2 && a1 > a3 && a2 < a3)
		ft_rotates(a, NULL, 'a');
	else if (a1 > a2 && a1 > a3 && a2 > a3)
	{
		ft_swaps(a, NULL, 'a');
		ft_rrotates(a, NULL, 'a');
	}
	else if (a1 < a2 && a1 < a3 && a2 > a3)
	{
		ft_swaps(a, NULL, 'a');
		ft_rotates(a, NULL, 'a');
	}
}

static void	ft_sort_four(t_list **a, t_list **b)
{
	int	min;
	int	i;

	i = 0;
	min = find_min_nbr(*a);
	while (i < 1)
	{
		if ((*a)->content == min)
		{
			ft_pushs(a, b, 'b');
			i++;
		}
		else
			ft_rotates(a, b, 'a');
	}
	ft_sort_three(a);
	ft_pushs(a, b, 'a');
}

static void	ft_sort_five(t_list **a, t_list **b)
{
	int	min;
	int	i;

	min = find_min_nbr(*a);
	i = 0;
	while (i < 2)
	{
		if ((*a)->content == min)
		{
			ft_pushs(a, b, 'b');
			i++;
			min = find_min_nbr(*a);
		}
		else
			ft_rotates(a, b, 'a');
	}
	ft_sort_three(a);
	while (*b)
		ft_pushs(a, b, 'a');
}

void setrr(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->inx <= ft_lstlast(*stack)->inx / 2)
			tmp->isrr = 0;
		else
			tmp->isrr = 1;
		tmp = tmp->next;
	}		
}

void setmoves(t_list **a, t_list **b)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *a;
	tmp2 = *b;
	while (tmp1)
	{
		if (tmp1->isrr == 0)
			tmp1->moves = tmp1->inx; // saat yönde dönüyorsa index sayıyı adım sayıyı olur
		else
			tmp1->moves = ft_lstlast(*a)->inx - tmp1->inx + 1; // ters yönünde dönüyorsa indexi son elemana getir ve en başa çıkarmak için 1 adım daha ekle
		tmp1 = tmp1->next; //listeyi iletlet
	}
	if (tmp2) // eğer b listesi boş değilse
	{
		while (tmp2)
		{
			if (tmp2->isrr == 0) // saat yönünde dönüyorsa
				tmp2->moves = tmp2->inx; // index sayıyı adım sayıyı olur
			else
				tmp2->moves = ft_lstlast(*b)->inx - tmp2->inx + 1; // ters yönünde dönüyorsa indexi son elemana getir ve en başa çıkarmak için 1 adım daha ekle
			tmp2 = tmp2->next; // listeyi ilerlet
		}
	}

}

// listeyi baştan sonra tarar ve en küçük elemanın indexini döner
int	get_smallest(t_list **b)
{
	t_list	*tmp;
	int		smallest;
	int		index;

	tmp = *b;
	smallest = tmp->content;
	index = tmp->inx;
	while (tmp)
	{
		if (tmp->content < smallest)
		{
			smallest = tmp->content;
			index = tmp->inx;
		}
		tmp = tmp->next;
	}
	return (index);
}
// listeyi baştan sonra tarar ve en büyük elemanın indexini döner
int	get_large(t_list **b)
{
	t_list	*tmp;
	int		large;
	int		index;

	tmp = *b;
	large = tmp->content;
	index = tmp->inx;
	while (tmp)
	{
		if (tmp->content > large)
		{
			large = tmp->content;
			index = tmp->inx;
		}
		tmp = tmp->next;
	}
	return (index);
}

// paramtere olarak verilen indexe sahip elemanı döner
t_list *listindex(int index, t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->inx == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

// her elemanın hedefini belirler
void gettarget(t_list **a, t_list **b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	while (tmp_a)
	{
		tmp_a->target = listindex(get_smallest(b), b);
		while (tmp_b)
		{
			if (tmp_a->content > tmp_b->content && tmp_a->target->content < tmp_b->content)
				tmp_a->target = tmp_b;
			tmp_b = tmp_b->next;
		}
		if (tmp_a->target->content > tmp_a->content)
			tmp_a->target = listindex(get_large(b), b);
		tmp_b = *b;
		tmp_a = tmp_a->next;
	}
}

// en az adımda en başa getirecek elemanı döner
// bunu nasıl yapıyor?
// listemin ilk elemannın hedef elemanının adım sayısını ve kendisinin adım sayısını toplar
// ve pointerın gösterdiği elemanın hedef elemanının adım sayısını ve kendisinin adım sayısını toplar
// bu iki toplamı karşılaştırır eğer birinci toplam daha küçükse pointerı birinci eleman yapar
// eğer iki toplam eşitse
// eğer pointerın hedef elemanı isrr değeri ve ilk elemanın hedef elemanı isrr değeri aynıysa
// ve ilk elemanın isrr değeri ve ilk elemannın hedef elemanı isrr değeri farklıysa ilk elemanı pointer yapar
// eğer hiç bir koşula uymazsa pointerı bir sonraki eleman yapar
// bu şekilde minimum adımda en başa getirecek elemanı bulmuş oluruz
t_list *get_min_moves(t_list **a)
{
	t_list	*tmp;
	t_list	*ret;

	tmp = *a;
	ret = tmp;
	while (tmp)
	{
		if (tmp->target->moves + tmp->moves
			< ret->target->moves + ret->moves)
			ret = tmp;
		else if (tmp->target->moves + tmp->moves == ret->target->moves + ret->moves)
		{
			if (tmp->target->isrr == ret->target->isrr
				&& ret->isrr != ret->target->isrr)
				ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

void rotate1(t_list **a, t_list **b, t_list *tmp)
{
	while (tmp->isrr == 1 && tmp->moves)
	{
		ft_rrotates(a, b, 'a');
		tmp->moves--;
	}
	while (tmp->target->isrr == 1 && tmp->target->moves)
	{
		ft_rrotates(a, b, 'b');
		tmp->target->moves--;
	}
	while (tmp->isrr == 0 && tmp->moves)
	{
		ft_rotates(a, b, 'a');
		tmp->moves--;
	}
	while (tmp->target->isrr == 0 && tmp->target->moves)
	{
		ft_rotates(a, b, 'b');
		tmp->target->moves--;
	}
}

void rotate2(t_list **a, t_list **b, t_list *tmp)
{
	while (tmp->moves && tmp->target->moves)
	{
		ft_rotates(a, b, 'r');
		tmp->moves--;
		tmp->target->moves--;
	}
	while (tmp->moves)
	{
		ft_rotates(a, b, 'a');
		tmp->moves--;
	}
	while (tmp->target->moves)
	{
		ft_rotates(a, b, 'b');
		tmp->target->moves--;
	}
}

void rotate3(t_list **a, t_list **b, t_list *tmp)
{
	while (tmp->moves && tmp->target->moves)
	{
		ft_rrotates(a, b, 'r');
		tmp->moves--;
		tmp->target->moves--;
	}
	while (tmp->moves)
	{
		ft_rrotates(a, b, 'a');
		tmp->moves--;
	}
	while (tmp->target->moves)
	{
		ft_rrotates(a, b, 'b');
		tmp->target->moves--;
	}
}

void laststep(t_list **a, t_list **b)
{
	while (listindex(get_large(b),b)->moves)
	{
		if (listindex(get_large(b),b)->isrr == 1)
			ft_rrotates(a, b, 'b');
		else
			ft_rotates(a, b, 'b');
		listindex(get_large(b),b)->moves--;
	}
	while (*b)
		ft_pushs(a, b, 'a');
}

void big_sort(t_list **a, t_list **b)
{
	t_list *tmp;

	ft_pushs(a, b, 'b'); // ilk elemanı b'ye atar
	ft_pushs(a, b, 'b'); // ikinci elemanı b'ye atar çünkü b içinde elimizde bir baş ve bir son olması gereklidir bunlara göre a deki ilk elemanın nereye geleceğini hesaplıyoruz
	while(*a)
	{
		gettarget(a, b); 
		tmp = get_min_moves(a);
		if (tmp->isrr != tmp->target->isrr)
			rotate1(a, b, tmp); // single rotate
		else if (tmp->isrr == tmp->target->isrr)
		{
			if (tmp->isrr == 0)
				rotate2(a, b, tmp); //rotate
			else
				rotate3(a, b, tmp); //rev rotate
		}
		ft_pushs(a, b, 'b');
	}
	laststep(a, b);
}

void	ft_sort(t_list **a, t_list **b, int size)
{
	if (size == 2)
		ft_swaps(a, b, 'a');
	else if (size == 3)
		ft_sort_three(a);
	else if (size == 4)
		ft_sort_four(a, b);
	else if (size == 5)
		ft_sort_five(a, b);
	else
	{
		setrr(a); // elementlerin hangi yarıda olduğunu belirler indexleri yarıda küçükse saat yönünde değilse tersi olarak işaretler
		setmoves(a,b); // elemanların ilk indexe kaç adımda ulaşacaklarını hesaplar ve keyderer
		big_sort(a, b); // sıralama işlemini başlatır
	}
	// print_list(*a);
}
