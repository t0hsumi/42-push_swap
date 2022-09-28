/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opitimze.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:51:03 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/28 11:51:04 by tohsumi          ###   ########.fr       */
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

static void	ra_rb(t_stacks *s)
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
				ft_memcpy(cur->data, &replace, s->solution->elem_size);
			}
		}
		cur = cur->next;
	}
}

static t_dlnode	*find_rrb(t_stacks *s, t_dlnode *cur)
{
	t_dlnode			*tmp;
	enum e_instruction	inst;

	tmp = cur->next;
	while (tmp != s->solution->dummy)
	{
		inst = *(enum e_instruction *)tmp->data;
		if (inst == sa || inst == ra || inst == rra)
			tmp = tmp->next;
		else if (inst == rrb)
			break ;
		else
			tmp = s->solution->dummy;
	}
	if (tmp == s->solution->dummy)
		return (NULL);
	else
		return (tmp);
}

static void	rra_rrb(t_stacks *s)
{
	t_dlnode			*cur;
	t_dlnode			*tmp;
	enum e_instruction	replace;
	int					elem_out;

	cur = s->solution->dummy->next;
	replace = rrr;
	while (cur != s->solution->dummy)
	{
		if (*(enum e_instruction *)cur->data == rra)
		{
			tmp = find_rrb(s, cur);
			if (tmp)
			{
				dllist_remove(s->solution, tmp, &elem_out);
				ft_memcpy(cur->data, &replace, s->solution->elem_size);
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

static void	rb_ra(t_stacks *s)
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
				ft_memcpy(cur->data, &replace, s->solution->elem_size);
			}
		}
		cur = cur->next;
	}
}

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

static void	rra_ra(t_stacks *s)
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

static void	ra_rra(t_stacks *s)
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

void	sol_optimize(t_stacks *s)
{
	ra_rb(s);
	rb_ra(s);
	ra_rra(s);
	rra_ra(s);
	rra_rrb(s);
	return ;
}
