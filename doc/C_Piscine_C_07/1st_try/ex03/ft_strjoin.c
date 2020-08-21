/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 01:52:30 by wopark            #+#    #+#             */
/*   Updated: 2020/08/19 01:56:13 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_join_process(char *ret, int size, char **strs, char *sep)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			ret[k++] = strs[i][j++];
		j = 0;
		while ((i < size - 1) && sep[j])
			ret[k++] = sep[j++];
		i++;
	}
	ret[k] = '\0';
	return (ret);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	len = 0;
	if (!size)
	{
		if (!(ret = (char *)malloc(1)))
			return (0);
		ret[0] = '\0';
		return (ret);
	}
	while (i < size)
		len += ft_strlen(strs[i++]);
	if (!(ret = (char *)malloc(sizeof(char) * len + size)))
		return (0);
	return (ft_join_process(ret, size, strs, sep));
}
