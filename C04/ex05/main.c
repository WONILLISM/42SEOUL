#include <stdio.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size);
int main()
{
    char str1[100] = "abcd";
    char str2[100] = "ABCD";

    ft_strlcat(str2, str1, 1);
    printf("%s\n", str2);
    return 0;
}