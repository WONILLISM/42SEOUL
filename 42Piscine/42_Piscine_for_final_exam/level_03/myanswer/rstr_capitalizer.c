#include <unistd.h>

int		is_white_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int		is_upper_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return -1;
	if (c >= 'A' && c <= 'Z')
		return 1;
	else return 0;
}

void	rstr_capitalizer(char *str)
{
	while (*str)
	{
		if (is_upper_lower(*str) == 1)
			*str = *str - 'A' + 'a';
		if (is_upper_lower(*str) == -1 && (is_white_space(*(str + 1)) || !*(str + 1)))
			*str = *str - 'a' + 'A';
		write(1, str++, 1);
	}
}
int		main(int argc, char **argv)
{
	int i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			rstr_capitalizer(argv[i++]);
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
