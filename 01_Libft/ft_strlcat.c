#include "libft.h"

size_t  strlcat(char *dst, const char *src, size_t size)
{
	size_t  dst_len;
	size_t  src_len;
	size_t	i;
	size_t	j;

	j = 0;
	while (j < size && dst[j])
		j++;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	while (i < src_len && dst_len + i + 1 < size)
		dst[dst_len + i] = src[i++];
	dst[dst_len + i] = '\0';
	return (j + src_len);
}