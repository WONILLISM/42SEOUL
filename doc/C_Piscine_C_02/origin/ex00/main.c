
#include	<stdio.h>

char	*ft_strcpy(char *dest, char *src);

int		main(void)
{
	char *str = "Hello World!";
	char dest[100];
	
	printf("return: %s\n", ft_strcpy(dest, str));
	printf("origin: %s -> destination: %s\n", str, dest);
	return (0);
}
