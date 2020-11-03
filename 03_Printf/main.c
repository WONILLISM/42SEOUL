#include "ft_printf.h"

int		main(void)
{
	int d = -12;

	printf("-->|%0*.0d|<--\n", 4, d);
	ft_printf("-->|%0*.0d|<--\n", 4, d);
	printf("[%.*d]\n",-1, 0);
	ft_printf("[%.*d]\n",-1, 0);
	return (0);
}
