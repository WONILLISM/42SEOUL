
unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int cnt;
	unsigned int i;

	i = 0;
	cnt = 0;
	while (src[cnt])
		cnt++;
	if (size)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (cnt);
}
