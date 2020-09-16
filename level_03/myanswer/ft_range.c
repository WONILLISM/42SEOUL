#include <stdio.h>
#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int *ret;
	int size;
	int acc;
	int i;

	size = start > end ? (start - end + 1) : (end - start + 1);
	acc = start > end ? -1 : 1;
	i = 0;
	if(!(ret = (int *)malloc(sizeof(int) * size)))
		return (0);
	while (i < size)
	{
		ret[i++] = start;
		start += acc;
	}
	return (ret);
}

int		main(void)
{
	int *arr;
	// int s = 1, e = 3;
	// int s = -1, e = 2;
	// int s = 0, e = 0;
	int s = 0, e = -3;

	int size = s > e ? (s - e + 1) : (e - s + 1);
	arr = ft_range(s, e);
	for (int i = 0; i<size; i++)
		printf("%d ", arr[i]);
	return (0);
}