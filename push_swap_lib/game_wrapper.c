#include "pushswap.h"
#include <stdio.h>
#include <zconf.h>

/*
 * Stack A and B singletones
 */

t_pstack		*_a(void)
{
	static t_pstack		*ptr = NULL;

	if (!ptr)
	{
		ptr = init_stack();
	}
	return (ptr);
}

t_pstack		*_b(void)
{
	static t_pstack		*ptr = NULL;

	if (!ptr)
	{
		ptr = init_stack();
	}
	return (ptr);
}

void		sa(void)
{
	stack_swap_2_top_elements(_a());
}

void 		sb(void)
{
	stack_swap_2_top_elements(_b());
}

void 		ss(void)
{
	sa();
	sb();
}

void		pa(void)
{
	PSTACK_TYPE		tmp;

	if (stack_pop(_b(), &tmp) == PS_OK)
	{
		stack_push(_a(), tmp);
	}

}

void 		pb(void)
{
	PSTACK_TYPE		tmp;

	if (stack_pop(_a(), &tmp) == PS_OK)
	{
		stack_push(_b(), tmp);
	}
}

void		ra(void)
{
	stack_rot(_a());
}

void		rb(void)
{
	stack_rot(_b());
}

void 		rr(void)
{
	ra();
	rb();
}

void 		rra(void)
{
	stack_rev_rot(_a());
}

void 		rrb(void)
{
	stack_rev_rot(_b());
}

void 		rrr(void)
{
	rra();
	rrb();
}

/*
 * could be called ONLY ONCE!
 */

void		kill(void)
{
	destroy_stack(_a());
	destroy_stack(_b());
}

int 	check_a(void)
{
	size_t		i;

	i = _a()->size - 1;
	while (i)
	{
		if (_a()->stack[i] >= _a()->stack[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int 	check(void)
{
	size_t		i;

	if (_b()->size == 0)
	{
		i = _a()->size - 1;
		while (i)
		{
			if (_a()->stack[i] >= _a()->stack[i - 1])
				return (0);
			i--;
		}
		return (1);
	}
	return (0);
}

void 		show(void)
{
	printf("STACK A: size %zu, capacity %zu\n",
			_a()->size, _a()->capacity);
	printf("STACK B: size %zu, capacity %zu\n",
			_b()->size, _b()->capacity);
	stack_print(_a());
	stack_print(_b());
}

void		sa_(void)
{
	sa();
	write(1, "sa\n", 4);
}

void		sb_(void)
{
	sb();
	write(1, "sb\n", 3);
}

void		ss_(void)
{
	ss();
	write(1, "ss\n", 3);
}

void		pa_(void)
{
	pa();
	write(1, "pa\n", 3);
}

void		pb_(void)
{
	pb();
	write(1, "pb\n", 3);
}

void		ra_(void)
{
	ra();
	write(1, "ra\n", 3);
}

void		rb_(void)
{
	rb();
	write(1, "rb\n", 3);
}

void		rr_(void)
{
	rr();
	write(1, "rr\n", 3);
}

void		rra_(void)
{
	rra();
	write(1, "rra\n", 4);
}

void		rrb_(void)
{
	rrb();
	write(1, "rrb\n", 4);
}

void		rrr_(void)
{
	rrr();
	write(1, "rrr\n", 4);
}