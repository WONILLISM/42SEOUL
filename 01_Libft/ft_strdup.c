#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s);
	if (!(dup = (char *)malloc(sizeof(char) * len + 1)))
		return ((char *)0);
	ft_strlcpy(dup, s, len + 1);
	return dup;
}