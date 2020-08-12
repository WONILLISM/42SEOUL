#include <stdio.h>

int ft_atoi_base(char *str, char *base);
int main()
{
    char *str = " ---+--+1234ab567";
    char *base = "cde";
    printf("%d\n", ft_atoi_base(str, base));
    return 0;
}