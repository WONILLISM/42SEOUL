#include <stdio.h>

unsigned int	gcd(unsigned int a, unsigned int b)
{
	if (a%b == 0)
		return (b);
	return gcd(b, a%b);
}
unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);
	return (a * b / gcd(a, b));
}

int				main(void)
{
	printf("%d\n", lcm(17, 9));
	return (0);
}