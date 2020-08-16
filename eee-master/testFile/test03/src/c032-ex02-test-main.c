
	#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>


	char	*ft_strcat(char *dest, char *src);

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
	printf("%s\n", strcat(dest, "abc"));
	printf("%s\n", strcat(dest, "123"));
	printf("%s\n", strcat(dest, ""));
	printf("%s\n", strcat(dest, "zz\0zz"));
	printf("\n----------------\nUser Created:\n");
	strncpy(dest, "1", 20);
	printf("%s\n", ft_strcat(dest, "abc"));
	printf("%s\n", ft_strcat(dest, "123"));
	printf("%s\n", ft_strcat(dest, ""));
	printf("%s\n", ft_strcat(dest, "zz\0zz"));
	}

	
