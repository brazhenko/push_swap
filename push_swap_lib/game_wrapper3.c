#include "pushswap.h"

void		ra(void)
{
	stack_rot(a__());
}

void		rb(void)
{
	stack_rot(b__());
}

void 		rr(void)
{
	ra();
	rb();
}

void 		rra(void)
{
	stack_rev_rot(a__());
}

void 		rrb(void)
{
	stack_rev_rot(b__());
}

void 		rrr(void)
{
	rra();
	rrb();
}
