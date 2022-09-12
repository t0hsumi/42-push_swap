#include <dllist.h>
#include <utils.h>
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

long ft_atoi(const char *s) {
	int i = 0;
	long res = 0;
	while (s[i]) {
		if ('0' <= s[i] && s[i] <= '9') {
			res *= 10;
			res += (long)(s[i] - '0');
		}
		i++;
	}
	return res;
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
	for (int i = 0; i < argc-1; i++) {
		printf("%d ", s.num[i]);
	}
	printf("\n");
	if (argc-1 <= 10) s.n = 5;
	else if (argc-1 <= 150) s.n = 8;
	else s.n = 18;
	s.middle = (s.num[0]+s.num[argc-2])/2;
	s.chunksize = (argc-1)/s.n;
	stacks_dispose(&s);
}

