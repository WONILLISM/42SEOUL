#include "ft_printf.h"

int		main(void)
{
	printf("-->|%0*.*x|<--\n", -4, -4, 0);
	ft_printf("-->|%0*.*x|<--\n", -4, -4, 0);

	printf("-->|%0*.*x|<--\n", 6, -4, 0);
	ft_printf("-->|%0*.*x|<--\n", 6, -4, 0);
	return (0);
}
