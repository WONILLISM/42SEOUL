
	#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>


	unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

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
	strcpy(dest, "a");
	printf("system:\n");
	printf("%lu %s\n", strlcat(dest, "power", 4), dest);
	printf("%lu %s\n", strlcat(dest, "po", 100), dest);
	printf("%lu %s\n", strlcat(dest, "ma", 2), dest);
	printf("%lu %s\n", strlcat(dest, "naver", 20), dest);
	printf("%lu %s\n", strlcat(dest, "zero", 0), dest);
	printf("\n----------------\nUser Created:\n");
	strncpy(dest, "a", 70);
	printf("%u %s\n", ft_strlcat(dest, "power", 4), dest);
	printf("%u %s\n", ft_strlcat(dest, "po", 100), dest);
	printf("%u %s\n", ft_strlcat(dest, "ma", 2), dest);
	printf("%u %s\n", ft_strlcat(dest, "naver", 20), dest);
	printf("%u %s\n", ft_strlcat(dest, "zero", 0), dest);
	}

	
