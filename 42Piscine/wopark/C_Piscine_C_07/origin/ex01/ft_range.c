#include <stdlib.h>
int		*ft_range(int min, int max)
{
	int *ret;
	int size;
	int i;

	if ((size = max - min) < 0)
		return (0);
	i = 0;
	if (!(ret = (int *)malloc(sizeof(int) * size)))
		return  (0);
	while (i < size)
		ret[i++] = min++;
	return (ret);
}
