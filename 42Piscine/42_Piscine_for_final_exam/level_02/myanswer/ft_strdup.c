#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_strdup(char *src)
{
    int i;
    int len;
    char *dest;

    i = -1;
    len = 0;
    while (src[len])
        len++;
    dest = (char *)malloc(sizeof(char) * len + 1);
    if (!src || !dest)
        return (NULL);
    i = -1;
    while (src[++i])
    {
        //printf("%c", src[i]);
        dest[i] = src[i];
    }
    // printf("\n");
    // i = 0;
    // while (src[i])
    // {
    //     printf("%c", src[i]);
    //     dest[i] = src[i++];
    // }
    // printf("\n");
    return dest;
}

int main()
{
    char *str = "Hello World!";
    char *dest;
    dest = strdup(str);
    printf("arr: %p  val: %s\n", dest, dest);
    dest = ft_strdup(str);
    printf("arr: %p  val: %s\n", dest, dest);
    return 0;
}