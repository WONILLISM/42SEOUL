#include "ft_printf.h"

int		main(void)
{
	printf("   printf -> [%.4s]\n", "hello");
	ft_printf("ft_printf -> [%.4s]\n", "hello");
	return (0);
}
