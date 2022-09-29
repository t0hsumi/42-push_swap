/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:33:04 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/29 13:14:46 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dllist.h>
#include <utils.h>

void	dllist_addtop(t_dllist *l, void *elem)
{
	t_dlnode	*node;

	if ((void *)l == NULL || elem == NULL)
	{
		write(2, ADDTOP_ERR_MSG, sizeof(ADDTOP_ERR_MSG));
		exit(EXIT_FAILURE);
	}
	node = malloc(sizeof(t_dlnode));
	if (node == NULL)
	{
		write(2, "malloc", 6);
		exit(EXIT_FAILURE);
	}
	node->data = malloc(l->elem_size);
	if (node->data == NULL)
	{
		write(2, "malloc", 6);
		exit(EXIT_FAILURE);
	}
	node->next = l->dummy->next;
	node->prev = l->dummy;
	node->prev->next = node;
	node->next->prev = node;
	++l->length;
	ft_memmove(node->data, elem, l->elem_size);
}

void	dllist_addlast(t_dllist *l, void *elem)
{
	t_dlnode	*node;

	if ((void *)l == NULL || elem == NULL)
	{
		write(2, ADDLAST_ERR_MSG, sizeof(ADDLAST_ERR_MSG));
		exit(EXIT_FAILURE);
	}
	node = malloc(sizeof(t_dlnode));
	if (node == NULL)
	{
		write(2, "malloc", 6);
		exit(EXIT_FAILURE);
	}
	node->data = malloc(l->elem_size);
	if (node->data == NULL)
	{
		write(2, "malloc", 6);
		exit(EXIT_FAILURE);
	}
	node->next = l->dummy;
	node->prev = l->dummy->prev;
	l->dummy->prev->next = node;
	l->dummy->prev = node;
	++l->length;
	ft_memmove(node->data, elem, l->elem_size);
}

void	dllist_swaptop(t_dllist *l)
{
	t_dlnode	*tmp;

	if ((void *)l == NULL)
	{
		write(2, SWAP_ERR_MSG, sizeof(SWAP_ERR_MSG));
		exit(EXIT_FAILURE);
	}
	if (l->length < 2)
		return ;
	tmp = l->dummy->next->next->next;
	tmp->prev = l->dummy->next;
	l->dummy->next = l->dummy->next->next;
	l->dummy->next->next = tmp->prev;
	l->dummy->next->prev = l->dummy;
	tmp->prev->next = tmp;
	tmp->prev->prev = l->dummy->next;
}

void	dllist_rotate(t_dllist *l)
{
	t_dlnode	*right;
	t_dlnode	*left;

	if ((void *)l == NULL)
	{
		write(2, ROTATE_ERR_MSG, sizeof(ROTATE_ERR_MSG));
		exit(EXIT_FAILURE);
	}
	if (l->length <= 1)
		return ;
	right = l->dummy->next->next;
	left = l->dummy->prev;
	left->next = l->dummy->next;
	left->next->prev = left;
	right->prev = l->dummy;
	right->prev->next = right;
	l->dummy->prev = left->next;
	left->next->next = l->dummy;
}

void	dllist_r_rotate(t_dllist *l)
{
	t_dlnode	*right;
	t_dlnode	*left;

	if ((void *)l == NULL)
	{
		write(2, R_ROTATE_ERR_MSG, sizeof(R_ROTATE_ERR_MSG));
		exit(EXIT_FAILURE);
	}
	if (l->length <= 1)
		return ;
	right = l->dummy->next;
	left = l->dummy->prev->prev;
	right->prev = l->dummy->prev;
	right->prev->next = right;
	left->next = l->dummy;
	left->next->prev = left;
	l->dummy->next = right->prev;
	right->prev->prev = l->dummy;
}
