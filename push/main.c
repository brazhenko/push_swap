#include "../push_swap_lib/pstack.h"
#include "sorter.h"

int 	main(int ac, char **av)
{
	if (ac > 1)
	{
		parse_argv(ac, av);
 		sort();
		kill();
	}
}