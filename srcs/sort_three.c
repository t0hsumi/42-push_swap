/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smallsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:02:28 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/29 12:39:30 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_first(t_stacks *s)
{
	if (*(int *)s->stack_a->dummy->next->next->data == s->num[1])
		stacks_sa(s);
	else
		stacks_rra(s);
	stacks_sa(s);
}

static void	sort_second(t_stacks *s)
{
	if (*(int *)s->stack_a->dummy->next->next->data == s->num[0])
		stacks_sa(s);
	else
		stacks_rra(s);
}

static void	sort_third(t_stacks *s)
{
	if (*(int *)s->stack_a->dummy->next->next->data == s->num[0])
		stacks_ra(s);
	else
	{
		stacks_sa(s);
		stacks_rra(s);
	}
}

void	sort_three(t_stacks *s)
{
	if (*(int *)s->stack_a->dummy->next->data == s->num[0])
		sort_first(s);
	else if (*(int *)s->stack_a->dummy->next->data == s->num[1])
		sort_second(s);
	else
		sort_third(s);
}
