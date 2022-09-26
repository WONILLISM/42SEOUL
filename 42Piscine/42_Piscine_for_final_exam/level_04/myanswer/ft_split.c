#include <stdlib.h>
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
	if (!(ret = (char **)malloc(sizeof(char *) * row)))
		return (char **)0;
	while (1)
	{
		if ((is_white_space(*str) || !*str) && len)
		{
			j = 0;
			if (!(ret[i] = (char *)malloc(sizeof(char) * len + 1)))
				return (char **)0;
			while (j < len)
			{
				ret[i][j] = *tmp++;
				j++;
			}
			ret[i][j] = '\0';
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
			ret[i] = NULL;
			break;
		}
		str++;
	}
	return (ret);
}

int     main(void)
{
	// char *str = " abcd. dfdf. aaa$!@#";
	// char *str = "";
	char *str = "\v111\t111\v";

	char **ans;
	ans = ft_split(str);
	if (ans){
		for (int i = 0; ans[i]; i++)
			printf("%s\n", ans[i]);
	}
	return (0);
}