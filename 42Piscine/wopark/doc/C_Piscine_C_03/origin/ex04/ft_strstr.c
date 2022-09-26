
int		is_same(char *str, char *find_ptr)
{
	while (*find_ptr && *find_ptr == *str)
	{
		find_ptr++;
		str++;
	}
	if (!*find_ptr)
		return (1);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	char *ret;
	char *find_ptr;

	find_ptr = to_find;
	if (!*to_find)
		return str;
	while (*str)
	{
		if (*str == *to_find)
		{
			ret = str;
			if (is_same(ret, find_ptr))
				return (ret);
		}
		str++;
	}
	ret = 0;
	return (ret);
}
