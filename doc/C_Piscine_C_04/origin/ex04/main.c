
#include <stdio.h>

void ft_putnbr_base(int nbr, char *base);

int main()
{
    // printf("-2147483648\n");
    ft_putnbr_base(-2147483648, "012345678");
    printf("\n");
    return 0;
}
