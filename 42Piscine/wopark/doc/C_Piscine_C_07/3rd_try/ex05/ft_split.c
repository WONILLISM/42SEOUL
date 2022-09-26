/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 12:39:35 by wopark            #+#    #+#             */
/*   Updated: 2020/08/21 12:55:31 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		checkchar(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int		count(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	if (checkchar(str[0], charset) == 0)
		count++;
	i = 1;
	while (str[i])
	{
		if (checkchar(str[i - 1], charset) == 1
				&& checkchar(str[i], charset) == 0)
			count++;
		i++;
	}
	return (count);
}

char	*ft_strncpy(char *dest, char *src, unsigned int i, unsigned int n)
{
	unsigned int j;

	j = 0;
	while (i < n && src[i])
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

void	ft_fill(char *str, char *charset, char **ret)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (checkchar(str[i], charset) == 1)
			i++;
		count = 0;
		while (!checkchar(str[i], charset) && str[i])
		{
			count++;
			i++;
		}
		ret[j] = (char *)malloc(sizeof(char) * (count + 1));
		ret[j] = ft_strncpy(ret[j], str, i - count, i);
		j++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * (count(str, charset) + 1));
	ft_fill(str, charset, ret);
	ret[count(str, charset)] = 0;
	return (ret);
}
