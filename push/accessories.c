/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessories.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a17641238 <a17641238@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:39:50 by a17641238         #+#    #+#             */
/*   Updated: 2020/02/14 11:39:50 by a17641238        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_lib/pstack.h"

size_t		find_min_id_in_a(void)
{
	size_t		i;
	size_t		min_id;

	min_id = 0;
	i = 0;
	while (i < a__()->size)
	{
		if (a__()->stack[i] < a__()->stack[min_id])
			min_id = i;
		i++;
	}
	return (min_id);
}

void		pop_up_from_a(size_t num)
{
	PSTACK_TYPE		el;

	el = a__()->stack[num];
	if (num < a__()->size / 2)
	{
		while (a__()->stack[a__()->size - 1] != el)
		{
			rra_();
		}
	}
	else
	{
		while (a__()->stack[a__()->size - 1] != el)
		{
			ra_();
		}
	}
}

void		push_all_except_3_in_b(void)
{
	while (a__()->size != 3)
	{
		pb_();
	}
}

size_t		find_the_ok_place_in_a(PSTACK_TYPE val)
{
	size_t		i;

	i = 1;
	while (i < a__()->size)
	{
		if (a__()->stack[i - 1] > val && val > a__()->stack[i])
		{
			return (i - 1);
		}
		i++;
	}
	if (a__()->stack[a__()->size - 1] > val && val > a__()->stack[0])
		return (a__()->size - 1);
	return (find_min_id_in_a());
}

void		normalize(void)
{
	size_t		i;

	i = find_min_id_in_a();
	pop_up_from_a(i);
}
