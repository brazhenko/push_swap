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
	while (i < stack_a()->size)
	{
		if (stack_a()->stack[i] < stack_a()->stack[minid])
			minid = (i);
		i++;
	}
	return (minid);
}

void	sort3(void)
{
	if (check_a())
	 	return ;
	else if (stack_a()->stack[2] > stack_a()->stack[1] &&
			stack_a()->stack[1] < stack_a()->stack[0] &&
			stack_a()->stack[0] > stack_a()->stack[2])
		sa_();
	else if (stack_a()->stack[2] > stack_a()->stack[1] &&
			stack_a()->stack[1] > stack_a()->stack[0])
	{
		sa_();
		rra_();
	}
	else if (stack_a()->stack[2] > stack_a()->stack[1] &&
			stack_a()->stack[1] < stack_a()->stack[0] &&
			stack_a()->stack[0] < stack_a()->stack[2])
		ra_();
	else if (stack_a()->stack[2] < stack_a()->stack[1] &&
			stack_a()->stack[1] > stack_a()->stack[0] &&
			stack_a()->stack[0] > stack_a()->stack[2])
	{
		sa_();
		ra_();
	}
	else if (stack_a()->stack[2] < stack_a()->stack[1] &&
			stack_a()->stack[1] > stack_a()->stack[0] &&
			stack_a()->stack[0] < stack_a()->stack[2])
		rra_();
}

void	push_all_except_3_in_b(void)
{
	while (stack_a()->size != 3)
	{
		pb_();
	}
}

void	pop_up_from_a(size_t num)
{
	PSTACK_TYPE		el;

	el = stack_a()->stack[num];
	if (num < stack_a()->size / 2)
	{
		while (stack_a()->stack[stack_a()->size - 1] != el)
		{
			rra_();
		}
	}
	else
	{
		while (stack_a()->stack[stack_a()->size - 1] != el)
			ra_();
	}
}

void	pop_up_from_b(size_t num)
{
	PSTACK_TYPE		el;

	el = stack_b()->stack[num];
	if (num < stack_b()->size / 2)
	{
		while (stack_b()->stack[stack_b()->size - 1] != el)
		{
			rrb_();
		}

	}
	else
	{
		while (stack_b()->stack[stack_b()->size - 1] != el)
		{
			rb_();
		}
	}
}

size_t		find_the_ok_place_in_a(PSTACK_TYPE val)
{
	size_t		i;
	size_t		minid;

	i = 1;
	while (i < stack_a()->size)
	{
		if (stack_a()->stack[i - 1] > val && val > stack_a()->stack[i])
		{
			return (i - 1);
		}
		i++;
	}
	if (stack_a()->stack[stack_a()->size - 1] > val && val > stack_a()->stack[0])
		return (stack_a()->size - 1);
	return (find_min_in_a());
}

size_t		calc_min_steps_for_ok_place(PSTACK_TYPE val)
{
	size_t		num;

	num = find_the_ok_place_in_a(val);
	if (num < stack_a()->size / 2)
		return (num + 1);
	else
		return (stack_a()->size - num - 1);

}

void	fill_one(void)
{
	size_t		min_steps_count;
	size_t		min_steps_count_tmp;
	size_t		min_steps_count_num;
	size_t		i;

	min_steps_count_num = 0;
	min_steps_count = 1 +  1 + calc_min_steps_for_ok_place(
			stack_b()->stack[min_steps_count_num]);
	i = 1;
	while (i < stack_b()->size)
	{
		min_steps_count_tmp = (i > (stack_b()->size / 2) ?(stack_b()->size - i - 1)
		: (i + 1)) + (1) + calc_min_steps_for_ok_place(stack_b()->stack[i]);
		if (min_steps_count_tmp < min_steps_count)
			min_steps_count_num = i;
		i++;
	}
	// printf("steps: %zu, num: %d\n", min_steps_count, min_steps_count_num);
	// printf("OK PLACE %zu\n", find_the_ok_place_in_a(stack_b()->stack[stack_b()->size - 1]));
	pop_up_from_b(min_steps_count_num);
	pop_up_from_a(find_the_ok_place_in_a(stack_b()->stack[stack_b()->size - 1]));
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
	//выкинуть все кроме 3 в B
	push_all_except_3_in_b();
	//отсортировать A
	sort3();
	while (stack_b()->size != 0)
	{
		fill_one();
	}
	normalize();
	// show();
}

void 	sort(void)
{
	if (stack_a()->size == 1)
		return ;
	else if (stack_a()->size == 2)
		sort2();
	else if (stack_a()->size == 3)
		sort3();
	else
		sortelse();
}