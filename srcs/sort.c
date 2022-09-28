/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:02:43 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/28 11:49:58 by tohsumi          ###   ########.fr       */
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

static void	a_to_b(t_stacks *s)
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

static size_t	find_maxelem_b(t_stacks *s, int index)
{
	t_dlnode	*cur;
	size_t		res;

	res = 0;
	cur = s->stack_b->dummy->next;
	while (cur->data != NULL)
	{
		if (*(int *)cur->data == s->num[index])
			break ;
		res++;
		cur = cur->next;
	}
	return (res);
}

static void	swap_top(t_stacks *s, int *index, int *up)
{
	(*index)--;
	(*up)--;
	stacks_sa(s);
}

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
		swap_top(s, index, up);
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
		swap_top(s, index, up);
}

static void	pa_b_second_elem(t_stacks *s, int *up)
{
	stacks_pa(s);
	(*up) = 1;
}

static void	b_to_a(t_stacks *s)
{
	int			index;
	int			down;
	int			up;
	int			tmp;
	size_t		b_max_index;

	index = s->stacksize - 1;
	down = 0;
	up = 0;
	while (s->stack_b->length)
	{
		tmp = *(int *)s->stack_b->dummy->next->data;
		b_max_index = find_maxelem_b(s, index);
		if (tmp == s->num[index])
			pa_top(s, &index, &up);
		else if (index > 0 && s->num[index - 1] == tmp)
			pa_b_second_elem(s, &up);
		else if (down == 0 || tmp > *(int *)s->stack_a->dummy->prev->data)
			pa_bottom(s, &down);
		else
			pa_max_b(s, b_max_index, &index, &up);
		rotate_below(s, &down, &index);
	}
}

void	sort_stacks(t_stacks *s)
{
	if (s->stacksize == 2)
	{
		stacks_sa(s);
		if (*(int *)s->stack_a->dummy->next->data == s->num[1])
			stacks_sa(s);
	}
	else if (s->stacksize == 3)
		sort_three(s);
	else if (s->stacksize == 4)
		sort_four(s);
	else if (s->stacksize == 5)
		sort_five(s);
	else
	{
		a_to_b(s);
		b_to_a(s);
	}
}
