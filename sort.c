#include <stdio.h>
#include "push_swap_lib/pushswap.h"
#include <string.h>
#include <stdlib.h>

void	sort2(void)
{
	if (check())
	{
		return ;
	}
	sa_();
}

size_t		find_min_in_a()
{
	size_t		i;
	size_t		minid;

	minid = 0;
	i = 0;
	while (i < a__()->size)
	{
		if (a__()->stack[i] < a__()->stack[minid])
			minid = (i);
		i++;
	}
	return (minid);
}

void	sort3(void)
{
	if (check_a())
	 	return ;
	else if (a__()->stack[2] > a__()->stack[1] && a__()->stack[1] <
			a__()->stack[0] && a__()->stack[0] > a__()->stack[2])
		sa_();
	else if (a__()->stack[2] > a__()->stack[1] &&
			a__()->stack[1] > a__()->stack[0])
	{
		sa_();
		rra_();
	}
	else if (a__()->stack[2] > a__()->stack[1] && a__()->stack[1] <
			a__()->stack[0] && a__()->stack[0] < a__()->stack[2])
		ra_();
	else if (a__()->stack[2] < a__()->stack[1] && a__()->stack[1] >
			a__()->stack[0] && a__()->stack[0] > a__()->stack[2])
	{
		sa_();
		ra_();
	}
	else if (a__()->stack[2] < a__()->stack[1] && a__()->stack[1] >
			a__()->stack[0] && a__()->stack[0] < a__()->stack[2])
		rra_();
}

void	push_all_except_3_in_b(void)
{
	while (a__()->size != 3)
	{
		pb_();
	}
}

void	pop_up_from_a(size_t num)
{
	PSTACK_TYPE		el;

	el = a__()->stack[num];
	if (num < a__()->size / 2)
	{
		while (a__()->stack[a__()->size - 1] != el)
		{
			rra_();
		}
	}
	else
	{
		while (a__()->stack[a__()->size - 1] != el)
			ra_();
	}
}

void	pop_up_from_b(size_t num)
{
	PSTACK_TYPE		el;

	el = b__()->stack[num];
	if (num < b__()->size / 2)
	{
		while (b__()->stack[b__()->size - 1] != el)
		{
			rrb_();
		}

	}
	else
	{
		while (b__()->stack[b__()->size - 1] != el)
		{
			rb_();
		}
	}
}

size_t		find_the_ok_place_in_a(PSTACK_TYPE val)
{
	size_t		i;

	i = 1;
	while (i < a__()->size)
	{
		if (a__()->stack[i - 1] > val && val > a__()->stack[i])
		{
			return (i - 1);
		}
		i++;
	}
	if (a__()->stack[a__()->size - 1] > val && val > a__()->stack[0])
		return (a__()->size - 1);
	return (find_min_in_a());
}

size_t		calc_min_steps_for_ok_place(PSTACK_TYPE val)
{
	size_t		num;

	num = find_the_ok_place_in_a(val);
	if (num < a__()->size / 2)
		return (num + 1);
	else
		return (a__()->size - num - 1);

}

void	fill_one(void)
{
	size_t		min_steps_count;
	size_t		min_steps_count_tmp;
	size_t		min_steps_count_num;
	size_t		i;

	min_steps_count_num = 0;
	min_steps_count = 1 +  1 + calc_min_steps_for_ok_place(
			b__()->stack[min_steps_count_num]);
	i = 1;
	while (i < b__()->size)
	{
		min_steps_count_tmp = (i > (b__()->size / 2) ?(b__()->size - i - 1)
		: (i + 1)) + (1) + calc_min_steps_for_ok_place(b__()->stack[i]);
		if (min_steps_count_tmp < min_steps_count)
			min_steps_count_num = i;
		i++;
	}
	// printf("steps: %zu, num: %d\n", min_steps_count, min_steps_count_num);
	// printf("OK PLACE %zu\n", find_the_ok_place_in_a(stack_b()->stack[_b()->size - 1]));
	pop_up_from_b(min_steps_count_num);
	pop_up_from_a(find_the_ok_place_in_a(b__()->stack[b__()->size - 1]));
	pa_();
}

void		normalize()
{
	size_t		i;

	i = find_min_in_a();
	pop_up_from_a(i);
}

void	sortelse(void)
{
	push_all_except_3_in_b();
	sort3();
	while (b__()->size != 0)
	{
		fill_one();
	}
	normalize();
}

void 	sort(void)
{
	if (a__()->size == 1 || check())
		return ;
	else if (a__()->size == 2)
		sort2();
	else if (a__()->size == 3)
		sort3();
	else
		sortelse();
}