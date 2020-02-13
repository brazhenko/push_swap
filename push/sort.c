#include "sorter.h"

void		sort2(void)
{
	if (check())
	{
		return ;
	}
	sa_();
}

void		sort3(void)
{
	if (check_a())
		return ;
	else if (a__()->stack[2] > a__()->stack[1] && a__()->stack[1] <
			a__()->stack[0] && a__()->stack[0] > a__()->stack[2])
		sa_();
	else if (a__()->stack[2] > a__()->stack[1] &&
			a__()->stack[1] > a__()->stack[0])
	{
		sa_();
		rra_();
	}
	else if (a__()->stack[2] > a__()->stack[1] && a__()->stack[1] <
			a__()->stack[0] && a__()->stack[0] < a__()->stack[2])
		ra_();
	else if (a__()->stack[2] < a__()->stack[1] && a__()->stack[1] >
			a__()->stack[0] && a__()->stack[0] > a__()->stack[2])
	{
		sa_();
		ra_();
	}
	else if (a__()->stack[2] < a__()->stack[1] && a__()->stack[1] >
			a__()->stack[0] && a__()->stack[0] < a__()->stack[2])
		rra_();
}

void		sortelse(void)
{
	push_all_except_3_in_b();
	sort3();
	while (b__()->size != 0)
	{
		fill_one();
	}
	normalize();
}

void 	sort(void)
{
	if (a__()->size == 1 || check())
		return ;
	else if (a__()->size == 2)
		sort2();
	else if (a__()->size == 3)
		sort3();
	else
		sortelse();
}
