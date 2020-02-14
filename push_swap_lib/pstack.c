/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pstack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a17641238 <a17641238@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:41:16 by a17641238         #+#    #+#             */
/*   Updated: 2020/02/14 18:38:18 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pstack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <utilities.h>

#define NUL '\0'

/*
** stack ctor
*/

t_pstack		*init_stack(void)
{
	t_pstack	*ret;

	ret = xmalloc(sizeof(t_pstack));
	ft_memset(ret, 0, sizeof(*ret));
	ret->stack = xmalloc(PSTACK_INIT_CAPACITY * sizeof(PSTACK_TYPE));
	ret->capacity = PSTACK_INIT_CAPACITY;
	return (ret);
}


/*
** t_pstack *stack must be malloced before being freed
*/

void 			destroy_stack(t_pstack *stack)
{
	if (stack)
	{
		if (stack->capacity > NUL)
		{
			ft_memset(stack->stack, 0, stack->capacity * sizeof(PSTACK_TYPE));
			free(stack->stack);
		}
		ft_memset(stack, 0, sizeof(*stack));
		free(stack);
	}
}

int 			stack_push(t_pstack *stack, PSTACK_TYPE value)
{
	PSTACK_TYPE		*ptr;
	PSTACK_TYPE		*tmp;

	if (stack->capacity > stack->size)
	{
		stack->stack[stack->size] = value;
		stack->size++;
	}
	else
	{
		tmp = stack->stack;
		ptr = xmalloc(stack->capacity * sizeof(PSTACK_TYPE)
				+ PSTACK_EXTRA_CAPACITY * sizeof(PSTACK_TYPE));
		stack->stack = ptr;
		ft_memcpy(ptr, tmp, sizeof(PSTACK_TYPE) * stack->size);
		ft_memset(tmp, 0, sizeof(PSTACK_TYPE) * stack->size);
		free(tmp);
		stack->stack = ptr;
		stack->capacity += PSTACK_EXTRA_CAPACITY;
		stack->stack[stack->size] = value;
		stack->size++;

	}
	return (PS_OK);
}

int 		stack_pop(t_pstack *stack, PSTACK_TYPE *ptr)
{
	PSTACK_TYPE		ret;

	if (stack)
	{
		if (stack->size)
		{
			ret = stack->stack[stack->size - 1];
			stack->size--;
			*ptr = (ret);
			return (PS_OK);
		}
		return (PS_STACK_EMPTY);
	}
	return (PS_STACK_NULLPTR);
}

size_t			stack_size(t_pstack *stack)
{
	return (stack->size);
}

int	 	stack_swap_2_top_elements(t_pstack *stack)
{
	PSTACK_TYPE		tmp;

	if (stack->size >= 2)
	{
		tmp = stack->stack[stack->size - 1];
		stack->stack[stack->size - 1] = stack->stack[stack->size - 2];
		stack->stack[stack->size - 2] = tmp;
		return (PS_OK);
	}
	return (PS_NOT_ENOUGH_ELEMS);
}

int 	stack_rot(t_pstack *stack)
{
	PSTACK_TYPE		tmp;
	size_t			i;

	if (stack && stack->size > 0)
	{
		tmp = stack->stack[stack->size - 1];
		i = stack->size - 1;
		while (i)
		{
			stack->stack[i] = stack->stack[i - 1];
			i--;
		}
		stack->stack[0] = tmp;
		return (PS_OK);
	}
	return (PS_STACK_EMPTY);
}

int 	stack_rev_rot(t_pstack *stack)
{
	PSTACK_TYPE		tmp;
	size_t			i;

	if (stack && stack->size > 0)
	{
		tmp = stack->stack[0];
		i = 0;
		while (i < stack->size - 1)
		{
			stack->stack[i] = stack->stack[i + 1];
			i++;
		}
		stack->stack[stack->size - 1] = tmp;
		return (PS_OK);
	}
	return (PS_STACK_EMPTY);
}

int		is_there_(t_pstack *stack, PSTACK_TYPE el)
{
	size_t		i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] == el)
			return (1);
		i++;
	}
	return (0);
}
