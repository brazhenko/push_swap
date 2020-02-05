#include <zconf.h>
#include "pushswap.h"

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

