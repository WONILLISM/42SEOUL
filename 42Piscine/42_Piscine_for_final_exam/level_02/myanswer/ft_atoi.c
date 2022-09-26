#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int ft_atoi(char *str)
{
    int i;
    int ret;
    int sign;

    i = 0;
    ret = 0;
    sign = 1;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
        i++;
    if (str[i] == '-' || str[i] == '+')
        if (str[i] == '-')
            sign = -1;
    while (str[i] >= '0' && str[i] <= '9')
        ret = (ret * 10) + (str[i++] - '0');
    return (sign * ret);
}

int main()
{
    char *str1 = "---10";
    printf("%d\n", atoi(str1));
    printf("%d\n", ft_atoi(str1));
}