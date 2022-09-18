#include <utils.h>
#include <push_swap.h>

int main(int argc, char **argv) {
	stacks_t s;
	
	stacks_init(&s, argc);
	load_args(&s, argc, argv);
	a_to_b(&s);
	b_to_a(&s);
	sol_optimize(&s);
	print_sol(&s);
	stacks_dispose(&s);
}

