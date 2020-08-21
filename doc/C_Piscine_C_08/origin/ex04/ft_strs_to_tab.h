#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

int						ft_strsize(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void					ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str *answer;

	answer = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (answer == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		answer[i].size = ft_strsize(av[i]);
		answer[i].str = (char *)malloc(answer[i].size + 1);
		ft_strcpy(answer[i].str, av[i]);
		answer[i].copy = (char *)malloc(answer[i].size + 1);
		ft_strcpy(answer[i].copy, av[i]);
		i++;
	}
	answer[i].str = 0;
	return (answer);
}
