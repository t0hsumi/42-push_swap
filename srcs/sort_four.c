/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:40:32 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/29 12:40:34 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_four(t_stacks *s)
{
	t_dlnode	*cur;

	cur = s->stack_a->dummy->next;
	while (cur != s->stack_a->dummy)
	{
		if (*(int *)cur->data == s->num[3])
		{
			stacks_pb(s);
			break ;
		}
		cur = cur->next;
		stacks_ra(s);
	}
	sort_three(s);
	stacks_pa(s);
	stacks_ra(s);
}
