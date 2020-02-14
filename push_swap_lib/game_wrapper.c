/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a17641238 <a17641238@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:40:42 by a17641238         #+#    #+#             */
/*   Updated: 2020/02/14 18:42:22 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pstack.h"
#include <stdio.h>
#include <zconf.h>

/*
** Stack A and B singletones
*/

t_pstack	*a__(void)
{
	static t_pstack		*ptr = NULL;

	if (!ptr)
	{
		ptr = init_stack();
	}
	return (ptr);
}

t_pstack	*b__(void)
{
	static t_pstack		*ptr = NULL;

	if (!ptr)
	{
		ptr = init_stack();
	}
	return (ptr);
}

void		kill(void)
{
	static int		killed = FALSE;

	if (!killed)
	{
		killed = TRUE;
		destroy_stack(a__());
		destroy_stack(b__());
	}
}

int			check_a(void)
{
	size_t		i;

	i = a__()->size - 1;
	while (i)
	{
		if (a__()->stack[i] >= a__()->stack[i - 1])
			return (FALSE);
		i--;
	}
	return (TRUE);
}

int			check(void)
{
	size_t		i;

	if (b__()->size == 0)
	{
		i = a__()->size - 1;
		while (i)
		{
			if (a__()->stack[i] >= a__()->stack[i - 1])
				return (FALSE);
			i--;
		}
		return (TRUE);
	}
	return (FALSE);
}
