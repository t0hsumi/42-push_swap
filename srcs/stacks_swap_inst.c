/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_swap_inst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:44:06 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/29 12:44:16 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

void	stacks_sa(t_stacks *s)
{
	enum e_instruction	cur;

	cur = sa;
	if ((void *)s == NULL)
	{
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_a->length <= 1)
		return ;
	dllist_swaptop(s->stack_a);
	dllist_addlast(s->solution, &cur);
}

void	stacks_sb(t_stacks *s)
{
	enum e_instruction	cur;

	cur = sb;
	if ((void *)s == NULL)
	{
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_b->length <= 1)
		return ;
	dllist_swaptop(s->stack_b);
	dllist_addlast(s->solution, &cur);
}

void	stacks_ss(t_stacks *s)
{
	enum e_instruction	cur;

	cur = ss;
	if ((void *)s == NULL)
	{
		write(2, INPUT_ERR, sizeof(INPUT_ERR));
		exit(EXIT_FAILURE);
	}
	if (s->stack_a->length <= 1 && s->stack_a->length <= 1)
		return ;
	stacks_sa(s);
	stacks_sb(s);
	dllist_addlast(s->solution, &cur);
}
