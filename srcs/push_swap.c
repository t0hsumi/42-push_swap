#include <push_swap.h>

void stacks_init(stacks_t *s) {
	if ((void *)s==NULL) {
		exit(EXIT_FAILURE);
	}
	s->stack_a = malloc(sizeof(dllist_t));
	s->stack_b = malloc(sizeof(dllist_t));
	dllist_init(s->stack_a, sizeof(int));
	dllist_init(s->stack_b, sizeof(int));
}

void stacks_dispose(stacks_t *s) {
	dllist_dispose(s->stack_a);
	dllist_dispose(s->stack_b);
	free(s->stack_a);
	s->stack_a = NULL;
	free(s->stack_b);
	s->stack_b = NULL;
}

void stacks_sa(stacks_t *s) {
	dllist_swaptop(s->stack_a);
}

void stacks_sb(stacks_t *s) {
	dllist_swaptop(s->stack_b);
}

void stacks_ss(stacks_t *s) {
	stacks_sa(s);
	stacks_sb(s);
}

void stacks_ra(stacks_t *s) {
	dllist_rotate(s->stack_a);
}

void stacks_rb(stacks_t *s) {
	dllist_rotate(s->stack_b);
}

void stacks_rr(stacks_t *s) {
	stacks_ra(s);
	stacks_rb(s);
}

void stacks_rra(stacks_t *s) {
	dllist_r_rotate(s->stack_a);
}

void stacks_rrb(stacks_t *s) {
	dllist_r_rotate(s->stack_b);
}

void stacks_rrr(stacks_t *s) {
	stacks_rra(s);
	stacks_rrb(s);
}

void stacks_pa(stacks_t *s) {
	int elem_out;

	if (s->stack_b->length == 0)
		return;
	dllist_removetop(s->stack_b, &elem_out);
	dllist_addtop(s->stack_a, &elem_out);
}

void stacks_pb(stacks_t *s) {
	int elem_out;

	if (s->stack_a->length == 0)
		return;
	dllist_removetop(s->stack_a, &elem_out);
	dllist_addtop(s->stack_b, &elem_out);
}
