#include "ft_printf.h"

int		main(void)
{
	// printf("[%#10x]\n", 15);
	// ft_printf("[%#10x]\n", 15);

/*
hex 너비 음수인경우 처리
*/
	printf("-->|%#-4.x|<--\n", 0);
	ft_printf("-->|%#-4.x|<--\n", 0);
	return (0);
}
