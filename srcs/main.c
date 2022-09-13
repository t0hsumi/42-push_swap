#include <dllist.h>
#include <utils.h>
#include <stdio.h>
#include <push_swap.h>

void print_sol(stacks_t *s) {
	dlnode_t *cur = s->solution->dummy->next;
	char *inst[11] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr"};
	while (cur != s->solution->dummy) {
		enum instruction tmp = *(enum instruction *)cur->data;
		printf("%s", inst[tmp]);
		cur = cur->next;
	}
}

int main(int argc, char **argv) {
	stacks_t s;
	
	stacks_init(&s, argc);
	for (int i = 1; i < argc; i++) {
		int tmp = ft_atoi(argv[i]);
		dllist_addlast(s.stack_a, &tmp);
		s.num[i-1] = tmp;
	}
	quicksort(s.num, 0, argc-1);
	if (argc-1 <= 10) s.n = 5;
	else if (argc-1 <= 150) s.n = 8;
	else s.n = 18;
	s.middleindex = (argc-1)/2;
	s.chunksize = (argc-1)/s.n;
	s.stacksize = argc-1;
	a_to_b(&s);
	b_to_a(&s);
	print_sol(&s);
	stacks_dispose(&s);
}

