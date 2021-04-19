#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int		ft_strlen(char *s);
char	*ft_strcpy(char *dst, char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t nbyte);
ssize_t	ft_read(int fd, const void *buf, size_t nbyte);
char	*ft_strdup(const char *src);

int		main(int argc, char **argv)
{
	char	*src;
	char	*src2;
	char	src3[20];
	char	dst[10];

	/*    ft_strlen    */
	src = "Hello";
	printf("\n***** ft_strlen *****\n");
	printf("[Length of \"Hello\"]: %d\n", ft_strlen(src));
	printf("\n***** strlen *****\n");
	printf("[Length of \"Hello\"]: %lu\n", strlen(src));

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

	if (argc == 2)
	{
		printf("\n***** ft_write *****\n");
		printf("[argv[1]: %s ft_write res:]\n", argv[1]);
		ft_write(1, argv[1], ft_strlen(argv[1]));
		ft_write(1, "\n", 1);

		printf("\n***** write *****\n");
		printf("[argv[1]: %s ft_write res:]\n", argv[1]);
		write(1, argv[1], ft_strlen(argv[1]));
		write(1, "\n", 1);

		printf("\n***** ft_read *****\n");
		printf("[ft_read to src]\n");
		ft_read(0, src3, 20);
		printf("src : %s\n", src3);

		printf("\n***** read *****\n");
		printf("[read to src]\n");
		read(0, src3, 20);
		printf("src : %s\n", src3);
	}

	/*    ft_strcpy    */
	src = "World";
	printf("\n***** ft_strdup *****\n");
	printf("[src: \"World\"] dst: %s \n", ft_strdup(src));
	printf("\n***** strdup *****\n");
	printf("[src: \"World\"] dst: %s \n", strdup(src));

	return (0);
}
