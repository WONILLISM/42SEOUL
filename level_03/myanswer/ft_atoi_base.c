#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int ret;
	int sign;

	ret = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		char c = *str;
		if (c >= 'A' && c <= 'Z')
			c = c - 'A' + 'a';
		if (c >= '0' && c < '0' + str_base)
			ret = ret * str_base + (c - '0');
		else if (str_base > 10 && (c >= 'a' && c <= 'a' + str_base - 10))
			ret = ret * str_base + ((c - 'a') + 10);
		else 
			break;
		str++;
	}

	return sign * ret;
}
int main(){
	// char *str = "10000000000000000000000000000000";
	// char *str = "1111111111111111111111111111111";
	char *str = "-1123a";
	int str_base = 2;
	printf("%d\n",ft_atoi_base(str, str_base));
	return 0;
}