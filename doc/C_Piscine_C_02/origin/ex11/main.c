#include<stdio.h>

void ft_putstr_non_printable(char *str);

int main()
{
	char *str;
	char a[2] = {255, '\0'};

	str = "Coucou \ftu vas bien ?";
	//printf("%s\n", str);
	ft_putstr_non_printable(a);

	return 0;
}
