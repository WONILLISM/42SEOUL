/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 00:02:50 by wopark            #+#    #+#             */
/*   Updated: 2020/08/20 00:03:57 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_in_charset(char c, char *charset)
{
	int i;

	i = -1;
	while (charset[++i])
	{
		if (charset[i] == c)
			return (1);
	}
	return (0);
}

int		ft_len_end(char *str, char *charset)
{
	int size;

	size = 0;
	while (!ft_in_charset(str[size], charset))
		size++;
	return (size);
}

int		ft_count_str(char *str, char *charset)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (ft_in_charset(str[i], charset)
			&& !ft_in_charset(str[i + 1], charset))
			count++;
	}
	return (count - 1);
}

char	*ft_get_str(char *str, char *charset)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (ft_in_charset(str[i], charset)
			&& !ft_in_charset(str[i + 1], charset))
			return (&str[i + 1]);
	}
	return (&str[i]);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		j;
	int		substr_len;
	int		count;

	count = ft_count_str(str, charset);
	if (!(res = (char **)malloc(((count + 1) * sizeof(char *)))))
		return (NULL);
	i = 0;
	while (i < count)
	{
		str = ft_get_str(str, charset);
		if ((substr_len = ft_len_end(str, charset)))
		{
			if (!(res[i] = (char *)malloc(sizeof(char) * (substr_len + 1))))
				return (NULL);
			j = -1;
			while (++j < substr_len + 1)
				res[i][j] = j == substr_len ? '\0' : str[j];
			i++;
		}
	}
	res[i] = NULL;
	return (res);
}
