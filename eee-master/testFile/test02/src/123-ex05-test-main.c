#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>

	int		ft_str_is_uppercase(char *str);

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
			printf("%d", ft_str_is_uppercase("ABC"));
	printf("%d", ft_str_is_uppercase("aCI"));
	printf("%d", ft_str_is_uppercase("Cat"));
	printf("%d", ft_str_is_uppercase(""));
	}

	
