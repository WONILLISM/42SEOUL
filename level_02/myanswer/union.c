#include <unistd.h>

void ft_union(int *chk, char *str)
{
	while (*str)
	{
		if (!chk[*str])
			write(1, str, 1);
		chk[*str]++;
		str++;
	}
}
int main(int argc, char **argv)
{
	int check[128] = {0, };

	if (argc == 3)
	{
		ft_union(check, argv[1]);
		ft_union(check, argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}