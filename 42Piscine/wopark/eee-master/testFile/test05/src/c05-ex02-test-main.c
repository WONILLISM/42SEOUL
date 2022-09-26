
	#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>

int		ft_iterative_power(int nb, int power);

void printmsg(const char *msg, ...)
{
	char *newstr = (char *)malloc(strlen(msg) + 2);
	strcpy(newstr, msg);
	strcat(newstr, "\n");

	va_list args;
	va_start(args, msg);
	vprintf(newstr, args);
	va_end(args);
	// printf("%s\n", msg);
	free(newstr);
}

void printline()
{
	printf("\n------------------------------------------------------------\n");
}

void print_testing(const char *code)
{
	printmsg("\n## testing code :");
	printf("%s", code);
}

int main()
{
	
	printf("%d\n", ft_iterative_power(-3293, -1509));
	printf("%d\n", ft_iterative_power(0, 0));
	printf("%d\n", ft_iterative_power(-371, 0));
	printf("%d\n", ft_iterative_power(1109, 1));
	printf("%d\n", ft_iterative_power(0, 3));
	printf("%d\n", ft_iterative_power(8, 4));
	printf("%d\n", ft_iterative_power(-8, 5));
	printf("%d\n", ft_iterative_power(-5, 6));
	printf("%d\n", ft_iterative_power(-4, 7));
	printf("%d\n", ft_iterative_power(-3, 9));
	printf("%d\n", ft_iterative_power(-2, 10));
}
