#include "../push_swap_lib/pushswap.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 	valid(char *arg, int *num)
{
	int 	tmp;
	char	*tmp_s;
	tmp = atoi(arg);
	// tmp_s = ft_itoa(tmp);
	// if (strcmp(tmp_s, arg) == 0)
	// {*num = tmp; return 1;}
	return (0);
}

int 	get_next_oper(char *out)
{
	return (0);
}



void	process_oper(char *oper)
{
	if (strcmp(oper, ""))
}

int 	main(int ac, char **av)
{
	size_t 	i;
	char 	oper[10];
	if (ac > 1)
	{
		i = ac - 1;
		while (i)
		{
			puts(av[i]);
			// VALIDATION!
			stack_push(stack_a(), atoi(av[i]));
			i--;
		}
		show();
		while (get_next_oper(oper))
		{

		}
		kill();
	}
	return (0);
}