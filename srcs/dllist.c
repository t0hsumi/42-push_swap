/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:02:14 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/28 12:33:00 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dllist.h>
#include <utils.h>

void	dllist_init(t_dllist *l, size_t elem_size)
{
	if ((void *)l == NULL || elem_size <= 0)
	{
		write(2, INIT_ERR_MSG, sizeof(INIT_ERR_MSG));
		exit(EXIT_FAILURE);
	}
	l->dummy = malloc(sizeof(t_dlnode));
	if (l->dummy == NULL)
	{
		write(2, "malloc", 6);
		exit(EXIT_FAILURE);
	}
	l->elem_size = elem_size;
	l->length = 0;
	l->dummy->next = l->dummy;
	l->dummy->prev = l->dummy;
	l->dummy->data = NULL;
}

void	dllist_remove(t_dllist *l, t_dlnode*cur, void *elem_out)
{
	if ((void *)l == NULL || elem_out == NULL)
	{
		write(2, REMOVE_ERR_MSG, sizeof(REMOVE_ERR_MSG));
		exit(EXIT_FAILURE);
	}
	if (l->length == 0)
	{
		elem_out = NULL;
		return ;
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

void	dllist_dispose(t_dllist *l)
{
	t_dlnode	*node;
	t_dlnode	*old_node;

	if ((void *)l == NULL)
	{
		write(2, DISPOSE_ERR_MSG, sizeof(DISPOSE_ERR_MSG));
		exit(EXIT_FAILURE);
	}
	node = l->dummy->next;
	while (node != l->dummy)
	{
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
