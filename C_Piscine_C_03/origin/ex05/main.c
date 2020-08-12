#include <stdio.h>
#include <string.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size);
int main()
{
    char str1[100] = "abcd";
    char str2[100] = "ABCD";

    printf("%lu\n", strlcat(str2, str1, 1));
    printf("%u\n", ft_strlcat(str2, str1, 1));
    return 0;
}