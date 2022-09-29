/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:32:45 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/29 12:47:08 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stacks.h>

void	load_args(t_stacks *s, int argc, char **argv);
void	print_sol(t_stacks *s);
void	sort_three(t_stacks *s);
void	sort_four(t_stacks *s);
void	sort_five(t_stacks *s);
void	sort_stacks(t_stacks *s);
void	sol_optimize(t_stacks *s);

void	a_to_b(t_stacks *s);
void	b_to_a(t_stacks *s);
#endif
