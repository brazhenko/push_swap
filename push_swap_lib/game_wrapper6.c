/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_wrapper6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <lreznak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:40:29 by lreznak-          #+#    #+#             */
/*   Updated: 2020/02/14 18:40:37 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zconf.h>
#include "pstack.h"

void		rrr_(void)
{
	rrr();
	write(1, "rrr\n", 4);
}

void		rrr(void)
{
	rra();
	rrb();
}
