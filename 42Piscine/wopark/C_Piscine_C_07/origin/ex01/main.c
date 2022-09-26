#include <stdio.h>

int		*ft_range(int min, int max);
int main()
{
	int *arr;
	int a = 1;
	int b = 3;

	arr = ft_range(a,b);
	for(int i = 0; i < b-a; i++)
		printf("%d",arr[i]);
	return 0;
}
