
	#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>


	char				*ft_strncat(char *dest, char *src, unsigned int nb);

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
			char dest[100];
	printf("system:\n");
	strcpy(dest, "1");
	printf("%s\n", strncat(dest, "12", 2));
	printf("%s\n", strncat(dest, "abcd", 2));
	printf("%s\n", strncat(dest, "zz", 5));
	printf("%s\n", strncat(dest, "oo", 3));
	printf("%s\n", strncat(dest, "null?\0null!", 11));
	printf("%s\n", strncat(dest, "zero", 0));
	printf("\n----------------\nUser Created:\n");
	strncpy(dest, "1", 20);
	printf("%s\n", ft_strncat(dest, "12", 2));
	printf("%s\n", ft_strncat(dest, "abcd", 2));
	printf("%s\n", ft_strncat(dest, "zz", 5));
	printf("%s\n", ft_strncat(dest, "oo", 3));
	printf("%s\n", ft_strncat(dest, "null?\0null!", 11));
	printf("%s\n", ft_strncat(dest, "zero", 0));
	}

	
