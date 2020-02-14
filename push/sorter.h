/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a17641238 <a17641238@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:40:28 by a17641238         #+#    #+#             */
/*   Updated: 2020/02/14 18:25:02 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H
# define SORTER_H

# include "../push_swap_lib/pstack.h"

void	sort(void);
void	sort2(void);
void	sort3(void);

void	normalize();
void	fill_one(void);

size_t	find_min_id_in_a(void);
void	push_all_except_3_in_b(void);
void	pop_up_from_a(size_t num);
size_t	find_the_ok_place_in_a(PSTACK_TYPE val);
void	calc_shortest_way_len(size_t a, size_t b, size_t *arr);
void	process_put(size_t *arr);

#endif
