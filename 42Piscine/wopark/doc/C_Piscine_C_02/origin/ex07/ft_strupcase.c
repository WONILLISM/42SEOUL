
int		chk_upcase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int		chk_locase(char c)
{
	return (c >= 'a' && c <= 'z');
}

char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!chk_upcase(str[i]))
		{
			if (chk_locase(str[i]))
			{
				str[i] = str[i] - 'a' + 'A';
			}
		}
		++i;
	}
	str[i] = '\0';
	return (str);
}
