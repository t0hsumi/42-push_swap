/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opitimze.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:51:03 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/28 12:41:42 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <utils.h>

void	sol_optimize(t_stacks *s)
{
	ra_rb(s);
	rb_ra(s);
	ra_rra(s);
	rra_ra(s);
	rra_rrb(s);
	return ;
}
