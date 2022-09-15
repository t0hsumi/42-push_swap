#include <push_swap.h>

void a_to_b(stacks_t *s) {
	int start = s->middleindex - s->chunksize;
	int end = s->middleindex + s->chunksize;

	while (0 <= start && end <= s->stacksize-1) {
		int cur_a_len = s->stack_a->length;
		while (cur_a_len) {
			int tmp = *(int *)s->stack_a->dummy->next->data;
			if (s->num[start] <= tmp && tmp <= s->num[end]) {
				stacks_pb(s);
				if (tmp < s->num[s->middleindex]) {
					stacks_rb(s);
				}
			} else {
				stacks_ra(s);
			}
			cur_a_len--;
		}
		start -= s->chunksize;
		end += s->chunksize;
	}
	while (s->stack_a->length != 0) {
		int tmp = *(int *)s->stack_a->dummy->next->data;
		stacks_pb(s);
		if (tmp < s->num[s->middleindex])
			stacks_rb(s);
	}
}

void b_to_a(stacks_t *s) {
	int i = s->stacksize - 1;
	int down = 0;
	int up = 0;

	while (s->stack_b->length) {
		int tmp = *(int *)s->stack_b->dummy->next->data;

		size_t b_max_index = 0;
		dlnode_t *cur = s->stack_b->dummy->next;
		while (cur->data != NULL) {
			if (*(int *)cur->data == s->num[i])
				break;
			b_max_index++;
			cur = cur->next;
		}

		if (tmp == s->num[i]) {
			stacks_pa(s);
			i--;
			if (up) {
				stacks_sa(s);
				up--;
				i--;
			}
			while (down > 0 && i >= 0 && s->num[i]==*(int *)s->stack_a->dummy->prev->data) {
				stacks_rra(s);
				down--;
				i--;
			}
		} else if (i > 0 && s->num[i-1] == tmp) {
			stacks_pa(s);
			up = 1;
		} else if (down == 0 || tmp > *(int *)s->stack_a->dummy->prev->data){
			stacks_pa(s);
			stacks_ra(s);
			down++;
		} else {
			if (b_max_index < s->stack_b->length / 2) {
				while (b_max_index--)
					stacks_rb(s);
			} else {
				b_max_index = s->stack_b->length - b_max_index;
				while (b_max_index--)
					stacks_rrb(s);
			}
			stacks_pa(s);
			i--;
			if (up) {
				stacks_sa(s);
				up--;
				i--;
			}
			while (down > 0 && i >= 0 && s->num[i]==*(int *)s->stack_a->dummy->prev->data) {
				stacks_rra(s);
				down--;
				i--;
			}
		}
	}
}

void stacks_init(stacks_t *s, int argc) {
	if ((void *)s==NULL) {
		exit(EXIT_FAILURE);
	}
	s->stack_a = malloc(sizeof(dllist_t));
	if (s->stack_a == NULL) {
		exit(EXIT_FAILURE);
	}
	s->stack_b = malloc(sizeof(dllist_t));
	if (s->stack_b == NULL) {
		exit(EXIT_FAILURE);
	}
	s->solution = malloc(sizeof(enum instruction));
	if (s->solution == NULL) {
		exit(EXIT_FAILURE);
	}
	dllist_init(s->stack_a, sizeof(int));
	dllist_init(s->stack_b, sizeof(int));
	dllist_init(s->solution, sizeof(enum instruction));
	s->num = (int *)malloc(sizeof(int) * (argc-2));
	if (s->num == NULL) exit(EXIT_FAILURE);
}

void stacks_dispose(stacks_t *s) {
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

void stacks_sa(stacks_t *s) {
	enum instruction cur = sa;
	if (s->stack_a->length <= 1)
		return;
	dllist_swaptop(s->stack_a);
	dllist_addlast(s->solution, &cur);
}

void stacks_sb(stacks_t *s) {
	enum instruction cur = sb;
	if (s->stack_b->length <= 1)
		return;
	dllist_swaptop(s->stack_b);
	dllist_addlast(s->solution, &cur);
}

void stacks_ss(stacks_t *s) {
	enum instruction cur = ss;
	if (s->stack_a->length <= 1 && s->stack_a->length <= 1)
		return;
	stacks_sa(s);
	stacks_sb(s);
	dllist_addlast(s->solution, &cur);
}

void stacks_ra(stacks_t *s) {
	enum instruction cur = ra;
	if (s->stack_a->length <= 1)
		return;
	dllist_rotate(s->stack_a);
	dllist_addlast(s->solution, &cur);
}

void stacks_rb(stacks_t *s) {
	enum instruction cur = rb;
	if (s->stack_b->length <= 1)
		return;
	dllist_rotate(s->stack_b);
	dllist_addlast(s->solution, &cur);
}

void stacks_rr(stacks_t *s) {
	enum instruction cur = rr;
	if (s->stack_a->length <= 1 && s->stack_a->length <= 1)
		return;
	stacks_ra(s);
	stacks_rb(s);
	dllist_addlast(s->solution, &cur);
}

void stacks_rra(stacks_t *s) {
	enum instruction cur = rra;
	if (s->stack_a->length <= 1)
		return;
	dllist_r_rotate(s->stack_a);
	dllist_addlast(s->solution, &cur);
}

void stacks_rrb(stacks_t *s) {
	if (s->stack_b->length <= 1)
		return;
	enum instruction cur = rrb;
	dllist_r_rotate(s->stack_b);
	dllist_addlast(s->solution, &cur);
}

void stacks_rrr(stacks_t *s) {
	enum instruction cur = rrr;
	if (s->stack_a->length <= 1 && s->stack_a->length <= 1)
		return;
	stacks_rra(s);
	stacks_rrb(s);
	dllist_addlast(s->solution, &cur);
}

void stacks_pa(stacks_t *s) {
	enum instruction cur = pa;
	int elem_out;

	if (s->stack_b->length == 0)
		return;
	dllist_remove(s->stack_b, s->stack_b->dummy->next, &elem_out);
	dllist_addtop(s->stack_a, &elem_out);
	dllist_addlast(s->solution, &cur);
}

void stacks_pb(stacks_t *s) {
	enum instruction cur = pb;
	int elem_out;

	if (s->stack_a->length == 0)
		return;
	dllist_remove(s->stack_a, s->stack_a->dummy->next, &elem_out);
	dllist_addtop(s->stack_b, &elem_out);
	dllist_addlast(s->solution, &cur);
}
