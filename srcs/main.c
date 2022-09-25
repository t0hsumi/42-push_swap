#include <push_swap.h>

int main(int argc, char **argv) {
	t_stacks s;
	
	stacks_init(&s, argc);
	load_args(&s, argc, argv);
	sort_stacks(&s);
	sol_optimize(&s);
	print_sol(&s);
	stacks_dispose(&s);
}

