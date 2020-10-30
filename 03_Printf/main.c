#include "ft_printf.h"

int		main(void)
{
	// printf("   printf : [%.5d]\n", -3);
	printf("   printf : [%*.-5d]\n", 10,-123);
	// ft_printf("ft_printf : [%+5d]\n", -123);
	return (0);
}
