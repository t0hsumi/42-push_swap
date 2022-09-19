#include <push_swap.h>
#include <utils.h>
#include <limits.h>

void load_args(stacks_t *s, int argc, char **argv) {
	int i;
	int tmp;
	long arg_num;

	i = 0;
	while (++i < argc) {
		arg_num = ft_atoi(argv[i]);
		if (arg_num == LONG_MIN) {
			write(2, "Error\n", 6);
			stacks_dispose(s);
			exit(EXIT_FAILURE);
		}
		tmp = (int)arg_num;
		dllist_addlast(s->stack_a, &tmp);
		s->num[i-1] = tmp;
	}
	quicksort(s->num, 0, argc-1);
}

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

void print_sol(stacks_t *s) {
	dlnode_t *cur = s->solution->dummy->next;
	char *inst[11] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
	while (cur != s->solution->dummy) {
		enum instruction tmp = *(enum instruction *)cur->data;
		write(1, inst[tmp], ft_strlen(inst[tmp]));
		cur = cur->next;
	}
}

void sort_stacks(stacks_t *s) {
	a_to_b(s);
	b_to_a(s);
}

