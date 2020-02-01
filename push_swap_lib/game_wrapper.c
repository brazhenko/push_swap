#include "pushswap.h"
#include <stdio.h>


/*
 * Stack A and B singletones
 */

t_pstack		*stack_a(void)
{
	static t_pstack		*ptr = NULL;

	if (!ptr)
	{
		ptr = init_stack();
	}
	return (ptr);
}

t_pstack		*stack_b(void)
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
	stack_swap_2_top_elements(stack_a());
}

void 		sb(void)
{
	stack_swap_2_top_elements(stack_b());
}

void 		ss(void)
{
	sa();
	sb();
}

void		pa(void)
{
	PSTACK_TYPE		tmp;

	if (stack_pop(stack_b(), &tmp) == PS_OK)
	{
		stack_push(stack_a(), tmp);
	}

}

void 		pb(void)
{
	PSTACK_TYPE		tmp;

	if (stack_pop(stack_a(), &tmp) == PS_OK)
	{
		stack_push(stack_b(), tmp);
	}
}

void		ra(void)
{
	stack_rot(stack_a());
}

void		rb(void)
{
	stack_rot(stack_b());
}

void 		rr(void)
{
	ra();
	rb();
}

void 		rra(void)
{
	stack_rev_rot(stack_a());
}

void 		rrb(void)
{
	stack_rev_rot(stack_b());
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
	destroy_stack(stack_a());
	destroy_stack(stack_b());
}

int 	check(void)
{
	size_t		i;

	if (stack_b()->size == 0)
	{
		i = stack_a()->size - 1;
		while (i)
		{
			if (stack_a()->stack[i] >= stack_a()->stack[i - 1])
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
			stack_a()->size, stack_a()->capacity);
	printf("STACK B: size %zu, capacity %zu\n",
			stack_b()->size, stack_b()->capacity);
	stack_print(stack_a());
	stack_print(stack_b());
}