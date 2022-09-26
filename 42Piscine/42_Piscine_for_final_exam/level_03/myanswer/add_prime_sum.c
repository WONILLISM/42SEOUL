#include <unistd.h>

int ft_atoi(char *str)
{
	int ret;
	int sign;
	int i;

	ret = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if(str[i++] == '-')
			sign -= 1;
	while (str[i] >= '0' && str[i] <= '9')
		ret = ret * 10 + str[i++] - '0';
	return (ret * sign);
}

int get_prime(int n)
{
	int i;

	i = 2;
	if (n <= 1)
		return (0);
	while (i*i <= n)
	{
		if ((n % i) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr(int n)
{
	char res;

	if (n < 0 )
		write(1, "0", 1);
	else
	{
		if (n < 10)
		{
			res = n + '0';
			write(1, &res, 1);
		}
		else
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
	}
}

int		main(int argc, char **argv)
{
	int num;
	int sum;
	
	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		sum = 0;
		while (num > 0)
			if (get_prime(num--))
				sum += (num + 1);
		ft_putnbr(sum);	
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}