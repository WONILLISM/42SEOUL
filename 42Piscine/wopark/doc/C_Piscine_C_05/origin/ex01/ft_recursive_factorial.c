int	ft_tail_recursive(int fac, int number)
{
	fac *= number--;
	if (number > 0)
		return (ft_tail_recursive(fac, number));
	return (fac);
}

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (ft_tail_recursive(1, nb));
}