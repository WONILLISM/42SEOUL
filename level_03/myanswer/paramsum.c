#include <unistd.h>

void    ft_put_nbr(int num)
{
    char c;
    if (num > 10)
    {
        ft_put_nbr(num / 10);
        c = '0' + (num % 10);
        write(1, &c, 1);
    }
    else
    {
        c = '0' + num;
        write(1, &c, 1);
    }
}
int     main(int argc, char **argv)
{
    int num;

    num = argc - 1;
    if (argc > 1)
        ft_put_nbr(num);
    write(1, "0\n", 2);
    return (0);
}