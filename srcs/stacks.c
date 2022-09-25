#include <stacks.h>

void stacks_init(t_stacks *s, int argc) {
	if ((void *)s==NULL) {
		exit(EXIT_FAILURE);
	}
	s->stack_a = malloc(sizeof(t_dllist ));
	s->stack_b = malloc(sizeof(t_dllist ));
	s->solution = malloc(sizeof(enum e_instruction));
	if (!s->stack_a || !s->stack_b || !s->solution) {
		exit(EXIT_FAILURE);
	}
	dllist_init(s->stack_a, sizeof(int));
	dllist_init(s->stack_b, sizeof(int));
	dllist_init(s->solution, sizeof(enum e_instruction));
	s->num = (int *)malloc(sizeof(int) * (argc-2));
	if (s->num == NULL) exit(EXIT_FAILURE);
	if (argc-1 <= 10) s->n = 5;
	else if (argc-1 <= 150) s->n = 8;
	else s->n = 18;
	s->middleindex = (argc-1)/2;
	s->chunksize = (argc-1)/s->n;
	s->stacksize = argc-1;
}

void stacks_dispose(t_stacks *s) {
	dllist_dispose(s->stack_a);
	dllist_dispose(s->stack_b);
	dllist_dispose(s->solution);
	free(s->stack_a);
	s->stack_a = NULL;
	free(s->stack_b);
	s->stack_b = NULL;
	free(s->solution);
	s->solution = NULL;
	free(s->num);
	s->num = NULL;
}

void stacks_sa(t_stacks *s) {
	enum e_instruction cur = sa;

	if ((void *)s == NULL) {
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_a->length <= 1)
		return;
	dllist_swaptop(s->stack_a);
	dllist_addlast(s->solution, &cur);
}

void stacks_sb(t_stacks *s) {
	enum e_instruction cur = sb;

	if ((void *)s == NULL) {
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_b->length <= 1)
		return;
	dllist_swaptop(s->stack_b);
	dllist_addlast(s->solution, &cur);
}

void stacks_ss(t_stacks *s) {
	enum e_instruction cur = ss;

	if ((void *)s == NULL) {
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_a->length <= 1 && s->stack_a->length <= 1)
		return;
	stacks_sa(s);
	stacks_sb(s);
	dllist_addlast(s->solution, &cur);
}

void stacks_ra(t_stacks *s) {
	enum e_instruction cur = ra;

	if ((void *)s == NULL) {
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_a->length <= 1)
		return;
	dllist_rotate(s->stack_a);
	dllist_addlast(s->solution, &cur);
}

void stacks_rb(t_stacks *s) {
	enum e_instruction cur = rb;

	if ((void *)s == NULL) {
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_b->length <= 1)
		return;
	dllist_rotate(s->stack_b);
	dllist_addlast(s->solution, &cur);
}

void stacks_rr(t_stacks *s) {
	enum e_instruction cur = rr;

	if ((void *)s == NULL) {
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_a->length <= 1 && s->stack_a->length <= 1)
		return;
	stacks_ra(s);
	stacks_rb(s);
	dllist_addlast(s->solution, &cur);
}

void stacks_rra(t_stacks *s) {
	enum e_instruction cur = rra;

	if ((void *)s == NULL) {
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_a->length <= 1)
		return;
	dllist_r_rotate(s->stack_a);
	dllist_addlast(s->solution, &cur);
}

void stacks_rrb(t_stacks *s) {
	enum e_instruction cur = rrb;

	if ((void *)s == NULL) {
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_b->length <= 1)
		return;
	dllist_r_rotate(s->stack_b);
	dllist_addlast(s->solution, &cur);
}

void stacks_rrr(t_stacks *s) {
	enum e_instruction cur = rrr;

	if ((void *)s == NULL) {
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_a->length <= 1 && s->stack_a->length <= 1)
		return;
	stacks_rra(s);
	stacks_rrb(s);
	dllist_addlast(s->solution, &cur);
}

void stacks_pa(t_stacks *s) {
	enum e_instruction cur = pa;
	int elem_out;

	if ((void *)s == NULL) {
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_b->length == 0)
		return;
	dllist_remove(s->stack_b, s->stack_b->dummy->next, &elem_out);
	dllist_addtop(s->stack_a, &elem_out);
	dllist_addlast(s->solution, &cur);
}

void stacks_pb(t_stacks *s) {
	enum e_instruction cur = pb;
	int elem_out;

	if ((void *)s == NULL) {
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_a->length == 0)
		return;
	dllist_remove(s->stack_a, s->stack_a->dummy->next, &elem_out);
	dllist_addtop(s->stack_b, &elem_out);
	dllist_addlast(s->solution, &cur);
}
