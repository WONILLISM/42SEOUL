#include "ft_printf.h"

int		main(void)
{
	int a, b;

	printf("printf\n");
	a = printf("hello, %s.\n", "gavin");
	printf("return : %d\n", a);

	printf("\nft_printf\n");
	b = ft_printf("hello, %s.\n", "gavin");
	printf("return : %d\n", b);
	return (0);
}

