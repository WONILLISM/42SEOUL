#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2);

int main()
{
    char *str1 = "123467";
    char *str2 = "1236";

    printf("%s vs %s : %d\n", str1, str2, strcmp(str1, str2));
    printf("%s vs %s : %d\n", str1, str2, ft_strcmp(str1, str2));    
    return 0;
}
