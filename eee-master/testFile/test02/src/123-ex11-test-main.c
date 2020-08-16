#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>

	void	ft_putstr_non_printable(char *str);

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
			char o[100] = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(o);
	char all_character[256];
	for(int i = 0;i<255;i++)
		all_character[i] = (char)(i + 1);
	all_character[255] = '\0';
	ft_putstr_non_printable(all_character);
	}

	
