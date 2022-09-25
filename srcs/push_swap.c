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

void print_sol(stacks_t *s) {
	dlnode_t *cur = s->solution->dummy->next;
	char *inst[11] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
	while (cur != s->solution->dummy) {
		enum instruction tmp = *(enum instruction *)cur->data;
		write(1, inst[tmp], ft_strlen(inst[tmp]));
		cur = cur->next;
	}
}

