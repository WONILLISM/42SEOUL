#include <stdlib.h>

char    *ft_strdup(char *src)
{
    char    *dest;
    int     len;
    int     i;

    len = 0;
    i = 0;
    while (src[len])
        len++;
    if (!(dest = (char *)malloc(sizeof(char) * len)))
        return (0);
    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
