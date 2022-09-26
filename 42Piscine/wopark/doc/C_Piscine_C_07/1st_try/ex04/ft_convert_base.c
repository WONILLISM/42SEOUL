/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 01:58:31 by wopark            #+#    #+#             */
/*   Updated: 2020/08/19 02:12:01 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern	int	g_i;

int			ft_atoi_base(char *str, char *base)
{
	int radix;
	int res;
	int sign;
	int tmp;

	radix = is_valid_of_base(base);
	if (!base || radix <= 1)
		return (0);
	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
		if ('-' == *str++)
			sign = sign * -1;
	while ((tmp = get_radix(base, *str)) != -1)
	{
		res *= radix;
		res += tmp;
		str++;
	}
	return (sign * res);
}

void		ft_nbr_to_base(int nbr, char *base, int radix, char *ret)
{
	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			ft_nbr_to_base(nbr / radix, base, radix, ret);
			ret[g_i++] = base[-(nbr % radix)];
		}
		else
		{
			nbr = -nbr;
			ret[g_i++] = '-';
			ft_nbr_to_base(nbr / radix, base, radix, ret);
		}
	}
	else
	{
		if (nbr > radix - 1)
			ft_nbr_to_base(nbr / radix, base, radix, ret);
	}
	if (nbr)
		ret[g_i++] = base[nbr % radix];
}

int			is_valid_of_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	return (i);
}

int			get_radix(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}
