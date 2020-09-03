#include <stdio.h>

int     max(int* tab, unsigned int len)
{
	int max_value;
	int i;

	max_value = 1<<31;
	i = 0;
	if (!len)
		return (0);
	while (i < len)
	{
		max_value = max_value > tab[i]? max_value : tab[i];
		i++;
	}
	return max_value;
}
int main(){
	int arr[4] = {3,2,1,5};

	printf("%d", max(arr, 4));
	return 0;
}