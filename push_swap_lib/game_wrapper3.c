/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_wrapper3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a17641238 <a17641238@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:40:54 by a17641238         #+#    #+#             */
/*   Updated: 2020/02/14 17:26:50 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pstack.h"

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
