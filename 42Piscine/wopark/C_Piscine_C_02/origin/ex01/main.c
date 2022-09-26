
#include	<stdio.h>
#include	<string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int		main(void)
{
	char *str = "Hello World!";
	char dest[100];
	unsigned int n = 4;
	printf("return: %s\n", ft_strncpy(dest, str, n));
	printf("origin: %s -> destination: %s\n", str, dest);
	printf("origin: %s -> destination: %s\n", str, strncpy(dest, str, n));
	return (0);
}
