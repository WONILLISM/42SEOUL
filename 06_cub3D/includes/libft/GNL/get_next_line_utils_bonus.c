#include "../libft.h"

char	*gnl_strchr(const char *s, int c)
{
	char	*ret;
	ret = 0;
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!c)
		return ((char *)s);
	return (ret);
}

char	*gnl_strndup(const char *src, size_t n)
{
	char	*dest;
	size_t	i;
	if (!(dest = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*ret;

	if (!s1 || !s2)
		return (0);
	len_s1 = gnl_strlen(s1);
	len_s2 = gnl_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (0);
	gnl_memcpy(ret, s1, len_s1);
	gnl_memcpy(ret + len_s1, s2, len_s2);
	ret[len_s1 + len_s2] = 0;
	return (ret);
}

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*gnl_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (dst);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

