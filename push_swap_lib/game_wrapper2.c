#include "pstack.h"

void		sa(void)
{
	stack_swap_2_top_elements(a__());
}

void 		sb(void)
{
	stack_swap_2_top_elements(b__());
}

void 		ss(void)
{
	sa();
	sb();
}

void		pa(void)
{
	PSTACK_TYPE		tmp;

	if (stack_pop(b__(), &tmp) == PS_OK)
	{
		stack_push(a__(), tmp);
	}

}

void 		pb(void)
{
	PSTACK_TYPE		tmp;

	if (stack_pop(a__(), &tmp) == PS_OK)
	{
		stack_push(b__(), tmp);
	}
}

