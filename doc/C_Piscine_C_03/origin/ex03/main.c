#include <unistd.h>
#include <stdio.h>
#include <string.h>

char    *ft_strncat(char *dest, char *src, unsigned int nb);

int main()
{
    char str1[100] = "abcde";
    char str2[100] = "ABCDE";
    char *org = "abcde";
    
    printf("%s + %s = %s", org, str2, ft_strncat(str1, str2, 10));
    return 0;
}