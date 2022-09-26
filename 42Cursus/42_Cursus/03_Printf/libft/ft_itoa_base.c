/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 21:27:40 by wopark            #+#    #+#             */
/*   Updated: 2020/11/10 19:13:13 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len(unsigned int n, int base_len)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(unsigned int n, const char *base)
{
	int				base_len;
	int				len;
	char			*ret;

	len = (n == 0) ? 1 : 0;
	base_len = (unsigned int)ft_strlen((char *)base);
	len += ft_get_len(n, base_len);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	while (len >= 0)
	{
		len--;
		ret[len] = base[n % base_len];
		n /= base_len;
	}
	return (ret);
}
