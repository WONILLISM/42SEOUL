
#include	<stdio.h>

int		ft_str_is_alpha(char *str);

int		main(void)
{
	char *str1 = "Hello World!";
	char *str2 = "Hello";
	char *str3 = "1234";
	char *str4 = "";
	printf("if include nonalpha '0' else '1'\n");
	printf("str1(%s): %d\n", str1, ft_str_is_alpha(str1));
	printf("str3(%s): %d\n", str2, ft_str_is_alpha(str2));
	printf("str2(%s): %d\n", str3, ft_str_is_alpha(str3));
	printf("str4(%s): %d\n", str4, ft_str_is_alpha(str4));
	return (0);
}
