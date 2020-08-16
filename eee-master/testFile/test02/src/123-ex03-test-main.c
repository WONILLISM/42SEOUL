#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>

	int		ft_str_is_numeric(char *str);

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
		
	printf("%d", ft_str_is_numeric("123"));
	printf("%d", ft_str_is_numeric("a23"));
	printf("%d", ft_str_is_numeric("12z"));
	printf("%d", ft_str_is_numeric(""));
	}

	
