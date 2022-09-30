/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:57:15 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/29 12:44:16 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stacks.h>

void	stacks_init(t_stacks *s, int argc)
{
	if ((void *)s == NULL)
		exit(EXIT_FAILURE);
	s->stack_a = malloc(sizeof(t_dllist));
	s->stack_b = malloc(sizeof(t_dllist));
	s->solution = malloc(sizeof(t_dllist));
	if (!s->stack_a || !s->stack_b || !s->solution)
		exit(EXIT_FAILURE);
	dllist_init(s->stack_a, sizeof(int));
	dllist_init(s->stack_b, sizeof(int));
	dllist_init(s->solution, sizeof(enum e_instruction));
	s->num = (int *)malloc(sizeof(int) * (argc - 1));
	if (s->num == NULL)
		exit(EXIT_FAILURE);
	if (argc - 1 <= 10)
		s->n = 5;
	else if (argc - 1 <= 150)
		s->n = 8;
	else
		s->n = 18;
	s->middleindex = (argc - 1) / 2;
	s->chunksize = (argc - 1) / s->n;
	s->stacksize = argc - 1;
}

void	stacks_dispose(t_stacks *s)
{
	dllist_dispose(s->stack_a);
	dllist_dispose(s->stack_b);
	dllist_dispose(s->solution);
	free(s->stack_a);
	s->stack_a = NULL;
	free(s->stack_b);
	s->stack_b = NULL;
	free(s->solution);
	s->solution = NULL;
	free(s->num);
	s->num = NULL;
}
