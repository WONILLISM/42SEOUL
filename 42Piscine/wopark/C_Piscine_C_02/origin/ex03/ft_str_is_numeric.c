
int	is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_str_is_numeric(char *str)
{
	int ret;

	ret = 1;
	while (*str)
		if (!is_numeric(*str++))
			ret = 0;
	return (ret);
}
