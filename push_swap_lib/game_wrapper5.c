#include <zconf.h>
#include "pushswap.h"

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