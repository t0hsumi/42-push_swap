/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 23:03:43 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/25 23:03:45 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quicksort(int *a, int left, int right)
{
	int	pivot_index;
	int	pivot;
	int	i;
	int	j;

	if (right - left <= 1)
		return ;
	pivot_index = (left + right) / 2;
	pivot = a[pivot_index];
	swap(&a[pivot_index], &a[right - 1]);
	i = left;
	j = left;
	while (j < right - 1)
	{
		if (a[j] < pivot)
			swap(&a[i++], &a[j]);
		j++;
	}
	swap(&a[i], &a[right - 1]);
	quicksort(a, left, i);
	quicksort(a, i + 1, right);
}
