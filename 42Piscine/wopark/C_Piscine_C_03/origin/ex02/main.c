#include <stdio.h>
#include <string.h>

char    *ft_strcat(char *dest, char *src);

int main()
{
    char str1[10] = "abc";
    char str2[10] = "ABC";
    char *org = "abc";
    printf("%s + %s = %s", org, str2, ft_strcat(str1, str2));
    return 0;
}