
int		check_str(char c)
{
	return (c >= 'a' && c <= 'z');
}

int		ft_str_is_lowercase(char *str)
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
