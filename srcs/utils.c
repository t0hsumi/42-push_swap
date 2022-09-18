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
