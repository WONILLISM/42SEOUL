#include <stdlib.h>
#include <stdio.h>

int		g_flag;
int		g_row;

int		chk_charset(char c, char *charset)
{
	while (*charset)
		if (c == *charset++)
			return (1);
	return (0);
}

char	*ft_strndup(char *src, int len)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * len)))
		return (0);
	while (src[i] && (i < len))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	alloc_row(char **ret, char *tmp, int flag, int row)
{
	if (!(ret[row] = (char *)malloc(sizeof(char) * (flag + 1))))
		return ;
	ret[row] = ft_strndup(tmp, flag);
}

int		get_row_or_split(char *str, char *charset, char **ret, int mod)
{
	char	*tmp;

	while (*str)
	{
		if (!chk_charset(*str, charset))
		{
			if (!g_flag)
			{
				tmp = str;
				g_row++;
			}
			g_flag++;
		}
		else
		{
			if (g_flag && mod)
				alloc_row(ret, tmp, g_flag, g_row - 1);
			g_flag = 0;
		}
		str++;
	}
	if (g_flag && mod)
		alloc_row(ret, tmp, g_flag, g_row - 1);
	return (g_row);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		row;

	g_flag = 0;
	g_row = 0;
	row = get_row_or_split(str, charset, 0, 0);
	if (!(ret = (char **)malloc(sizeof(char) * row + 1)))
		return (0);
	g_flag = 0;
	g_row = 0;
	get_row_or_split(str, charset, ret, 1);
	if (ret[row - 1])
		(ret);

