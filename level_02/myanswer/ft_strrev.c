#include <stdio.h>
#include <string.h>

char* ft_strrev(char *str)
{
    int len;
    int i;
    char tmp;
    char *dest;

    len = 0;
    i = 0;
    while (str[len])
        len++;
    while (i < --len)
    {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
        i++;
    }
    return str;
}

int main()
{
    char str[10] = "Hello";
    printf("%s\n", ft_strrev(str));
    return 0;
}