#include <utils.h>
#include <limits.h>

static int ft_isdigit(int c) {
	return ('0' <= c && c <= '9');
}

long    ft_atoi(const char *nptr)
{
	long int res;
	int sign;
	int i;

	res = 0;
	sign = 1;
	i = 0;
	if (nptr[i] == '+' || nptr[i] == '-') {
		if (nptr[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit(nptr[i])) {
		res = res*10 + (int)(nptr[i] - '0');
		if (INT_MAX + 1L < res)
			return LONG_MIN;
		i++;
	}
	res *= sign;
	if (res < INT_MIN || INT_MAX < res || nptr[i] != 0 || i == 0)
		return LONG_MIN;
	else
		return (res);
}
