#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
	char	*ret;
	char	*str;
	int 	n;
	int		len;

	if (nbr == -2147483648)
		return ("-2147483648");
	len = 0;
	n = nbr;
	while (n)
	{
		n /= 10;
		len++;
	}
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
		return (char *)0;
	ret[len--] = '\0';
	while (nbr)
	{
		ret[len--] = '0' + (nbr % 10);
		nbr /= 10;
		
	}
	return (ret);
}
int		main(void)
{
	ft_itoa(199);
	return (0);
}