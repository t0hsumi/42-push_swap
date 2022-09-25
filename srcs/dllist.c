#include <dllist.h>
#include <utils.h>

void dllist_init(t_dllist *l, size_t elem_size) {
	if ((void *)l == NULL || elem_size <= 0) {
		write(2, INIT_ERR_MSG, sizeof(INIT_ERR_MSG));
		exit(EXIT_FAILURE);
	}
	l->dummy = malloc(sizeof(t_dlnode));
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

void dllist_addtop(t_dllist *l, void *elem) {
	t_dlnode*node;

	if ((void *)l == NULL || elem == NULL) {
		write(2, ADDTOP_ERR_MSG, sizeof(ADDTOP_ERR_MSG));
		exit(EXIT_FAILURE);
	}
	node = malloc(sizeof(t_dlnode));
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
	ft_memcpy(node->data, elem, l->elem_size);
}

void dllist_addlast(t_dllist *l, void *elem) {
	t_dlnode*node;

	if ((void *)l == NULL || elem == NULL) {
		write(2, ADDLAST_ERR_MSG, sizeof(ADDLAST_ERR_MSG));
		exit(EXIT_FAILURE);
	}
	node = malloc(sizeof(t_dlnode));
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
	ft_memcpy(node->data, elem, l->elem_size);
}

void dllist_swaptop(t_dllist *l) {
	if ((void *)l == NULL) {
		write(2, SWAP_ERR_MSG , sizeof(SWAP_ERR_MSG));
		exit(EXIT_FAILURE);
	}

	if (l->length < 2)
		return;
	t_dlnode*tmp = l->dummy->next->next->next;
	tmp->prev = l->dummy->next;
	l->dummy->next = l->dummy->next->next;
	l->dummy->next->next = tmp->prev;
	l->dummy->next->prev = l->dummy;
	tmp->prev->next = tmp;
	tmp->prev->prev = l->dummy->next;
}

void dllist_rotate(t_dllist *l) {
	if ((void *)l == NULL) {
		write(2, ROTATE_ERR_MSG , sizeof(ROTATE_ERR_MSG));
		exit(EXIT_FAILURE);
	}
	if (l->length <= 1) return;
	t_dlnode*right = l->dummy->next->next;
	t_dlnode*left = l->dummy->prev;

	left->next = l->dummy->next;
	left->next->prev = left;
	right->prev = l->dummy;
	right->prev->next = right;
	l->dummy->prev = left->next;
	left->next->next = l->dummy;
}

void dllist_r_rotate(t_dllist *l) {
	if ((void *)l == NULL) {
		write(2, R_ROTATE_ERR_MSG , sizeof(R_ROTATE_ERR_MSG));
		exit(EXIT_FAILURE);
	}
	if (l->length <= 1) return;
	t_dlnode*right = l->dummy->next;
	t_dlnode*left = l->dummy->prev->prev;

	right->prev = l->dummy->prev;
	right->prev->next = right;
	left->next = l->dummy;
	left->next->prev = left;
	l->dummy->next = right->prev;
	right->prev->prev = l->dummy;
}

void dllist_remove(t_dllist *l, t_dlnode*cur, void *elem_out) {
	if ((void *)l == NULL || elem_out == NULL) {
		write(2, REMOVE_ERR_MSG , sizeof(REMOVE_ERR_MSG));
		exit(EXIT_FAILURE);
	}
	if (l->length == 0) {
		elem_out = NULL;
		return;
	}
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	ft_memcpy(elem_out, cur->data, l->elem_size);
	--l->length;
	free(cur->data);
	cur->data = NULL;
	free(cur);
	cur = NULL;
}

void dllist_dispose(t_dllist *l) {
	t_dlnode*node;
	t_dlnode*old_node;

	if ((void *)l == NULL) {
		write(2, DISPOSE_ERR_MSG , sizeof(DISPOSE_ERR_MSG));
		exit(EXIT_FAILURE);
	}
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

