/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:32:45 by tohsumi           #+#    #+#             */
/*   Updated: 2022/10/03 12:51:51 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stacks.h>

/* push_swap.c */
void	load_args(t_stacks *s, int argc, char **argv);
void	print_sol(t_stacks *s);

/* sort_three.c */
void	sort_three(t_stacks *s);

/* sort_four.c */
void	sort_four(t_stacks *s);

/* sort_five.c */
void	sort_five(t_stacks *s);

/* sort.c */
void	sort_stacks(t_stacks *s);

/* oprimize.c */
void	sol_optimize(t_stacks *s);

/* a_to_b.c */
void	a_to_b(t_stacks *s);

/* b_to_a.c */
void	b_to_a(t_stacks *s);

#endif
