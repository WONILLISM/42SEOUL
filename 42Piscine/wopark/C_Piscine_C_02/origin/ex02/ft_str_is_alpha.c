
int		is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int		ft_str_is_alpha(char *str)
{
	int ret;

	ret = 1;
	while (*str)
		if (!is_alpha(*str++))
			ret = 0;
	return (ret);
}
