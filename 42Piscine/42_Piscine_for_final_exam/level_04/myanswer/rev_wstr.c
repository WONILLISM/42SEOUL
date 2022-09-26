#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int     is_white_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int     get_row_size(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		if (!is_white_space(*str) && (is_white_space(*(str + 1)) || *(str + 1) == '\0'))
			len++;
		str++;
	}
	return (len);
}

char    **ft_split(char *str)
{
	char	**ret;
	char	*tmp;
	int		row;
	int		len;
	int		i;
	int		j;

	len = 0;
	i = 0;
	while (is_white_space(*str))
		str++;
	if (!(row = get_row_size(str)))
		return (char **)0;
	if (!(ret = (char **)malloc(sizeof(char *) * row + 1)))
		return (char **)0;
	while (1)
	{
		if ((is_white_space(*str) || !*str) && len)
		{
			j = 0;
			if (!(ret[row - i - 1] = (char *)malloc(sizeof(char) * len + 1)))
				return (char **)0;
			while (j < len)
			{
				ret[row - i - 1][j] = *tmp++;
				j++;
			}
			ret[row - i - 1][j] = '\0';
			i++;
			tmp = "";
			len = 0;
		}
		if (!is_white_space(*str))
		{
			if (!len)
				tmp = str;
			len++;
		}
		if (!*str)
		{
			ret[row] = NULL;
			break;
		}
		str++;
	}
	return (ret);
}

int     main(int argc, char **argv)
{
	// int		argc = 2;
	// char 	*argv = "le temps du mepris precede celui de l'indifference";
	char	**res;
	int		i;
	int		j;

	if (argc == 2)
	{
		res = ft_split(argv[1]);
		i = 0;
		j = 0;
		while (res[i]!=0)
		{
			j = 0;
			while (res[i][j] != 0)
			{
				write(1, &res[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}