#ifndef SORTER_H
# define SORTER_H

#include "../push_swap_lib/pstack.h"

void 	sort(void);
void	sort2(void);
void	sort3(void);

void	normalize();
void	fill_one(void);


// accessories

size_t	find_min_id_in_a(void);
void	push_all_except_3_in_b(void);
void	pop_up_from_a(size_t num);
size_t	find_the_ok_place_in_a(PSTACK_TYPE val);
void		calc_shortest_way_len(size_t a, size_t b, size_t *arr);
void		process_put(size_t *arr);
#endif
