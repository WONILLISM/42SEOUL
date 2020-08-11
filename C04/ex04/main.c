#include <stdio.h>
#include <string.h>

char *ft_strstr(char *str, char *find_ptr);
int main()
{
    char str1[] = "He is a smart man";
    char str2[] = "He is";

    // char *ptr1 = strstr(str1, str2);
    // printf("[str1]: %s\n", str1);
    // printf("[ptr1]: %c\n", *ptr1);

    char *ptr2 = ft_strstr(str1, str2);
    printf("[str1]: %s\n", str1);
    printf("[ptr1]: %c\n", *ptr2);
    return 0;
}