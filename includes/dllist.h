/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:39:24 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/30 18:44:41 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLLIST_H
# define DLLIST_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define INIT_ERR_MSG "dllist_init:invalid argument to function input"
# define ADDTOP_ERR_MSG "dllist_addtop:invalid argument to function input"
# define ADDLAST_ERR_MSG "dllist_addlast:invalid argument to function input"
# define SWAP_ERR_MSG "dllist_swaptop:invalid argument to function input"
# define ROTATE_ERR_MSG "dllist_rotate:invalid argument to function input"
# define R_ROTATE_ERR_MSG "dllist_r_rotate:invalid argument to function input"
# define REMOVETOP_ERR_MSG "dllist_remove_top:\
	invalid argument to function input"
# define REMOVE_ERR_MSG "dllist_remove:invalid argument to function input"
# define DISPOSE_ERR_MSG "dllist_dispose:invalid argument to function input"

typedef struct t_dlnode {
	void			*data;
	struct t_dlnode	*next;
	struct t_dlnode	*prev;
}	t_dlnode;

typedef struct t_dllist {
	size_t		elem_size;
	size_t		length;
	t_dlnode	*dummy;
}	t_dllist;

/* dllist.c */
void	dllist_init(t_dllist *l, size_t elem_size);
void	dllist_remove(t_dllist *l, t_dlnode *cur, void *elem_out);
void	dllist_dispose(t_dllist *l);

/* dllist_instructions.c */
void	dllist_addlast(t_dllist *l, void *elem);
void	dllist_addtop(t_dllist *l, void *elem);
void	dllist_swaptop(t_dllist *l);
void	dllist_rotate(t_dllist *l);
void	dllist_r_rotate(t_dllist *l);

#endif
