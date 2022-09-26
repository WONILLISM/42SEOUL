
	#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>


	void	ft_putnbr_base(int nbr, char *base);

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
		
	ft_putnbr_base(40, "0123456789abcdef");
	printf("\n");
	ft_putnbr_base(31, "0123456789abcdef");
	printf("\n");
	ft_putnbr_base(15, "01");
	printf("\n");
	ft_putnbr_base(-15, "0123456789");
	printf("\n");
	ft_putnbr_base(-16, "01");
	printf("\n");
	ft_putnbr_base(2147483647, "0123456789abcdef");
	printf("\n");
	ft_putnbr_base(-2147483648, "0123456789abcdef");
	}

	
