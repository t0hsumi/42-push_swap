#include <dllist.h>
#include <stdio.h>
#include <push_swap.h>

void print_dllist(dllist_t *l) {
	dlnode_t *cur = l->dummy->next;
	while (cur != l->dummy) {
		printf("%d ", *(int *)(cur->data));
		cur = cur->next;
	}
	printf("\n");
}

void print(stacks_t *s) {
	printf("a : ");
	print_dllist(s->stack_a);
	printf("b : ");
	print_dllist(s->stack_b);
}

int main(void) {
	stacks_t s;
	
	stacks_init(&s);
	for (int i = 0; i < 10; i++) {
		dllist_addlast(s.stack_a, &i);
	}
	print(&s);
	printf("ra\n"); stacks_ra(&s); print(&s);
	printf("pb\n"); stacks_pb(&s); print(&s);
	printf("pb\n"); stacks_pb(&s); print(&s);
	printf("ss\n"); stacks_ss(&s); print(&s);
	printf("ss\n"); stacks_ss(&s); print(&s);
	printf("ra\n"); stacks_ra(&s); print(&s);
	printf("rra\n"); stacks_rra(&s); print(&s);
	printf("rrr\n"); stacks_rrr(&s); print(&s);
	stacks_dispose(&s);
}

