
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_nonprintable(char c)
{
	return (c < ' ' || c == 127);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	cur;
	char			*hex_val;

	hex_val = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		cur = str[i];
		if (is_nonprintable(cur))
		{
			ft_putchar('\\');
			ft_putchar(hex_val[cur / 16]);
			ft_putchar(hex_val[cur % 16]);
		}
		else
			ft_putchar(cur);
		i++;
	}
}
