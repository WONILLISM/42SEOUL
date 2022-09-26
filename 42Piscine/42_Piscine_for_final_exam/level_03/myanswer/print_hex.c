#include <unistd.h>

int		ctoi(char *s)
{
	int ret;
	int sign;

	sign = 1;
	ret = 0;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s)
	{
		ret = ret * 10 + (*s - '0');
		s++;
	}
	return sign * ret;
}
void	print_hex(int num, char *hex)
{
	if (num > 16)
	{
		print_hex(num / 16, hex);
		write(1, &hex[num % 16], 1);
	}
	else
	{
		write(1, &hex[num], 1);
	}
}
int		main(int argc, char **argv)
{
	char	*hex;
	int		dec;
	
	hex = "0123456789abcdef";
	if (argc == 2)
	{
		dec = ctoi(argv[1]);
		print_hex(dec, hex);
	}
	write(1, "\n", 1);
	return (0);
}
