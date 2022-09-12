#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <dllist.h>

typedef struct stacks_t {
	dllist_t *stack_a;
	dllist_t *stack_b;
} stacks_t;

void stacks_init(stacks_t *s);
void stacks_dispose(stacks_t *s);
void stacks_sa(stacks_t *s);
void stacks_sb(stacks_t *s);
void stacks_ss(stacks_t *s);
void stacks_pa(stacks_t *s);
void stacks_pb(stacks_t *s);
void stacks_ra(stacks_t *s);
void stacks_rb(stacks_t *s);
void stacks_rr(stacks_t *s);
void stacks_rra(stacks_t *s);
void stacks_rrb(stacks_t *s);
void stacks_rrr(stacks_t *s);

#endif
