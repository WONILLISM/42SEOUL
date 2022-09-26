
int		is_nonprintable(char c)
{
	return (c < ' ' || c == 127);
}

int		ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (is_nonprintable(*str++))
			return (0);
	}
	return (1);
}