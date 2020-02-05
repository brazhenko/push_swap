#include <stdio.h>
#include "push_swap_lib/pushswap.h"
#include "utilities.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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