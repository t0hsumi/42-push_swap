/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:40:41 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/29 12:40:44 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	pa_max_elem(t_stacks *s)
{
	if (*(int *)s->stack_b->dummy->next->data == s->num[3])
		stacks_sb(s);
	stacks_pa(s);
	stacks_pa(s);
	stacks_ra(s);
	stacks_ra(s);
}

void	sort_five(t_stacks *s)
{
	int	cur;
	int	flag;

	flag = 0;
	while (1)
	{
		cur = *(int *)s->stack_a->dummy->next->data;
		if (cur == s->num[3] || cur == s->num[4])
		{
			if (cur == s->num[3])
				flag |= 0b01;
			else
				flag |= 0b10;
			stacks_pb(s);
		}
		else
			stacks_ra(s);
		if (flag == 0b11)
			break ;
	}
	sort_three(s);
	pa_max_elem(s);
}
