#include <stdio.h>
#include "push_swap_lib/pushswap.h"
#include "utilities.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "sorter.h"

static void		error_exit(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int 	valid(char *arg, int *num)
{
	int 	tmp;
	char	*tmp_s;
	tmp = ft_atoi(arg);
	tmp_s = ft_itoa(tmp);
	if (strcmp(tmp_s, arg) == 0 && !is_there_(_a(), tmp))
	{
		*num = tmp;
		free(tmp_s);
		return (1);
	}
	free(tmp_s);
	return (0);
}

int main(int ac, char **av)
{
	size_t 	i;
	int 	value;

	if (ac > 1)
	{
		i = ac - 1;
		while (i)
		{
			if (valid(av[i], &value))
				stack_push(_a(), atoi(av[i]));
			else
				error_exit();
			i--;
		}
		sort();
		kill();
	}
}