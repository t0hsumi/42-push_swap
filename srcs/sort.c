#include <push_swap.h>

static void a_to_b(stacks_t *s) {
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

static void b_to_a(stacks_t *s) {
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

void sort_stacks(stacks_t *s) {
	if (s->stacksize == 2) {
		stacks_sa(s);
		if (*(int *)s->stack_a->dummy->next->data == s->num[1])
			stacks_sa(s);
	}
	else if (s->stacksize == 3) {
		sort_three(s);
	} else if (s->stacksize == 4) {
		sort_four(s);
	} else if (s->stacksize == 5) {
		sort_five(s);
	}
	else {
		a_to_b(s);
		b_to_a(s);
	}
}
