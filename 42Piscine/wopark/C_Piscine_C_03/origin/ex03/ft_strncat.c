
#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int i;

	i = 0;
	while (dest[i])
		i++;
	while (*src && nb--)
	{
		dest[i] = *src++;
		i++;
	}
	dest[i] = '\0';
	return dest;
}
