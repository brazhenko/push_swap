#include "../push_swap_lib/pushswap.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>
#include "utilities.h"
#include "checker.h"

int 	valid(char *arg, int *num)
{
	int 	tmp;
	char	*tmp_s;
	tmp = ft_atoi(arg);
	tmp_s = ft_itoa(tmp);
	if (strcmp(tmp_s, arg) == 0 && !is_there_(stack_a(), tmp))
	{
		*num = tmp;
		free(tmp_s);
		return (1);
	}
	free(tmp_s);
	return (0);
}

int 	get_next_oper(char *out)
{
	char	c;
	size_t 	i;

	memset(out, 1, MAX_OPER_LEN + 1);
	i = 0;
	while (read(0, &c, 1))
	{
		if (c == '\n')
		{
			out[i] = 0;
			return (1);
		}
		out[i] = c;
		i++;
		if (i >= MAX_OPER_LEN)
			error_exit();
	}
	return (0);
}

const char *g_v[PUSH_SWAP_COMMAND_COUNT] =
{
	"sa", "sb", "ss", "pa",
	"pb", "ra", "rb", "rr",
	"rra", "rrb", "rrr"
};

void (*g_actions[PUSH_SWAP_COMMAND_COUNT])(void) =
{
	&sa, &sb, &ss, &pa,
	&pb, &ra, &rb, &rr,
	&rra, &rrb, &rrr
};

int		process_oper(char *oper)
{
	size_t		i;

	i = 0;
	while (i < PUSH_SWAP_COMMAND_COUNT)
	{
		if (strncmp(oper, g_v[i], MAX_OPER_LEN) == 0)
		{
			g_actions[i]();
			return (0);
		}
		i++;
	}
	error_exit();
	return (1);
}

int 	main(int ac, char **av)
{
	size_t 	i;
	int 	value;
	char 	oper[MAX_OPER_LEN + 1];

	if (ac > 1)
	{
		i = ac - 1;
		while (i)
		{
			puts(av[i]);
			// VALIDATION!
			if (valid(av[i], &value))
				stack_push(stack_a(), atoi(av[i]));
			else
				error_exit();
			i--;
		}
		show();
		while (get_next_oper(oper))
			process_oper(oper);
		if (check())
			puts("OK");
		else
			puts("KO");
		kill();
	}
	return (0);
}