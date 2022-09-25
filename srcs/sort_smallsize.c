#include <push_swap.h>

static void sort_first(t_stacks *s) {
	if (*(int *)s->stack_a->dummy->next->next->data == s->num[1]) {
		stacks_sa(s);
	} else {
		stacks_rra(s);
	}
	stacks_sa(s);
}

static void sort_second(t_stacks *s) {
	if (*(int *)s->stack_a->dummy->next->next->data == s->num[0])
		stacks_sa(s);
	else
		stacks_rra(s);
}

static void sort_third(t_stacks *s) {
	if (*(int *)s->stack_a->dummy->next->next->data == s->num[0])
		stacks_ra(s);
	else {
		stacks_sa(s);
		stacks_rra(s);
	}
}

void sort_three(t_stacks *s) {
	if (*(int *)s->stack_a->dummy->next->data == s->num[0])
		sort_first(s);
	else if (*(int *)s->stack_a->dummy->next->data == s->num[1])
		sort_second(s);
	else
		sort_third(s);
}

void sort_four(t_stacks *s) {
	t_dlnode*cur = s->stack_a->dummy->next;

	while (cur != s->stack_a->dummy) {
		if (*(int *)cur->data == s->num[3]) {
			stacks_pb(s);
			break;
		}
		cur = cur->next;
		stacks_ra(s);
	}
	sort_three(s);
	stacks_pa(s);
	stacks_ra(s);
}

void sort_five(t_stacks *s) {
	t_dlnode*cur = s->stack_a->dummy->next;
	int flag = 0;

	while (cur != s->stack_a->dummy) {
		cur = cur->next;
		if (*(int *)cur->prev->data == s->num[3]) {
			stacks_pb(s);
			flag |= 0b10;
		} else if (*(int *)cur->prev->data == s->num[4]) {
			stacks_pb(s);
			flag |= 0b01;
		} else {
			stacks_ra(s);
		}
		if (flag == 0b11)
			break;
	}
	sort_three(s);
	if (*(int *)s->stack_b->dummy->next->data == s->num[3])
		stacks_sb(s);
	stacks_pa(s);
	stacks_pa(s);
	stacks_ra(s);
	stacks_ra(s);
}
