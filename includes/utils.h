/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:19:02 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/25 23:21:31 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <stdlib.h>

void	quicksort(int *a, int left, int right);
long	ft_atoi(const char *nptr);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);

#endif
