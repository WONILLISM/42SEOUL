
	#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>


	int	ft_strncmp(char *s1, char *s2, unsigned int n);

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
	printf("%d ",strncmp("", "abc", 1));
	printf("%d ",strncmp("abc", "de", 0));
	printf("%d ",strncmp("abc", "abc", 5));
	printf("%d ",strncmp("abd", "abe", 2));
	printf("%d ",strncmp("abcde", "abc", 5));
	printf("%d ",strncmp("abcde", "abc", 3));
	printf("\n----------------\nUser Created:\n");
	printf("%d ",ft_strncmp("", "abc", 1));
	printf("%d ",ft_strncmp("abc", "de", 0));
	printf("%d ",ft_strncmp("abc", "abc", 5));
	printf("%d ",ft_strncmp("abd", "abe", 2));
	printf("%d ",ft_strncmp("abcde", "abc", 5));
	printf("%d ",ft_strncmp("abcde", "abc", 3));
	printf("\n");
	}

	
