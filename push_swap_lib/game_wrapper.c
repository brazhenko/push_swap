#include "pstack.h"
#include <stdio.h>
#include <zconf.h>

/*
** Stack A and B singletones
*/

t_pstack	*a__(void)
{
	static t_pstack		*ptr = NULL;

	if (!ptr)
	{
		ptr = init_stack();
	}
	return (ptr);
}

t_pstack	*b__(void)
{
	static t_pstack		*ptr = NULL;

	if (!ptr)
	{
		ptr = init_stack();
	}
	return (ptr);
}

void		kill(void)
{
	static int 		killed = FALSE;

	if (!killed)
	{
		killed = TRUE;
		destroy_stack(a__());
		destroy_stack(b__());
	}
}

int 	check_a(void)
{
	size_t		i;

	i = a__()->size - 1;
	while (i)
	{
		if (a__()->stack[i] >= a__()->stack[i - 1])
			return (FALSE);
		i--;
	}
	return (TRUE);
}

int 	check(void)
{
	size_t		i;

	if (b__()->size == 0)
	{
		i = a__()->size - 1;
		while (i)
		{
			if (a__()->stack[i] >= a__()->stack[i - 1])
				return (FALSE);
			i--;
		}
		return (TRUE);
	}
	return (FALSE);
}

void 		show(void)
{
	printf("STACK A: size %zu, capacity %zu\n",
			a__()->size, a__()->capacity);
	printf("STACK B: size %zu, capacity %zu\n",
			b__()->size, b__()->capacity);
	stack_print(a__());
	stack_print(b__());
}

