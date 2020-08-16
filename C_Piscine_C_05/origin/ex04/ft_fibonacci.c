int     ft_tail_recursive(int pprev, int prev, int n)
{
    if (n < 0)
        return (-1);
    if (n == 0)
        return pprev;
    if (n == 1)
        return prev;
    return (ft_tail_recursive(prev, (pprev + prev), n - 1));
}
int		ft_fibonacci(int index)
{
    return (ft_tail_recursive(0, 1, index));
}