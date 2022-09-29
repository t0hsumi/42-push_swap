/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_push_inst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:43:22 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/29 12:43:24 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

void	stacks_pa(t_stacks *s)
{
	enum e_instruction	cur;
	int					elem_out;

	cur = pa;
	if ((void *)s == NULL)
	{
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_b->length == 0)
		return ;
	dllist_remove(s->stack_b, s->stack_b->dummy->next, &elem_out);
	dllist_addtop(s->stack_a, &elem_out);
	dllist_addlast(s->solution, &cur);
}

void	stacks_pb(t_stacks *s)
{
	enum e_instruction	cur;
	int					elem_out;

	cur = pb;
	if ((void *)s == NULL)
	{
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_a->length == 0)
		return ;
	dllist_remove(s->stack_a, s->stack_a->dummy->next, &elem_out);
	dllist_addtop(s->stack_b, &elem_out);
	dllist_addlast(s->solution, &cur);
}
