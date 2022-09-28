/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:53:41 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/28 10:58:51 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_stacks	s;

	stacks_init(&s, argc);
	load_args(&s, argc, argv);
	sort_stacks(&s);
	sol_optimize(&s);
	print_sol(&s);
	stacks_dispose(&s);
}
