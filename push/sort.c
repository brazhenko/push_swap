#include <stdio.h>
#include "../push_swap_lib/pstack.h"
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

void		push_all_except_3_in_b(void)
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
	if (a__()->size == 1 || check())
		return ;
	else if (a__()->size == 2)
		sort2();
	else if (a__()->size == 3)
		sort3();
	else
		sortelse();
}