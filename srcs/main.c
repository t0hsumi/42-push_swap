#include <dllist.h>
#include <stdio.h>

void print_dllist(dllist_t *l) {
	dlnode_t *cur = l->dummy->next;
	while (cur != l->dummy) {
		printf("%d ", *(int *)(cur->data));
		cur = cur->next;
	}
	printf("\n");
}

int main(void) {
	dllist_t l;
	dllist_init(&l, sizeof(int));
	for (int i = 0; i< 10; i++) {
		dllist_addlast(&l, &i);
	}
	print_dllist(&l);
	dllist_swaptop(&l);
	print_dllist(&l);
	dllist_rotate(&l);
	print_dllist(&l);
	dllist_r_rotate(&l);
	print_dllist(&l);
	int i;
	dllist_removetop(&l, &i);
	print_dllist(&l);
	printf("%d\n", i);
	dllist_dispose(&l);
	return 0;
}
