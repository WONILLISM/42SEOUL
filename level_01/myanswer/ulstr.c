#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;
	char	cur;

	i = 0;
	if (argc == 2)
	{
		while(argv[1][i])
		{
			cur = argv[1][i];
			if (argv[1][i] >= 'A' && 'Z' >= argv[1][i])
				cur += 32;
			if (argv[1][i] >= 'a' && 'z' >= argv[1][i])
				cur -= 32;
			write(1, &cur, 1);
			i += 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}