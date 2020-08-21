#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, unsigned int n);

int main()
{
    char *str1 = "123467";
    char *str2 = "1234";

    printf("%s vs %s : %d\n", str1, str2, strncmp(str1, str2, 3));
    printf("%s vs %s : %d\n", str1, str2, ft_strncmp(str1, str2, 3));   
    
    return 0;
}