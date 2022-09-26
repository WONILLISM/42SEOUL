#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
	if (a % b == 0)
		return (b);
	return (gcd(b, a % b));
}
int main(int argc, char **argv)
{
	int a;
	int b;

	if (argc == 3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		if (a == 0 || b == 0)
		{
			printf("\n");
			return (0);
		}
		printf("%d", gcd(a, b));
	}
	printf("\n");
	return (0);
}
