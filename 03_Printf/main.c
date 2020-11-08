#include "ft_printf.h"

int		main(void)
{
	char *s = "hi";
	int d = 1234;
	int n, m;
	printf("%s %d%n hello\n%n",s, d, &n, &m);
	printf("n : %d  m : %d\n",n,m);
	ft_printf("%s %d%n hello\n%n",s, d, &n, &m);
	ft_printf("n : %d  m : %d\n",n,m);
	return (0);
}

