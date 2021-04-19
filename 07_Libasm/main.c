#include <stdio.h>
int		ft_strlen(char *s);
char	*ft_strcpy(char *dst, char *src);
int		ft_strcmp();
int		main()
{
	char	*src;
	char	dst[10];

	src = "Hello";
	printf("***** ft_strlen *****\n[Length of \"Hello\"]: %d\n", ft_strlen(src));
	src = "World";
	printf("***** ft_strcpy *****\n[src: \"World\"] dst: %s \n", ft_strcpy(dst, src));
	return (0);
}
