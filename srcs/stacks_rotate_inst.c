/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_rotate_inst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:41:49 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/29 12:44:16 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

void	stacks_ra(t_stacks *s)
{
	enum e_instruction	cur;

	cur = ra;
	if ((void *)s == NULL)
	{
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_a->length <= 1)
		return ;
	dllist_rotate(s->stack_a);
	dllist_addlast(s->solution, &cur);
}

void	stacks_rb(t_stacks *s)
{
	enum e_instruction	cur;

	cur = rb;
	if ((void *)s == NULL)
	{
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_b->length <= 1)
		return ;
	dllist_rotate(s->stack_b);
	dllist_addlast(s->solution, &cur);
}

void	stacks_rr(t_stacks *s)
{
	enum e_instruction	cur;

	cur = rr;
	if ((void *)s == NULL)
	{
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_a->length <= 1 && s->stack_a->length <= 1)
		return ;
	stacks_ra(s);
	stacks_rb(s);
	dllist_addlast(s->solution, &cur);
}
