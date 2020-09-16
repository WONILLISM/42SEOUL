#include <unistd.h>

int		ctoi(char *str)
{
	int ret;

	ret = 0;
	while (*str)
		ret = ret * 10 + (*str++ - '0');
	return ret;
}

void	itoc(int n)
{
	char c;

	if (n > 10)
	{
		c = '0' + n % 10;
		itoc(n / 10);
		write(1, &c, 1);
	}
	else
	{
		c = '0' + n;
		write(1, &c, 1);
	}
}
int		main(int argc, char **argv)
{
	int i;
	int num;
	int len;
	char mul;

	if (argc > 1)
	{
		i = 1;
		len = 0;
		num = ctoi(argv[1]);
		while (argv[1][len])
			len++;
		while (i <= 9)
		{
			mul = '0' + i;
			write(1, &mul, 1);
			write(1, " x ", 3);
			write(1, argv[1], len);
			write(1, " = ", 3);
			itoc(num * i++);
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
