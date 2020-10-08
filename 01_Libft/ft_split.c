#include "libft.h"

static int	get_row(char const *s, char c)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			ret++;
		i++;
	}
	return (ret);
}
static int	get_split(char const *s, char c, char **ret)
{
	char	*flag;
	size_t	col;
	size_t	i;

	col = 0;
	i = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!flag)
				flag = (char *)s;
			col++;
			if(*(s + 1) == c || !*(s + 1))
			{
				if (!(ret[i] = (char *)malloc(sizeof(char) * col + 1)))
					return (0);
				ft_strlcpy(ret[i], flag, col);
				i++;
				flag = 0;
				col = 0;
			}
		}
		s++;
	}
	ret[i] = NULL;
	return (1);
}
char		**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	row;

	row = 0;
	while (*s == c)
		s++;
	if (!(row = get_row(s, c)))
		return ((char **)s);
	if (!(ret = (char **)malloc(sizeof(char) * row + 1)))
		return (0);
	if (get_split(s, c, ret))
		return (ret);
	else
		return (0);
}
