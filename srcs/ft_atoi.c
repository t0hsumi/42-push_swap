#include <utils.h>
#include <limits.h>


static int	is_plus_ok(const char *nptr, long int num, int i)
{
	long int	ov_div;

	ov_div = LONG_MAX / 10;
	if (num > ov_div && '0' <= nptr[i] && nptr[i] <= '9')
		return (0);
	else if (num == ov_div && '8' <= nptr[i] && nptr[i] <= '9')
		return (0);
	else
		return (1);
}

static int	is_minus_ok(const char *nptr, long int num, int i)
{
	long int	ov_div;

	ov_div = LONG_MAX / 10;
	if (num > ov_div && '0' <= nptr[i] && nptr[i] <= '9')
		return (0);
	else if (num == ov_div && nptr[i] == '9')
		return (0);
	else
		return (1);
}

long	ft_atoi(const char *nptr)
{
	long int	num;
	int			sign;
	size_t		i;

	num = 0;
	i = 0;
	sign = 1;
	while (('\t' <= nptr[i] && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			sign = -1;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		num = 10 * num + (nptr[i++] - '0');
		if (sign == 1)
			if (!is_plus_ok(nptr, num, i))
				return (LONG_MIN);
		if (sign == -1)
			if (!is_minus_ok(nptr, num, i))
				return (LONG_MIN);
	}
	return (sign * num);
}
