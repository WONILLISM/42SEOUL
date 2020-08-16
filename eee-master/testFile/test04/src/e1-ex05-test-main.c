
	#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>


	;

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
		
	printf("%d ", ft_atoi_base("42", "0123456789"));
	printf("%d ", ft_atoi_base("   42", "0123456789"));
	printf("%d ", ft_atoi_base("  +--++-rcrdmddd+-abc", "mrdoc"));
	printf("%d ", ft_atoi_base("-10000000000000000000000000000000", "01"));
	printf("%d ", ft_atoi_base("8888888888888888888888888888888", "a8"));
	printf("%d ", ft_atoi_base("one", "e"));
	printf("%d ", ft_atoi_base("blank", ""));
	printf("\n");
	}

	
