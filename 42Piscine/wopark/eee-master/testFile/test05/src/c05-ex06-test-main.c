
	#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>

int		ft_is_prime(int nb);

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
		printf("-5: %d\n", ft_is_prime(-5));
	printf(" 0: %d\n", ft_is_prime(0));
	printf(" 1: %d\n", ft_is_prime(1));
	printf(" 2: %d\n", ft_is_prime(2));
	printf(" 3: %d\n", ft_is_prime(3));
	printf(" 4: %d\n", ft_is_prime(4));
	printf(" 7: %d\n", ft_is_prime(7));
	printf("10: %d\n", ft_is_prime(10));
}
