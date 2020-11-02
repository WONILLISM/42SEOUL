#include "ft_printf.h"

int		main(void)
{
	int d = 12;

	printf("-->|%0*.d|<--\n", 4, d);
	ft_printf("-->|%0*.d|<--\n", 4, d);

	printf("-->|%0*.0d|<--\n", 4, d);
	ft_printf("-->|%0*.0d|<--\n", 4, d);

	printf("-->|%0*.1d|<--\n", 4, d);
	ft_printf("-->|%0*.1d|<--\n", 4, d);


	printf("-->|%0*.*d|<--\n", 4, -4, d);
	ft_printf("-->|%0*.*d|<--\n", 4, -4, d);
	// printf("[%.*d]\n",-1, 0);
	// ft_printf("[%.*d]\n",-1, 0);

	// printf("[%.-1d]\n", 0);
	// ft_printf("[%.-1d]\n", 0);
	// printf("this %%.0d number, 0\n");
	// printf("this [%.0d] number\n", 0);
	// ft_printf("this [%.0d] number\n\n", 0);

	// printf("[%%.d], 0\n");
	// printf("[%.d]\n", 0);
	// ft_printf("[%.d]\n\n", 0);

	// printf("[%%5.0d], 0\n");
	// printf("[%5.0d]\n", 0);
	// ft_printf("[%5.0d]\n\n", 0);

	// printf("[%%5.d], 0\n");
	// printf("[%5.d]\n", 0);
	// ft_printf("[%5.d]\n\n", 0);

	// printf("[%%-5.0d], 0\n");
	// printf("[%-5.0d]\n", 0);
	// ft_printf("[%-5.0d]\n\n", 0);

	// printf("[%%-5.d], 0\n");
	// printf("[%-5.d]\n", 0);
	// ft_printf("[%-5.d]\n\n", 0);
	return (0);
}
