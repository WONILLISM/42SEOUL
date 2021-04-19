#include <stdio.h>
#include <string.h>

int		ft_strlen(char *s);
char	*ft_strcpy(char *dst, char *src);
int		ft_strcmp(const char *s1, const char *s2);

int		main()
{
	char	*src;
	char	*src2;
	char	dst[10];

	/*    ft_strlen    */
	src = "Hello";
	printf("\n***** ft_strlen *****\n");
	printf("[Length of \"Hello\"]: %d\n", ft_strlen(src));
	printf("\n***** strlen *****\n");
	printf("[Length of \"Hello\"]: %d\n", strlen(src));

	/*    ft_strcpy    */
	src = "World";
	printf("\n***** ft_strcpy *****\n");
	printf("[src: \"World\"] dst: %s \n", ft_strcpy(dst, src));
	printf("\n***** strcpy *****\n");
	printf("[src: \"World\"] dst: %s \n", strcpy(dst, src));

	/*    ft_strcmp    */
	src = "Hello";
	src2 = "Hello";
	printf("\n***** ft_strcmp equal*****\n");
	printf("[src: \"Hello\" src2: \"Hello\"] : ");
	if (ft_strcmp(src, src2))
		printf("not equal\n");
	else
		printf("equal\n");
	printf("\n***** strcmp equal*****\n");
	printf("[src: \"Hello\" src2: \"Hello\"] : ");
	if (strcmp(src, src2))
		printf("not equal\n");
	else
		printf("equal\n");

	src = "Hello";
	src2 = "World";
	printf("\n***** ft_strcmp not equal*****\n");
	printf("[src: \"Hello\" src2: \"World\"] : ");
	if (ft_strcmp(src, src2))
		printf("not equal\n");
	else
		printf("equal\n");
	printf("\n***** strcmp not equal*****\n");
	printf("[src: \"Hello\" src2: \"World\"] : ");
	if (strcmp(src, src2))
		printf("not equal\n");
	else
		printf("equal\n");

	return (0);
}
