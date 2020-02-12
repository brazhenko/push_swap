#include <stdio.h>
#include "push_swap_lib/pushswap.h"
#include <string.h>
#include <stdlib.h>
#include <limits.h>

void		sort2(void)
{
	if (check())
	{
		return ;
	}
	sa_();
}

size_t		find_min_id_in_a()
{
	size_t		i;
	size_t		min_id;

	min_id = 0;
	i = 0;
	while (i < a__()->size)
	{
		if (a__()->stack[i] < a__()->stack[min_id])
			min_id = i;
		i++;
	}
	return (min_id);
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
	return (find_min_id_in_a());
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
		{
			ra_();
		}
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

void	pop_from_a_and_b(size_t a_id, size_t b_id)
{
	if ((a_id < a__()->size / 2) && (b_id < b__()->size / 2))
	{
		while (a_id != a__()->size - 1 && b_id != b__()->size - 1)
		{
			a_id = (a_id == 0 ? a__()->size - 1 : a_id - 1);
			b_id = (b_id == 0 ? a__()->size - 1 : b_id - 1);
			rrr_();
		}
	}
	else if ((a_id >= a__()->size / 2) && (b_id >= b__()->size / 2))
	{
		while (a_id != a__()->size - 1 && b_id != b__()->size - 1)
		{
			a_id++;
			b_id++;
			printf("%zu -- %zu\n", a_id, b_id);
			fflush(stdout);
			rr_();
		}
	}
	pop_up_from_a(a_id);
	pop_up_from_b(b_id);
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
		min_steps_count_tmp = (i > (b__()->size / 2) ? (b__()->size - i - 1) : (i + 1)) + (1) + calc_min_steps_for_ok_place(b__()->stack[i]);
		if (min_steps_count_tmp < min_steps_count)
			min_steps_count_num = i;
		i++;
	}
	pop_up_from_b(min_steps_count_num);
	pop_up_from_a(find_the_ok_place_in_a(b__()->stack[b__()->size - 1]));
	// pop_from_a_and_b(min_steps_count_num, find_the_ok_place_in_a(b__()->stack[b__()->size - 1]));
	pa_();
}



//---------------------------fill_one2------------------------------------------

#define A_UP_B_UP		0
#define A_DOWN_B_DOWN	1
#define A_UP_B_DOWN		2
#define A_DOWN_B_UP		3


static size_t	max(size_t x, size_t y)
{
	return (x > y ? x : y);
}

static void		process_put(size_t *arr)
{
	if (arr[5] == A_UP_B_UP)
	{
		while (arr[6] && arr[7])
		{
			rr_();
			arr[6]--;
			arr[7]--;
		}
		while (arr[6])
		{
			ra_();
			arr[6]--;
		}
		while (arr[7])
		{
			rb_();
			arr[7]--;
		}
	}
	else if (arr[5] == A_DOWN_B_DOWN)
	{
		while (arr[6] && arr[7])
		{
			rrr_();
			arr[6]--;
			arr[7]--;
		}
		while (arr[6])
		{
			rra_();
			arr[6]--;
		}
		while (arr[7])
		{
			rrb_();
			arr[7]--;
		}
	}
	else if (arr[5] == A_DOWN_B_UP)
	{
		while (arr[6])
		{
			rra_();
			arr[6]--;
		}
		while (arr[7])
		{
			rb_();
			arr[7]--;
		}
	}
	else if (arr[5] == A_UP_B_DOWN)
	{
		while (arr[6])
		{
			ra_();
			arr[6]--;
		}
		while (arr[7])
		{
			rrb_();
			arr[7]--;
		}
	}
	pa_();
}

/*
 * arr[0] - steps to shift A elem up
 * arr[1] - steps to shift A elem down
 * arr[2] - steps to shift B elem up
 * arr[3] - steps to shift B elem down
 * arr[4] - current minimum steps
 * arr[5] - current algorithm type
 * arr[6] - position in A to put on
 * arr[7] - position in B to take
 */

void		calc_shortest_way_len(size_t a, size_t b, size_t *arr)
{
	arr[0] = a__()->size - a - 1;
	arr[1] = a + 1;
	arr[2] = b__()->size - b - 1;
	arr[3] = b + 1;
	// a вверх, b вниз
	if (arr[0] + arr[3] < arr[4])
	{
		arr[4] = arr[0] + arr[3];
		arr[5] = A_UP_B_DOWN;
		arr[6] = arr[0];
		arr[7] = arr[3];
	}
	// b вверх, a вниз
	else if (arr[2] + arr[1] < arr[4])
	{
		arr[4] = arr[2] + arr[1];
		arr[5] = A_DOWN_B_UP;
		arr[6] = arr[1];
		arr[7] = arr[2];
	}
	// обе вверх
	else if (max(arr[0], arr[2]) < arr[4])
	{
		arr[4] = max(arr[0], arr[2]);
		arr[5] = A_UP_B_UP;
		arr[6] = arr[0];
		arr[7] = arr[2];
	}
	//обе вниз
	else if (max(arr[1], arr[3]) < arr[4])
	{
		arr[4] = max(arr[1], arr[3]);
		arr[5] = A_DOWN_B_DOWN;
		arr[6] = arr[1];
		arr[7] = arr[3];
	}

}


void		fill_one2(void)
{
	size_t		i;
	size_t		arr[10];

	arr[4] = 0 - 1;
	calc_shortest_way_len(find_the_ok_place_in_a(b__()->stack[0]), 0, arr);
	i = 1;
	while (i < b__()->size)
	{
		calc_shortest_way_len(find_the_ok_place_in_a(b__()->stack[i]), i, arr);
		i++;
	}
	// printf("shortest way: %zu, %zu, vals:%d, %d, count %zu\n", arr[6], arr[7], a__()->stack[arr[6]], b__()->stack[arr[7]], arr[4]);
	process_put(arr);
}

void		normalize()
{
	size_t		i;

	i = find_min_id_in_a();
	pop_up_from_a(i);
}

void		sortelse(void)
{
	push_all_except_3_in_b();
	sort3();
	while (b__()->size != 0)
	{
		fill_one2();
	}
	normalize();
}

void 	sort(void)
{
	//show();
	if (a__()->size == 1 || check())
		return ;
	else if (a__()->size == 2)
		sort2();
	else if (a__()->size == 3)
		sort3();
	else
		sortelse();
	// show();
}