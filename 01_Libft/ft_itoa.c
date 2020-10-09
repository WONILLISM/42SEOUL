#include "libft.h"

static size_t	ft_get_len(int n)
{
	size_t	len;

	len = (n <= 0) ? 1 : 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	size_t		len;
	int			sign;
	char		*ret;
	long int	tmp;

	sign = n < 0 ? -1 : 1;
	len = ft_get_len(n);
	if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ret[len] = 0;
	len--;
	tmp = n < 0 ? -n : n;
	while (len >= 0)
	{
		ret[len] = '0' + tmp % 10;
		tmp /= 10;
		len--;
	}
	if (sign == -1)
		ret[0] = '-';
	return (ret);
}
