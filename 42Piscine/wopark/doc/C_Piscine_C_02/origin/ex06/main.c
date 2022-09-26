#include <stdio.h>
int ft_str_is_printable(char *str);

int main(){
    char str[4] = {' ',126};
    printf("%d\n", ft_str_is_printable(str));
    return 0;
}