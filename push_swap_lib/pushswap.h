#ifndef PUSHSWAP_H

# include <stddef.h>
# include <stdint.h>
# define PUSHSWAP_H

# define PSTACK_INIT_CAPACITY	10
# define PSTACK_EXTRA_CAPACITY	20
# define PSTACK_TYPE			uint32_t

/*
 * Errors
 */

# define PS_OK					0
# define PS_NOT_ENOUGH_ELEMS	1
# define PS_STACK_EMPTY			2
# define PS_STACK_NULLPTR		3

typedef struct	s_pstack t_pstack;
struct	s_pstack
{
	PSTACK_TYPE	*stack;
	size_t		size;
	size_t		capacity;
};

t_pstack		*init_stack(void);
void 			destroy_stack(t_pstack *stack);
int 			stack_push(t_pstack *stack, PSTACK_TYPE value);
int				stack_pop(t_pstack *stack, PSTACK_TYPE *ptr);
int 			stack_empty(t_pstack *stack);
size_t			stack_size(t_pstack *stack);
int 			stack_swap_2_top_elements(t_pstack *stack);
void			stack_print(t_pstack *pstack);
int 			stack_rev_rot(t_pstack *stack);
int 			stack_rot(t_pstack *stack);
int				is_there_(t_pstack *stack, PSTACK_TYPE el);

/*
 * game wrapping
 */

# define PUSH_SWAP_COMMAND_COUNT	11
# define MAX_OPER_LEN				4

t_pstack		*stack_a(void);
t_pstack		*stack_b(void);
void 			sa(void);
void 			sb(void);
void 			ss(void);
void 			pa(void);
void 			pb(void);
void 			ra(void);
void 			rb(void);
void 			rr(void);
void 			rra(void);
void 			rrb(void);
void 			rrr(void);
void 			show(void);
int 			check(void);
void			kill(void);

#endif