#include "../push_swap_lib/pstack.h"
#include "sorter.h"

/*
** arr[0] - steps to shift A elem up
** arr[1] - steps to shift A elem down
** arr[2] - steps to shift B elem up
** arr[3] - steps to shift B elem down
** arr[4] - current minimum steps
** arr[5] - current algorithm type
** arr[6] - position in A to put on
** arr[7] - position in B to take
*/

void		fill_one(void)
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
