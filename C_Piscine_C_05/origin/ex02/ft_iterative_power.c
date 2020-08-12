int ft_iterative_power(int nb, int power)
{
    int ret;

    ret = 1;
    while(power--)
    {
        ret *=nb;
    }
    return ret;
}