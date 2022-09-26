#include <unistd.h>
#include <stdio.h>
char    g_stack[4096];
int     g_top;
void    push(char c)
{
	 g_stack[g_top++] = c;
}

char    pop(char c)
{
	if (g_top == 0)
		return (-1);
	else if (c == ')' && g_stack[g_top - 1] == '(')
		return (g_stack[--g_top]);
	else if (c == '}' && g_stack[g_top - 1] == '{')
		return (g_stack[--g_top]);
	else if (c == ']' && g_stack[g_top - 1] == '[')
		return (g_stack[--g_top]);
	else
		return -1;
}

int ft_brakets(char *str)
{
	while (*str)
	{
		if (*str == '(' || *str == '{' || *str == '[')
			push(*str);
		else if (*str == ')' || *str == '}' || *str == ']')
		{
			if (pop(*str) == -1)
				return (0);
		}
		str++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int i;
	int chk;

	i = 1;
	if (argc >= 2)
	{
		while (i < argc){
			chk = ft_brakets(argv[i]);
			if (g_top == 0 && chk)
				write(1, "OK", 2);
			else
				write(1, "Error", 5);
			i++;
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}