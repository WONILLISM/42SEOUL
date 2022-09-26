#include <unistd.h>
#include <stdio.h>

int		is_nonprintable(char c)
{
	return (c < ' ' || c == 127);
}
void	print_memory(const void *addr, size_t size)
{
	unsigned char   *p;
	unsigned char	*cur;
	char            *hex;
	size_t			i;
	size_t			j;
	hex = "0123456789abcdef";
	p = (char *)addr;
	i = 0;
	while (i < size)
	{
		cur = &p[i];
		j = 0;
		while (j < (sizeof(int)) * 4)
		{
			if (i + j < size)
			{
				write(1, &hex[((*cur) / 16) % 16], 1);
				write(1, &hex[(*cur) % 16], 1);
				if (j%2==1)
					write(1, " ", 1);
				cur++;
			}
			else
			{
				write(1, "  ", 2);
				if (j % 2 == 1)
					write(1, " ", 1);
			}
			j++;
		}
		cur = &p[i];
		j = 0;
		while (j < (sizeof(int)) * 4 && i + j < size)
		{
			if (!is_nonprintable(*(cur + j)))
				write(1, (cur+j), 1);
			else
				write(1, ".", 1);
			j++;
		}
		write(1, "\n", 1);
		i += j;
	}
}

int     main(void)
{
	int	tab[10] = {0x7fffffff, 23, 150, 255, 12, 16,  21, 42};
	// int	tab[10] = {65, 66, 67, 68, 69, 70,  71, 72};
	// int	tab[10] = {16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
	print_memory(tab, sizeof(tab));
	return (0);
}