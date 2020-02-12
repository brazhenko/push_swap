
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>
#include "utilities.h"
#include "checker.h"
#include "../push_swap_lib/pstack.h"

int 		get_next_oper(char *out)
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
	&sa_, &sb_, &ss_, &pa_,
	&pb_, &ra_, &rb_, &rr_,
	&rra_, &rrb_, &rrr_
};

int			process_oper(char *oper)
{
	size_t		i;

	i = 0;
	while (i < PUSH_SWAP_COMMAND_COUNT)
	{
		if (ft_strncmp(oper, g_v[i], MAX_OPER_LEN) == 0)
		{
			g_actions[i]();
			return (0);
		}
		i++;
	}
	puts(oper);
	error_exit();
	return (1);
}

int 		main(int ac, char **av)
{
	char 	oper[MAX_OPER_LEN + 1];

	if (ac > 1)
	{
		parse_argv(ac, av);
//		show();
		while (get_next_oper(oper))
			process_oper(oper);

		if (check())
			write(STDOUT_FILENO, "OK\n", 3);
		else
			write(STDOUT_FILENO, "KO\n", 3);
		//show();
		kill();
	}
	return (0);
}