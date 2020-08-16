#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>

	char		*ft_strupcase(char *str);

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
			char c[100] = "abDc";
	printf("%s\n", ft_strupcase(c));
	strcpy(c, "aI");
	printf("%s\n", ft_strupcase(c));
	strcpy(c, "0fN99");
	printf("%s\n", ft_strupcase(c));
	strcpy(c, "");
	printf("%s\n", ft_strupcase(c));
	}

	
