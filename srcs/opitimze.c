#include <push_swap.h>

static void ra_rb(stacks_t *s) {
	dlnode_t *cur = s->solution->dummy->next;
	enum instruction RR = rr;

	while (cur != s->solution->dummy) {
		if (*(enum instruction *)cur->data == ra) {
			int flag = 0;
			dlnode_t *tmp = cur->next;
			while (tmp != s->solution->dummy) {
				enum instruction inst = *(enum instruction *)tmp->data;
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
				dllist_remove(s->solution, tmp);
				memcpy(cur->data, &RR, s->solution->elem_size);
			}
		}
		cur = cur->next;
	}
}

static void rb_ra(stacks_t *s) {
	dlnode_t *cur = s->solution->dummy->next;
	enum instruction RR = rr;

	while (cur != s->solution->dummy) {
		if (*(enum instruction *)cur->data == rb) {
			int flag = 0;
			dlnode_t *tmp = cur->next;
			while (tmp != s->solution->dummy) {
				enum instruction inst = *(enum instruction *)tmp->data;
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
				dllist_remove(s->solution, tmp);
				memcpy(cur->data, &RR, s->solution->elem_size);
			}
		}
		cur = cur->next;
	}
}

static void rra_ra(stacks_t *s) {
	dlnode_t *cur = s->solution->dummy->next;

	while (cur != s->solution->dummy) {
		if (*(enum instruction *)cur->data == rra) {
			int flag = 0;
			dlnode_t *tmp = cur->next;
			while (tmp != s->solution->dummy) {
				enum instruction inst = *(enum instruction *)tmp->data;
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
				dllist_remove(s->solution, tmp);
				dllist_remove(s->solution, cur->next);
			}
		}
		cur = cur->next;
	}
}

static void ra_rra(stacks_t *s) {
	dlnode_t *cur = s->solution->dummy->next;

	while (cur != s->solution->dummy) {
		if (*(enum instruction *)cur->data == ra) {
			int flag = 0;
			dlnode_t *tmp = cur->next;
			while (tmp != s->solution->dummy) {
				enum instruction inst = *(enum instruction *)tmp->data;
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
				dllist_remove(s->solution, tmp);
				dllist_remove(s->solution, cur->next);
			}
		}
		cur = cur->next;
	}
}

void sol_optimize(stacks_t *s) {
	ra_rb(s);
	rb_ra(s);
	ra_rra(s);
	rra_ra(s);
	return;
}
