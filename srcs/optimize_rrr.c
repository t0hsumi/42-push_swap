/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:36:56 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/30 18:38:26 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <utils.h>

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

/*
   The instruction sequence rra -> rrb can be abbrviated rrr.
   rra -> ... -> rrb  =>  rrr -> ... -> nop
*/
void	rra_rrb(t_stacks *s)
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
				ft_memmove(cur->data, &replace, s->solution->elem_size);
			}
		}
		cur = cur->next;
	}
}
