#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
#include <unistd.h>

#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c);

size_t	ft_strlen(const char *s);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);

#endif