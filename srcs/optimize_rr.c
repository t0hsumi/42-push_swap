/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:36:47 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/29 13:14:46 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <utils.h>

static t_dlnode	*find_rb(t_stacks *s, t_dlnode *cur)
{
	t_dlnode			*tmp;
	enum e_instruction	inst;

	tmp = cur->next;
	while (tmp != s->solution->dummy)
	{
		inst = *(enum e_instruction *)tmp->data;
		if (inst == sa || inst == ra || inst == rra)
			tmp = tmp->next;
		else if (inst == rb)
			break ;
		else
			tmp = s->solution->dummy;
	}
	if (tmp == s->solution->dummy)
		return (NULL);
	else
		return (tmp);
}

void	ra_rb(t_stacks *s)
{
	t_dlnode			*cur;
	t_dlnode			*tmp;
	enum e_instruction	replace;
	int					elem_out;

	cur = s->solution->dummy->next;
	replace = rr;
	while (cur != s->solution->dummy)
	{
		if (*(enum e_instruction *)cur->data == ra)
		{
			tmp = find_rb(s, cur);
			if (tmp)
			{
				dllist_remove(s->solution, tmp, &elem_out);
				ft_memmove(cur->data, &replace, s->solution->elem_size);
			}
		}
		cur = cur->next;
	}
}

static t_dlnode	*find_ra(t_stacks *s, t_dlnode *cur)
{
	t_dlnode			*tmp;
	enum e_instruction	inst;

	tmp = cur->next;
	while (tmp != s->solution->dummy)
	{
		inst = *(enum e_instruction *)tmp->data;
		if (inst == sb || inst == rb || inst == rrb)
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

void	rb_ra(t_stacks *s)
{
	t_dlnode			*cur;
	t_dlnode			*tmp;
	enum e_instruction	replace;
	int					elem_out;

	cur = s->solution->dummy->next;
	replace = rr;
	while (cur != s->solution->dummy)
	{
		if (*(enum e_instruction *)cur->data == rb)
		{
			tmp = find_ra(s, cur);
			if (tmp)
			{
				dllist_remove(s->solution, tmp, &elem_out);
				ft_memmove(cur->data, &replace, s->solution->elem_size);
			}
		}
		cur = cur->next;
	}
}
