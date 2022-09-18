#include <utils.h>

void *ft_memcpy(void *dest, const void *src, size_t n) {
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

void print_sol(stacks_t *s) {
	dlnode_t *cur = s->solution->dummy->next;
	char *inst[11] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
	while (cur != s->solution->dummy) {
		enum instruction tmp = *(enum instruction *)cur->data;
		write(1, inst[tmp], ft_strlen(inst[tmp]));
		cur = cur->next;
	}
}

