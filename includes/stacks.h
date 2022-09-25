/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:20:07 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/25 12:39:51 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include <dllist.h>

# define INPUT_ERR "invalid argument to function input"

enum e_instruction {
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

typedef struct t_stacks {
	t_dllist	*stack_a;
	t_dllist	*stack_b;
	int			n;
	int			*num;
	int			middleindex;
	int			chunksize;
	int			stacksize;

	t_dllist	*solution;
}	t_stacks;

void	stacks_init(t_stacks *s, int argc);
void	stacks_dispose(t_stacks *s);

void	stacks_sa(t_stacks *s);
void	stacks_sb(t_stacks *s);
void	stacks_ss(t_stacks *s);
void	stacks_pa(t_stacks *s);
void	stacks_pb(t_stacks *s);
void	stacks_ra(t_stacks *s);
void	stacks_rb(t_stacks *s);
void	stacks_rr(t_stacks *s);
void	stacks_rra(t_stacks *s);
void	stacks_rrb(t_stacks *s);
void	stacks_rrr(t_stacks *s);

#endif
