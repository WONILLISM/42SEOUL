#include "ft_printf.h"

int		main(void)
{
	// - 0 . *

	printf("	printf : [%-*.5d]\n",2, -123);
	// printf("	printf : [%.5d]\n", -123);
	// ft_printf("	ft_printf : [%.5d]\n", -123);
	// printf("	printf : [%.05d]\n", -123);
	// ft_printf("	ft_printf : [%.05d]\n", -123);

	// printf("	printf : [%-.7d]\n", -123);
	// ft_printf("	ft_printf : [%5d]\n", -123);
	// printf("	printf : [%07d]\n", -123);
	// ft_printf("	ft_printf : [%05d]\n", -123);
	return (0);
}
