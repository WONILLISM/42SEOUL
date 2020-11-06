#include "ft_printf.h"

int		main(void)
{
	printf("-->|%0*.%|<--\n", 2);
	ft_printf("-->|%0*.%|<--\n", 2);

	printf("-->|%0*.*%|<--\n", 2, -4);
	ft_printf("-->|%0*.*%|<--\n", 2, -4);

	printf("-->|%0*.*%|<--\n", 2, 1);
	ft_printf("-->|%0*.*%|<--\n", 2, 1);
	return (0);
}

