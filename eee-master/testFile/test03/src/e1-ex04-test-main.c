
	#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>


	char	*ft_strstr(char *str, char *to_find);

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
			printf("system:\n");
	printf("%s\n", strstr("abcd", "bcd"));
	printf("%s\n", strstr("bbbbaaaa", "a"));
	printf("%s\n", strstr("abcd", "abcdef"));
	printf("%s\n", strstr("abcdbcdbcd", "bcd"));
	printf("%s\n", strstr("none", ""));
	printf("\n----------------\nUser Created:\n");
	printf("%s\n", ft_strstr("abcd", "bcd"));
	printf("%s\n", ft_strstr("bbbbaaaa", "a"));
	printf("%s\n", ft_strstr("abcd", "abcdef"));
	printf("%s\n", ft_strstr("abcdbcdbcd", "bcd"));
	printf("%s\n", ft_strstr("none", ""));
	}

	
