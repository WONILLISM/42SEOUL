#include "ft_printf.h"

int		main(void)
{
	// printf("[%.7x]\n", 2147);
	// ft_printf("[%x]\n", 123u);
	printf("[%s]\n", ft_itoa_base(255, "0123456789abcdef"));
	return (0);
}

