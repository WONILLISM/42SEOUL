int ft_recursive_power(int nb, int power)
{
    if (!power)
        return 1;
    return nb * ft_recursive_power(nb, power - 1);
}