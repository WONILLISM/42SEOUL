#include <stdio.h>
#include <string.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size);
int main()
{
    char str1[100] = "";
    char str2[100] = "asd";

    printf("%s : %lu\n", str2, strlcat(str2, str1, -1));
    //printf("%s : %u\n", str2, ft_strlcat(str2, str1, 1));
    return 0;
}