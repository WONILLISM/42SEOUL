
int		check_str(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int		ft_str_is_uppercase(char *str)
{
	int ret;
	int i;

	ret = 1;
	i = 0;
	while (str[i])
	{
		if (!check_str(str[i]))
		{
			ret = 0;
		}
		i++;
	}
	return (ret);
}
