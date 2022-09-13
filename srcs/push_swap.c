#include <push_swap.h>
#include <stdio.h>

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

void a_to_b(stacks_t *s) {
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

void b_to_a(stacks_t *s) {
	int i = s->stacksize - 1;
	int down = 0;
	//printf("init\n");
	//print(s);

	while (s->stack_b->length) {
		int tmp = *(int *)s->stack_b->dummy->next->data;
		if (tmp == s->num[i]) {
			stacks_pa(s);
			//printf("first cond : pa\n");
			//print(s);
			i--;
			while (down > 0 && i >= 0 && s->stack_a->dummy->prev->data && s->num[i]==*(int *)s->stack_a->dummy->prev->data) {
				stacks_rra(s);
				//printf("first cond : rra\n");
				//print(s);
				down--;
				i--;
			}
		} else if (s->stack_a->length == 0){
			stacks_pa(s);
			//printf("second cond : pa\n");
			//print(s);
			down++;
		} else if (down == 0 || tmp > *(int *)s->stack_a->dummy->prev->data){
			stacks_pa(s);
			stacks_ra(s);
			//printf("third cond : pa ra\n");
			//print(s);
			down++;
		} else {
			int j = 1;
			dlnode_t *cur = s->stack_a->dummy->prev;
			while (j <= down) {
				if (*(int *)cur->data < tmp)
					break;
				j++;
				cur = cur->prev;
			}
			if (j == down+1) {
				int k = down;
				while (k--)
					stacks_rra(s);
				stacks_pa(s);
				//printf("forth cond down : rra* + pa\n");
				//print(s);
				k = down+1;
				while (k--) {
					stacks_ra(s);
				}
			} else {
				int k = j - 1;
				while (k--) {
					stacks_rra(s);
				}
				stacks_pa(s);
				//printf("forth cond : rra* + pa\n");
				//print(s);
				while (j--) {
					stacks_ra(s);
				}
			}
			//printf("forth cond : last\n");
			//print(s);
			down++;
		}
	}
}

void stacks_init(stacks_t *s, int argc) {
	if ((void *)s==NULL) {
		exit(EXIT_FAILURE);
	}
	s->stack_a = malloc(sizeof(dllist_t));
	if (s->stack_a == NULL) {
		exit(EXIT_FAILURE);
	}
	s->stack_b = malloc(sizeof(dllist_t));
	if (s->stack_b == NULL) {
		exit(EXIT_FAILURE);
	}
	s->solution = malloc(sizeof(enum instruction));
	if (s->solution == NULL) {
		exit(EXIT_FAILURE);
	}
	dllist_init(s->stack_a, sizeof(int));
	dllist_init(s->stack_b, sizeof(int));
	dllist_init(s->solution, sizeof(enum instruction));
	s->num = (int *)malloc(sizeof(int) * (argc-2));
	if (s->num == NULL) exit(EXIT_FAILURE);
}

void stacks_dispose(stacks_t *s) {
	dllist_dispose(s->stack_a);
	dllist_dispose(s->stack_b);
	dllist_dispose(s->solution);
	free(s->stack_a);
	s->stack_a = NULL;
	free(s->stack_b);
	s->stack_b = NULL;
	free(s->solution);
	s->solution = NULL;
	free(s->num);
	s->num = NULL;
}

void stacks_sa(stacks_t *s) {
	enum instruction cur = sa;
	dllist_swaptop(s->stack_a);
	dllist_addlast(s->solution, &cur);
}

void stacks_sb(stacks_t *s) {
	enum instruction cur = sb;
	dllist_swaptop(s->stack_b);
	dllist_addlast(s->solution, &cur);
}

void stacks_ss(stacks_t *s) {
	enum instruction cur = ss;
	stacks_sa(s);
	stacks_sb(s);
	dllist_addlast(s->solution, &cur);
}

void stacks_ra(stacks_t *s) {
	enum instruction cur = ra;
	dllist_rotate(s->stack_a);
	dllist_addlast(s->solution, &cur);
}

void stacks_rb(stacks_t *s) {
	enum instruction cur = rb;
	dllist_rotate(s->stack_b);
	dllist_addlast(s->solution, &cur);
}

void stacks_rr(stacks_t *s) {
	enum instruction cur = rr;
	stacks_ra(s);
	stacks_rb(s);
	dllist_addlast(s->solution, &cur);
}

void stacks_rra(stacks_t *s) {
	enum instruction cur = rra;
	dllist_r_rotate(s->stack_a);
	dllist_addlast(s->solution, &cur);
}

void stacks_rrb(stacks_t *s) {
	enum instruction cur = rrb;
	dllist_r_rotate(s->stack_b);
	dllist_addlast(s->solution, &cur);
}

void stacks_rrr(stacks_t *s) {
	enum instruction cur = rrr;
	stacks_rra(s);
	stacks_rrb(s);
	dllist_addlast(s->solution, &cur);
}

void stacks_pa(stacks_t *s) {
	enum instruction cur = pa;
	int elem_out;

	if (s->stack_b->length == 0)
		return;
	dllist_removetop(s->stack_b, &elem_out);
	dllist_addtop(s->stack_a, &elem_out);
	dllist_addlast(s->solution, &cur);
}

void stacks_pb(stacks_t *s) {
	enum instruction cur = pb;
	int elem_out;

	if (s->stack_a->length == 0)
		return;
	dllist_removetop(s->stack_a, &elem_out);
	dllist_addlast(s->solution, &cur);
	dllist_addtop(s->stack_b, &elem_out);
}
