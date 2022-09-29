/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:43:26 by tohsumi           #+#    #+#             */
/*   Updated: 2022/09/29 12:52:49 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
	ft_memcpy(ptr, s1, ft_strlen(s1) + 1);
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
