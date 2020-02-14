/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_wrapper2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a17641238 <a17641238@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:40:48 by a17641238         #+#    #+#             */
/*   Updated: 2020/02/14 18:25:52 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pstack.h"

void		sa(void)
{
	stack_swap_2_top_elements(a__());
}

void		sb(void)
{
	stack_swap_2_top_elements(b__());
}

void		ss(void)
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

void		pb(void)
{
	PSTACK_TYPE		tmp;

	if (stack_pop(a__(), &tmp) == PS_OK)
	{
		stack_push(b__(), tmp);
	}
}
