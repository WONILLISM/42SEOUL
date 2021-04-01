/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 23:51:09 by wopark            #+#    #+#             */
/*   Updated: 2020/10/11 01:05:40 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_free_malloc_error(char **ret)
{
	size_t	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (NULL);
}

static size_t	ft_get_row(char const *s, char c)
{
	size_t	ret;
	size_t	i;

	ret = 0;
	i = 0;
	if (!*s)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			ret++;
			while (s[i] && s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		ret++;
	return (ret);
}

static size_t	ft_get_strlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		i++;
	}
	return (i);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	len;
	size_t	row;
	size_t	i;

	if (!s)
		return (NULL);
	row = ft_get_row(s, c);
	if (!(ret = (char **)malloc(sizeof(char *) * (row + 1))))
		return (NULL);
	i = 0;
	while (i < row)
	{
		while (*s && *s == c)
			s++;
		len = ft_get_strlen(s, c);
		if (!(ret[i] = (char *)malloc(sizeof(char) * len + 1)))
			return (ft_free_malloc_error(ret));
		ft_strlcpy(ret[i], s, len + 1);
		i++;
		if (i < row)
			s += len;
	}
	ret[i] = (NULL);
	return (ret);
}
