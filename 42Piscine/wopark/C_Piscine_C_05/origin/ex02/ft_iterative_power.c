int ft_iterative_power(int nb, int power)
{
    int ret;

    if (power < 0)
		return (0);
    ret = 1;
    while(power--)
        ret *=nb;
    return (ret);
}