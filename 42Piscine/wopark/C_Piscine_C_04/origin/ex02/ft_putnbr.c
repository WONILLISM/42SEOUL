#	include <unistd.h>
#	define MIN_INT -2147483648

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (nb == MIN_INT)
		{
			ft_putnbr(nb / 10);
			ft_putchar('8');
		}
		else
		{
			ft_putchar('-');
			ft_putnbr(-nb);
		}
	}
	else
	{
		if (nb > 9)
			ft_putnbr(nb / 10);
		ft_putchar('0' + nb % 10);
	}
}