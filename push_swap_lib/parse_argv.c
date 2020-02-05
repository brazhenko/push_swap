#include <stddef.h>
#include "utilities.h"
#include "pushswap.h"
#include <stdlib.h>
#include <stdio.h>

int 	valid(char *arg, int *num)
{
	int 	tmp;
	char	*tmp_s;
	tmp = ft_atoi(arg);
	tmp_s = ft_itoa(tmp);
	if (ft_strcmp(tmp_s, arg) == 0 && !is_there_(a__(), tmp))
	{
		*num = tmp;
		free(tmp_s);
		return (TRUE);
	}
	free(tmp_s);
	return (FALSE);
}

void 	parse_arg(char *arg)
{
	char		**nums;
	size_t		i;
	int 		num;

	nums = strsplitcharset(arg, " \n\t\v\r\f");
	if (nums)
	{
		i = 0;
		while (nums[i])
			i++;
		while (i--)
		{
			if (valid(nums[i], &num))
				stack_push(a__(), num);
			else
				error_exit();
		}
		charptrptrdel(nums);
	}
}

void	parse_argv(int ac, char **av)
{
	ac--;
	while (ac)
	{
		parse_arg(av[ac]);
		ac--;
	}
}
