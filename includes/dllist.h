#ifndef DLLIST_H
#define DLLIST_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define INIT_ERR_MSG "dllist_init : invalid argument to function input"
#define ADD_ERR_MSG "dllist_addlast : invalid argument to function input"
#define SWAP_ERR_MSG "dllist_swaptop : invalid argument to function input"

typedef struct dlnode_t {
	void *data;
	struct dlnode_t *next;
	struct dlnode_t *prev;
} dlnode_t;

typedef struct dllist_t {
	size_t elem_size;
	size_t length;
	dlnode_t *dummy;
} dllist_t;

void dllist_init(dllist_t *l, size_t elem_size);
void dllist_addlast(dllist_t *l, void *elem);
void dllist_addtop(dllist_t *l, void *elem);
void dllist_swaptop(dllist_t *l);
void dllist_rotate(dllist_t *l);
void dllist_r_rotate(dllist_t *l);
void dllist_removetop(dllist_t *l, void *elem_out);
void dllist_dispose(dllist_t *l);

#endif
