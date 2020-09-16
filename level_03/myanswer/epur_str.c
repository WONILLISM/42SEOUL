#include <unistd.h>

int		is_white_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}
int     main(int argc, char **argv)
{
	int i;

	if (argc == 2)
	{
		i = 0;
		while (is_white_space(argv[1][i]))
			i++;
		while (argv[1][i])
		{
			if (argv[1][i] == ' ')
			{
				while (is_white_space(argv[1][i]))
					i++;
				if (argv[1][i])
					write(1, " ", 1);
			}
			else
			{
				write(1, &argv[1][i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}