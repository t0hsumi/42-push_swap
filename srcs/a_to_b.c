/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:46:23 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/29 12:46:24 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	pb_rest(t_stacks *s)
{
	int	tmp;

	while (s->stack_a->length != 0)
	{
		tmp = *(int *)s->stack_a->dummy->next->data;
		stacks_pb(s);
		if (tmp < s->num[s->middleindex])
			stacks_rb(s);
	}
}

void	a_to_b(t_stacks *s)
{
	int	cur_a_len;
	int	tmp;
	int	size;

	size = s->chunksize;
	while (0 <= s->middleindex - size && s->middleindex + size < s->stacksize)
	{
		cur_a_len = s->stack_a->length + 1;
		while (--cur_a_len)
		{
			tmp = *(int *)s->stack_a->dummy->next->data;
			if (s->num[s->middleindex - size] <= tmp && \
					tmp < s->num[s->middleindex + size])
			{
				stacks_pb(s);
				if (tmp < s->num[s->middleindex])
					stacks_rb(s);
			}
			else
				stacks_ra(s);
		}
		size += s->chunksize;
	}
	pb_rest(s);
}
