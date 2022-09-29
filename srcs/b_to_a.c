/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:48:33 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/29 12:59:28 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <utils.h>

static void	rotate_below(t_stacks *s, int *down, int *index)
{
	while (*down > 0 && *index >= 0 && \
			s->num[*index] == *(int *)s->stack_a->dummy->prev->data)
	{
		stacks_rra(s);
		(*down)--;
		(*index)--;
	}
}

static void	pa_max_b(t_stacks *s, size_t b_max_index, int *index, int *up)
{
	if (b_max_index < s->stack_b->length / 2)
		while (b_max_index--)
			stacks_rb(s);
	else
	{
		b_max_index = s->stack_b->length - b_max_index;
		while (b_max_index--)
			stacks_rrb(s);
	}
	stacks_pa(s);
	(*index)--;
	if (*up)
	{
		(*index)--;
		(*up)--;
		stacks_sa(s);
	}
}

static void	pa_bottom(t_stacks *s, int *down)
{
	stacks_pa(s);
	stacks_ra(s);
	(*down)++;
}

static void	pa_top(t_stacks *s, int *index, int *up)
{
	stacks_pa(s);
	(*index)--;
	if (*up)
	{
		(*index)--;
		(*up)--;
		stacks_sa(s);
	}
}

void	b_to_a(t_stacks *s)
{
	int			index;
	int			down;
	int			up;
	int			tmp;

	index = s->stacksize - 1;
	down = 0;
	up = 0;
	while (s->stack_b->length)
	{
		tmp = *(int *)s->stack_b->dummy->next->data;
		if (tmp == s->num[index])
			pa_top(s, &index, &up);
		else if (index > 0 && s->num[index - 1] == tmp)
		{
			stacks_pa(s);
			up = 1;
		}
		else if (down == 0 || tmp > *(int *)s->stack_a->dummy->prev->data)
			pa_bottom(s, &down);
		else
			pa_max_b(s, find_elem_location(s, index), &index, &up);
		rotate_below(s, &down, &index);
	}
}
