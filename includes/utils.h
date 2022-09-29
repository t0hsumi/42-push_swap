/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:19:02 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/29 12:52:41 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef UTILS_H
# define UTILS_H

# include <stacks.h>
# include <stddef.h>
# include <stdlib.h>

void	quicksort(int *a, int left, int right);
long	ft_atoi(const char *nptr);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
size_t	find_elem_location(t_stacks *s, int index);

void	ra_rb(t_stacks *s);
void	rb_ra(t_stacks *s);

void	rra_rrb(t_stacks *s);

void	rra_ra(t_stacks *s);
void	ra_rra(t_stacks *s);
#endif
