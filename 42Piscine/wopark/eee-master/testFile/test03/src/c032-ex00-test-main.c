
	#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>


	int		ft_strcmp(char *s1, char *s2);

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
	printf("%d ",strcmp("", "abc"));
	printf("%d ",strcmp("abc", ""));
	printf("%d ",strcmp("abc", "abc"));
	printf("%d ",strcmp("abd", "abe"));
	printf("%d ",strcmp("abc", "abcde"));
	printf("%d ",strcmp("abcde", "abc"));
	printf("\n----------------\nUser Created:\n");
	printf("%d ",ft_strcmp("", "abc"));
	printf("%d ",ft_strcmp("abc", ""));
	printf("%d ",ft_strcmp("abc", "abc"));
	printf("%d ",ft_strcmp("abd", "abe"));
	printf("%d ",ft_strcmp("abc", "abcde"));
	printf("%d ",ft_strcmp("abcde", "abc"));
	}

	
