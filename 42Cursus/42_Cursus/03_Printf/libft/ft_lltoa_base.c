/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 21:27:40 by wopark            #+#    #+#             */
/*   Updated: 2020/11/05 21:18:41 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_get_len(long long n, int base_len)
{
	long long	len;

	len = 0;
	while (n)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char					*ft_lltoa_base(long long n, const char *base)
{
	long long		tmp;
	int				len;
	long long		base_len;
	char			*ret;

	tmp = (n < 0) ? -n : n;
	len = (n <= 0) ? 1 : 0;
	base_len = (long long)ft_strlen((char *)base);
	len = ft_get_len(tmp, base_len);
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (0);
	ret[len] = '\0';
	if (n <= 0)
		ret[0] = (n == 0) ? '0' : '-';
	while (n != 0)
	{
		len--;
		ret[len] = (n > 0) ? base[(n % base_len)] : base[-(n % base_len)];
		n = n / base_len;
	}
	return (ret);
}
