int     ft_iterative_factorial(int nb)
{
    int i;
    int res;

    if (nb < 0)
        return (0);
    i = 1;
    res = 1;
    while (i <= nb)
        res *=i++;
    return (res);
}