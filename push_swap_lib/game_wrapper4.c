/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_wrapper4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a17641238 <a17641238@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:40:58 by a17641238         #+#    #+#             */
/*   Updated: 2020/02/14 11:40:58 by a17641238        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zconf.h>
#include "pstack.h"

void		sa_(void)
{
	sa();
	write(1, "sa\n", 3);
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

