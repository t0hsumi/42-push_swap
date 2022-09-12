#include <dllist.h>

void dllist_init(dllist_t *l, size_t elem_size) {
	if ((void *)l == NULL || elem_size <= 0) {
		write(2, INIT_ERR_MSG, sizeof(INIT_ERR_MSG));
		exit(EXIT_FAILURE);
	}
	l->dummy = malloc(sizeof(dlnode_t));
	if (l->dummy == NULL) {
		write(2, "malloc", 6);
		exit(EXIT_FAILURE);
	}
	l->elem_size = elem_size;
	l->length = 0;

	l->dummy->next = l->dummy;
	l->dummy->prev = l->dummy;
	l->dummy->data = NULL;
}

void dllist_addtop(dllist_t *l, void *elem) {
	dlnode_t *node;

	if ((void *)l == NULL || elem == NULL) {
		write(2, ADD_ERR_MSG, sizeof(ADD_ERR_MSG));
		exit(EXIT_FAILURE);
	}
	node = malloc(sizeof(dlnode_t));
	if (node == NULL) {
		write(2, "malloc", 6);
		exit(EXIT_FAILURE);
	}
	node->data = malloc(l->elem_size);
	if (node->data == NULL) {
		write(2, "malloc", 6);
		exit(EXIT_FAILURE);
	}

	node->next = l->dummy->next;
	node->prev = l->dummy;
	node->prev->next = node;
	node->next->prev = node;

	++l->length;
	memcpy(node->data, elem, l->elem_size);
}

void dllist_addlast(dllist_t *l, void *elem) {
	dlnode_t *node;

	if ((void *)l == NULL || elem == NULL) {
		write(2, ADD_ERR_MSG, sizeof(ADD_ERR_MSG));
		exit(EXIT_FAILURE);
	}
	node = malloc(sizeof(dlnode_t));
	if (node == NULL) {
		write(2, "malloc", 6);
		exit(EXIT_FAILURE);
	}
	node->data = malloc(l->elem_size);
	if (node->data == NULL) {
		write(2, "malloc", 6);
		exit(EXIT_FAILURE);
	}

	node->next = l->dummy;
	node->prev = l->dummy->prev;
	l->dummy->prev->next = node;
	l->dummy->prev = node;

	++l->length;
	memcpy(node->data, elem, l->elem_size);
}

void dllist_swaptop(dllist_t *l) {
	if ((void *)l == NULL) {
		write(2, SWAP_ERR_MSG , sizeof(SWAP_ERR_MSG));
		exit(EXIT_FAILURE);
	}

	if (l->length < 2)
		return;
	dlnode_t *tmp = l->dummy->next->next->next;
	tmp->prev = l->dummy->next;
	l->dummy->next = l->dummy->next->next;
	l->dummy->next->next = tmp->prev;
	l->dummy->next->prev = l->dummy;
	tmp->prev->next = tmp;
	tmp->prev->prev = l->dummy->next;
}

void dllist_rotate(dllist_t *l) {
	dlnode_t *right = l->dummy->next->next;
	dlnode_t *left = l->dummy->prev;

	left->next = l->dummy->next;
	left->next->prev = left;
	right->prev = l->dummy;
	right->prev->next = right;
	l->dummy->prev = left->next;
	left->next->next = l->dummy;
}

void dllist_r_rotate(dllist_t *l) {
	dlnode_t *right = l->dummy->next;
	dlnode_t *left = l->dummy->prev->prev;

	right->prev = l->dummy->prev;
	right->prev->next = right;
	left->next = l->dummy;
	left->next->prev = left;
	l->dummy->next = right->prev;
	right->prev->prev = l->dummy;
}

void dllist_removetop(dllist_t *l, void *elem_out) {
	if (l->length == 0) {
		elem_out = NULL;
		return;
	}
	dlnode_t * node = l->dummy->next;

	node->prev->next = node->next;
	node->next->prev = node->prev;
	memcpy(elem_out, node->data, l->elem_size);
	--l->length;
	free(node->data);
	node->data = NULL;
	free(node);
	node = NULL;
}

void dllist_dispose(dllist_t *l) {
	dlnode_t *node;
	dlnode_t *old_node;

	node = l->dummy->next;
	while (node != l->dummy) {
		free(node->data);
		node->data = NULL;
		old_node = node;
		node = node->next;
		free(old_node);
		old_node = NULL;
	}
	free(l->dummy);
	l->dummy = NULL;
}

