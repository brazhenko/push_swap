/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a17641238 <a17641238@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:40:14 by a17641238         #+#    #+#             */
/*   Updated: 2020/02/14 11:40:14 by a17641238        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_lib/pstack.h"

#define A_UP_B_UP		0
#define A_DOWN_B_DOWN	1
#define A_UP_B_DOWN		2
#define A_DOWN_B_UP		3

static void	a_up_b_up(size_t *arr)
{
	while (arr[6] && arr[7])
	{
		rr_();
		arr[6]--;
		arr[7]--;
	}
	while (arr[6])
	{
		ra_();
		arr[6]--;
	}
	while (arr[7])
	{
		rb_();
		arr[7]--;
	}
}

static void	a_down_b_down(size_t *arr)
{
	while (arr[6] && arr[7])
	{
		rrr_();
		arr[6]--;
		arr[7]--;
	}
	while (arr[6])
	{
		rra_();
		arr[6]--;
	}
	while (arr[7])
	{
		rrb_();
		arr[7]--;
	}
}

static void	a_down_b_up(size_t *arr)
{
	while (arr[6])
	{
		rra_();
		arr[6]--;
	}
	while (arr[7])
	{
		rb_();
		arr[7]--;
	}
}

static void	a_up_b_down(size_t *arr)
{
	while (arr[6])
	{
		ra_();
		arr[6]--;
	}
	while (arr[7])
	{
		rrb_();
		arr[7]--;
	}
}

void		process_put(size_t *arr)
{
	if (arr[5] == A_UP_B_UP)
		a_up_b_up(arr);
	else if (arr[5] == A_DOWN_B_DOWN)
		a_down_b_down(arr);
	else if (arr[5] == A_DOWN_B_UP)
		a_down_b_up(arr);
	else if (arr[5] == A_UP_B_DOWN)
		a_up_b_down(arr);
	pa_();
}
