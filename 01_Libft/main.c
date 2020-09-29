#include "libft.h"

void chk_strlen(){
	printf("strlen\n");
	char *s = "Hello";
	printf("strlen : %d ft_strlen : %d", strlen(s), ft_strlen(s));
}

void chk_strlcpy(){
	printf("strlcpy\n");
	// char s1[100] = "hello";
	// char d1[100];
	char s2[100] = "hello";
	char d2[100];
	printf("strlcpy : ft_strlcpy : %ld %s\n", ft_strlcpy(d2, s2, 5));
}

void chk_strlcat(){
	printf("strlcat\n");
	// char s1[100] = "hello";
	// char d1[100] = " world!";
	char s2[100] = "hello";
	char d2[100] = " world!";
	printf("strlcat : ft_strlcat : %ld %s\n", ft_strlcpy(d2, s2, 5));	
}

void chk_strchr(){
	char *s = "Hello";
	int c = '\0';
	printf("%p %p\n", strchr(s,c), ft_strchr(s, c));
}

int main(){
	// strlen
	chk_strlen();

	// strlcpy
	chk_strlcpy();

	// strlcat
	chk_strlcat();

	// strchr
	chk_strchr();
	return 0;
}