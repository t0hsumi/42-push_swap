/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:43:26 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/29 13:20:03 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <utils.h>

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*usdst;
	unsigned char	*ussrc;

	usdst = (unsigned char *)dest;
	ussrc = (unsigned char *)src;
	if (dest == src)
		return (dest);
	while (n)
	{
		*usdst = *ussrc;
		usdst++;
		ussrc++;
		n--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	u_int8_t	*from;
	u_int8_t	*to;
	int			i;
	size_t		j;

	from = (u_int8_t *)src;
	to = (u_int8_t *)dest;
	if (from == to || n == 0)
		return (dest);
	if (to > from && to - from < (int)n)
	{
		i = n;
		while (--i >= 0)
			to[i] = from[i];
	}
	else if (from > to && from - to < (int)n)
	{
		j = -1;
		while (++j < n)
			to[j] = from[j];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ptr)
		return (NULL);
	ft_memmove(ptr, s1, ft_strlen(s1) + 1);
	return (ptr);
}

size_t	find_elem_location(t_stacks *s, int index)
{
	t_dlnode	*cur;
	size_t		res;

	res = 0;
	cur = s->stack_b->dummy->next;
	while (cur->data != NULL)
	{
		if (*(int *)cur->data == s->num[index])
			break ;
		res++;
		cur = cur->next;
	}
	return (res);
}
