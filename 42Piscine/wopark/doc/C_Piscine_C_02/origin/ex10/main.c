#include <stdio.h>
#include <string.h>
unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size);
int main(){
    char dest[100];
    printf("ft_strlcpy : %s  %u\n", dest, ft_strlcpy(dest, "123456",10));
    printf("strlcpy : %s  %lu\n", dest, strlcpy(dest, "123456",10));
    return 0;
}