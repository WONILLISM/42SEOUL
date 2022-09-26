#include <stdio.h>

int ft_atoi(char *str);
int main()
{
    char *str = " ---+--+12-+34ab567";
    printf("%d\n", ft_atoi(str));
    return 0;
}
