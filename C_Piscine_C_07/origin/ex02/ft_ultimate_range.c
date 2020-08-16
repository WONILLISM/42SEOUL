#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int size;
	int *buf;
	int i;

	if ((size = max - min) < 0)
		return (0);
	if (!(buf = malloc(sizeof(int) * size)))
		return (0);
	i = 0;
	while (min < max)
		*range[i++] = min++;
	return (i);
}
