
	#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>

int		ft_find_next_prime(int nb);

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
		printf("%d\n", ft_find_next_prime(-2));
	printf("%d\n", ft_find_next_prime(24));
	printf("%d\n", ft_find_next_prime(29));
	printf("%d\n", ft_find_next_prime(2147483629));
	printf("%d\n", ft_find_next_prime(2147483630));
	
}
