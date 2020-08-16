#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>

	unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size);

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
			char o[20];
	printf("returned - %lu, string - %s \n", strlcpy(o, "abcdef", 10L), o);
	printf("returned - %lu, string - %s \n", strlcpy(o, "123456", 6L), o);
	printf("returned - %lu, string - %s \n", strlcpy(o, "abcdef", 7L), o);
	printf("returned - %lu, string - %s \n", strlcpy(o, "123456", 3L), o);
	printf("returned - %lu, string - %s \n", strlcpy(o, "abcef", 0L), o);
	printf("-------------------\n");
	printf("returned - %u, string - %s \n", ft_strlcpy(o, "abcdef", 10L), o);
	printf("returned - %u, string - %s \n", ft_strlcpy(o, "123456", 6L), o);
	printf("returned - %u, string - %s \n", ft_strlcpy(o, "abcdef", 7L), o);
	printf("returned - %u, string - %s \n", ft_strlcpy(o, "123456", 3L), o);
	printf("returned - %u, string - %s \n", ft_strlcpy(o, "abcef", 0L), o);
	}

	
