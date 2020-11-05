#include "ft_printf.h"

int		main(void)
{
	// printf("[%.7x]\n", 2147);
	// ft_printf("[%x]\n", 123u);

	printf("pf[%.p]\n", NULL);
	ft_printf("ft[%.p]\n", NULL);
	// printf("pf[%2.9p]\n", 1234);
	// ft_printf("ft[%2.9p]", 1234);
	return (0);
}

