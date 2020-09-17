#include <unistd.h>
#include <stdlib.h>

void	do_oper(char **ptr, char *str, int *i)
{
	int stack;

	if (str[*i] == '>')
		*ptr += 1;
	else if (str[*i] == '<')
		*ptr -= 1;
	else if (str[*i] == '+')
		**ptr += 1;
	else if (str[*i] == '-')
		**ptr -= 1;
	else if (str[*i] == '.')
		write(1, *ptr, 1);
	else if (str[*i] == '[' && **ptr == '\0')
	{
		stack = 1;
		while (stack)
		{
			*i += 1;
			if (str[*i] == '[')
				stack++;
			else if(str[*i] == ']')
				stack--;
		}
	}
	else if (str[*i] == ']' && **ptr == '\0')
	{
		stack = 1;
		while (stack)
		{
			*i -= 1;
			if (str[*i] == '[')
				stack--;
			else if(str[*i] == ']')
				stack++;
		}
	}
}
int		ft_brainfuck(char *str)
{
	int		i;
	char	*ptr;

	if (!(ptr = (char *)malloc(sizeof(char) * 2048) + 1))
		return -1;
	i = 0;
	while (i <= 2048)
		ptr[i++] = '\0';
	i = 0;
	while (str[i])
	{
		do_oper(&ptr, str, &i);
		i++;
	}
}

int     main(int argc, char **argv)
{
	char *str;

	if (argc == 2)
	{
		str = argv[1];
		ft_brainfuck(str);
	}
	else
		write(1, "\n", 1);
	return (0);
}