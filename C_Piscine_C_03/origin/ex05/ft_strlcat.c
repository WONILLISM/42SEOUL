
unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int d_len;
	unsigned int s_len;
	unsigned int j;
	unsigned int i;

	d_len = 0;
	s_len = 0;
	i = 0;
	while (dest[d_len])
		d_len++;
	j = d_len;
	while (src[s_len])
		s_len++;
	while (src[i])
	{
		dest[j] = src[i];
		i++;
		j++;
		if (j == size - 1)
			break ;
	}
	dest[j] = '\0';
	return (d_len + s_len);
}
