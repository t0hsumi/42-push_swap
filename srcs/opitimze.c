#include <push_swap.h>
#include <utils.h>

static void ra_rb(t_stacks *s) {
	t_dlnode*cur = s->solution->dummy->next;
	enum e_instruction RR = rr;
	int elem_out;

	while (cur != s->solution->dummy) {
		if (*(enum e_instruction *)cur->data == ra) {
			int flag = 0;
			t_dlnode*tmp = cur->next;
			while (tmp != s->solution->dummy) {
				enum e_instruction inst = *(enum e_instruction *)tmp->data;
				if (inst == rb) {
					flag = 1;
					break;
				}
				else if (inst == sa || inst == ra || inst == rra){
					tmp = tmp->next;
					continue;
				}
				else
					break;
			}
			if (flag) {
				dllist_remove(s->solution, tmp, &elem_out);
				ft_memcpy(cur->data, &RR, s->solution->elem_size);
			}
		}
		cur = cur->next;
	}
}

static void rra_rrb(t_stacks *s) {
	t_dlnode*cur = s->solution->dummy->next;
	enum e_instruction RRR = rrr;
	int elem_out;

	while (cur != s->solution->dummy) {
		if (*(enum e_instruction *)cur->data == rra) {
			int flag = 0;
			t_dlnode*tmp = cur->next;
			while (tmp != s->solution->dummy) {
				enum e_instruction inst = *(enum e_instruction *)tmp->data;
				if (inst == rrb) {
					flag = 1;
					break;
				}
				else if (inst == sa || inst == ra || inst == rra){
					tmp = tmp->next;
					continue;
				}
				else
					break;
			}
			if (flag) {
				dllist_remove(s->solution, tmp, &elem_out);
				ft_memcpy(cur->data, &RRR, s->solution->elem_size);
			}
		}
		cur = cur->next;
	}
}

static void rb_ra(t_stacks *s) {
	t_dlnode*cur = s->solution->dummy->next;
	enum e_instruction RR = rr;
	int elem_out;

	while (cur != s->solution->dummy) {
		if (*(enum e_instruction *)cur->data == rb) {
			int flag = 0;
			t_dlnode*tmp = cur->next;
			while (tmp != s->solution->dummy) {
				enum e_instruction inst = *(enum e_instruction *)tmp->data;
				if (inst == ra) {
					flag = 1;
					break;
				}
				else if (inst == sb || inst == rb || inst == rrb){
					tmp = tmp->next;
					continue;
				}
				else
					break;
			}
			if (flag) {
				dllist_remove(s->solution, tmp, &elem_out);
				ft_memcpy(cur->data, &RR, s->solution->elem_size);
			}
		}
		cur = cur->next;
	}
}

static void rra_ra(t_stacks *s) {
	t_dlnode*cur = s->solution->dummy->next;
	int elem_out;

	while (cur != s->solution->dummy) {
		if (*(enum e_instruction *)cur->data == rra) {
			int flag = 0;
			t_dlnode*tmp = cur->next;
			while (tmp != s->solution->dummy) {
				enum e_instruction inst = *(enum e_instruction *)tmp->data;
				if (inst == ra) {
					flag = 1;
					break;
				} else if (inst == sb || inst == ra || inst == rr || inst == rrb) {
					tmp = tmp->next;
					continue;
				}
				else
					break;
			}
			if (flag) {
				cur = cur->prev;
				dllist_remove(s->solution, tmp, &elem_out);
				dllist_remove(s->solution, cur->next, &elem_out);
			}
		}
		cur = cur->next;
	}
}

static void ra_rra(t_stacks *s) {
	t_dlnode*cur = s->solution->dummy->next;
	int elem_out;

	while (cur != s->solution->dummy) {
		if (*(enum e_instruction *)cur->data == ra) {
			int flag = 0;
			t_dlnode*tmp = cur->next;
			while (tmp != s->solution->dummy) {
				enum e_instruction inst = *(enum e_instruction *)tmp->data;
				if (inst == rra) {
					flag = 1;
					break;
				} else if (inst == sb || inst == ra || inst == rr || inst == rrb) {
					tmp = tmp->next;
					continue;
				}
				else
					break;
			}
			if (flag) {
				cur = cur->prev;
				dllist_remove(s->solution, tmp, &elem_out);
				dllist_remove(s->solution, cur->next, &elem_out);
			}
		}
		cur = cur->next;
	}
}

void sol_optimize(t_stacks *s) {
	ra_rb(s);
	rb_ra(s);
	ra_rra(s);
	rra_ra(s);
	rra_rrb(s);
	return;
}
