/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_push_inst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:43:22 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/29 22:59:52 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

void	stacks_pa(t_stacks *s)
{
	enum e_instruction	cur;
	t_dlnode			*elem_out;

	cur = pa;
	if ((void *)s == NULL)
	{
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_b->length == 0)
		return ;
	elem_out = s->stack_b->dummy->next;
	elem_out->next->prev = elem_out->prev;
	elem_out->prev->next = elem_out->next;
	elem_out->next = s->stack_a->dummy->next;
	elem_out->prev = s->stack_a->dummy;
	elem_out->next->prev = elem_out;
	elem_out->prev->next = elem_out;
	dllist_addlast(s->solution, &cur);
	s->stack_a->length++;
	s->stack_b->length--;
}

void	stacks_pb(t_stacks *s)
{
	enum e_instruction	cur;
	t_dlnode			*elem_out;

	cur = pb;
	if ((void *)s == NULL)
	{
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_a->length == 0)
		return ;
	elem_out = s->stack_a->dummy->next;
	elem_out->next->prev = elem_out->prev;
	elem_out->prev->next = elem_out->next;
	elem_out->next = s->stack_b->dummy->next;
	elem_out->prev = s->stack_b->dummy;
	elem_out->next->prev = elem_out;
	elem_out->prev->next = elem_out;
	dllist_addlast(s->solution, &cur);
	s->stack_a->length--;
	s->stack_b->length++;
}
