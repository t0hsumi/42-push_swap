/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_none.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:36:32 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/29 12:36:34 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <utils.h>

static t_dlnode	*find_ra_rotate(t_stacks *s, t_dlnode *cur)
{
	t_dlnode			*tmp;
	enum e_instruction	inst;

	tmp = cur->next;
	while (tmp != s->solution->dummy)
	{
		inst = *(enum e_instruction *)tmp->data;
		if (inst == sb || inst == ra || inst == rr || inst == rrb)
			tmp = tmp->next;
		else if (inst == ra)
			break ;
		else
			tmp = s->solution->dummy;
	}
	if (tmp == s->solution->dummy)
		return (NULL);
	else
		return (tmp);
}

void	rra_ra(t_stacks *s)
{
	t_dlnode	*cur;
	t_dlnode	*tmp;
	int			elem_out;

	cur = s->solution->dummy->next;
	while (cur != s->solution->dummy)
	{
		if (*(enum e_instruction *)cur->data == rra)
		{
			tmp = find_ra_rotate(s, cur);
			if (tmp)
			{
				cur = cur->prev;
				dllist_remove(s->solution, tmp, &elem_out);
				dllist_remove(s->solution, cur->next, &elem_out);
			}
		}
		cur = cur->next;
	}
}

static t_dlnode	*find_rra_rotate(t_stacks *s, t_dlnode *cur)
{
	t_dlnode			*tmp;
	enum e_instruction	inst;

	tmp = cur->next;
	while (tmp != s->solution->dummy)
	{
		inst = *(enum e_instruction *)tmp->data;
		if (inst == sb || inst == ra || inst == rr || inst == rrb)
			tmp = tmp->next;
		else if (inst == rra)
			break ;
		else
			tmp = s->solution->dummy;
	}
	if (tmp == s->solution->dummy)
		return (NULL);
	else
		return (tmp);
}

void	ra_rra(t_stacks *s)
{
	t_dlnode			*cur;
	t_dlnode			*tmp;
	int					elem_out;

	cur = s->solution->dummy->next;
	while (cur != s->solution->dummy)
	{
		if (*(enum e_instruction *)cur->data == ra)
		{
			tmp = find_rra_rotate(s, cur);
			if (tmp)
			{
				cur = cur->prev;
				dllist_remove(s->solution, tmp, &elem_out);
				dllist_remove(s->solution, cur->next, &elem_out);
			}
		}
		cur = cur->next;
	}
}
