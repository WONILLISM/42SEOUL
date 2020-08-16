#include <stdio.h>

int ft_atoi_base(char *str, char *base);
int main()
{
    char *str = " ---+--+123456789";
    char *base = "0123456789abcdef";
    printf("%d\n", ft_atoi_base(str, base));
    return 0;
}
