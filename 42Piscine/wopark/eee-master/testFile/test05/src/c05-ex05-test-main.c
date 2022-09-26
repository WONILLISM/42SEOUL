
	#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>

int		ft_sqrt(int nb);

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
	
	printf("%d\n", ft_sqrt(-2));
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(1));
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(6));
	printf("%d\n", ft_sqrt(9));
	printf("%d\n", ft_sqrt(15));
	printf("%d\n", ft_sqrt(16));
	printf("%d\n", ft_sqrt(17));
}
