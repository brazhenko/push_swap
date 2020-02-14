/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_shortest_way_len.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a17641238 <a17641238@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:39:55 by a17641238         #+#    #+#             */
/*   Updated: 2020/02/14 11:39:55 by a17641238        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_lib/pstack.h"
#include "utilities.h"

#define A_UP_B_UP		0
#define A_DOWN_B_DOWN	1
#define A_UP_B_DOWN		2
#define A_DOWN_B_UP		3

static void a_up_b_down(size_t *arr)
{
	arr[4] = arr[0] + arr[3];
	arr[5] = A_UP_B_DOWN;
	arr[6] = arr[0];
	arr[7] = arr[3];
}

static void a_down_b_up(size_t *arr)
{
	arr[4] = arr[2] + arr[1];
	arr[5] = A_DOWN_B_UP;
	arr[6] = arr[1];
	arr[7] = arr[2];
}

static void a_up_b_up(size_t *arr)
{
	arr[4] = max(arr[0], arr[2]);
	arr[5] = A_UP_B_UP;
	arr[6] = arr[0];
	arr[7] = arr[2];
}

static void a_down_b_down(size_t *arr)
{
	arr[4] = max(arr[1], arr[3]);
	arr[5] = A_DOWN_B_DOWN;
	arr[6] = arr[1];
	arr[7] = arr[3];
}

void		calc_shortest_way_len(size_t a, size_t b, size_t *arr)
{
	arr[0] = a__()->size - a - 1;
	arr[1] = a + 1;
	arr[2] = b__()->size - b - 1;
	arr[3] = b + 1;
	if (arr[0] + arr[3] < arr[4])
		a_up_b_down(arr);
	else if (arr[2] + arr[1] < arr[4])
		a_down_b_up(arr);
	else if (max(arr[0], arr[2]) < arr[4])
		a_up_b_up(arr);
	else if (max(arr[1], arr[3]) < arr[4])
		a_down_b_down(arr);
}