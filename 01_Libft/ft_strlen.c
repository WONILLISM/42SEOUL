#include "libft.h"

size_t  ft_strlen(const char *s)
{
    const   char    *ptr;

    ptr = s;
    while (*s)
        s++;
    return (ptr - s);
}