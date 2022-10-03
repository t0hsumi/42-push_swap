/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:34:48 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/30 18:30:33 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdlib.h>
#include <utils.h>
#include <limits.h>

static int	is_duplicates(int *num, int nelms)
{
	int	i;

	i = 0;
	while (i < nelms - 1)
	{
		if (num[i] == num[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	load_args(t_stacks *s, int argc, char **argv)
{
	int		i;
	int		tmp;
	long	arg_num;

	i = 0;
	while (++i < argc)
	{
		arg_num = ft_atoi(argv[i]);
		if (arg_num == LONG_MIN)
		{
			write(2, "Error\n", 6);
			stacks_dispose(s);
			exit(EXIT_FAILURE);
		}
		tmp = (int)arg_num;
		dllist_addlast(s->stack_a, &tmp);
		s->num[i - 1] = tmp;
	}
	quicksort(s->num, 0, argc - 1);
	if (is_duplicates(s->num, argc - 1))
	{
		write(2, "Error\n", 6);
		stacks_dispose(s);
		exit(EXIT_FAILURE);
	}
}

static void	inst_init(char **inst)
{
	inst[0] = ft_strdup("sa\n");
	inst[1] = ft_strdup("sb\n");
	inst[2] = ft_strdup("ss\n");
	inst[3] = ft_strdup("pa\n");
	inst[4] = ft_strdup("pb\n");
	inst[5] = ft_strdup("ra\n");
	inst[6] = ft_strdup("rb\n");
	inst[7] = ft_strdup("rr\n");
	inst[8] = ft_strdup("rra\n");
	inst[9] = ft_strdup("rrb\n");
	inst[10] = ft_strdup("rrr\n");
}

static void	inst_dispose(char **inst)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		free(inst[i]);
		inst[i++] = NULL;
	}
}

void	print_sol(t_stacks *s)
{
	t_dlnode			*cur;
	enum e_instruction	tmp;
	char				**inst;

	cur = s->solution->dummy->next;
	inst = (char **)malloc(sizeof(char *) * 11);
	if (!inst)
		exit(EXIT_FAILURE);
	inst_init(inst);
	while (cur->data != NULL)
	{
		tmp = *(enum e_instruction *)cur->data;
		write(1, inst[tmp], ft_strlen(inst[tmp]));
		cur = cur->next;
	}
	inst_dispose(inst);
	free(inst);
	inst = NULL;
}
