/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_rev_rotate_inst.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:42:48 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/29 12:42:49 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

void	stacks_rra(t_stacks *s)
{
	enum e_instruction	cur;

	cur = rra;
	if ((void *)s == NULL)
	{
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_a->length <= 1)
		return ;
	dllist_r_rotate(s->stack_a);
	dllist_addlast(s->solution, &cur);
}

void	stacks_rrb(t_stacks *s)
{
	enum e_instruction	cur;

	cur = rrb;
	if ((void *)s == NULL)
	{
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_b->length <= 1)
		return ;
	dllist_r_rotate(s->stack_b);
	dllist_addlast(s->solution, &cur);
}

void	stacks_rrr(t_stacks *s)
{
	enum e_instruction	cur;

	cur = rrr;
	if ((void *)s == NULL)
	{
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_a->length <= 1 && s->stack_a->length <= 1)
		return ;
	stacks_rra(s);
	stacks_rrb(s);
	dllist_addlast(s->solution, &cur);
}
