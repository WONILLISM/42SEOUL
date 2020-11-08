/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 21:27:40 by wopark            #+#    #+#             */
/*   Updated: 2020/11/08 14:36:42 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_len(unsigned int n)
{
	int	len;

	len = (n == 0) ? 1 : 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_utoa(unsigned int n)
{
	int			len;
	char		*ret;
	long long	tmp;

	len = ft_get_len(n);
	if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ret[len] = 0;
	len--;
	//tmp = n < 0 ? -(long long)n : (long long)n;
	while (len >= 0)
	{
		ret[len] = '0' + tmp % 10;
		tmp /= 10;
		len--;
	}
	return (ret);
}
