/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 04:03:03 by wopark            #+#    #+#             */
/*   Updated: 2020/08/13 05:11:23 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_chk_char(char *str, char c)
{
	while (*str)
	{
		if (c == *str++)
			return (1);
	}
	return (0);
}

int		is_valid_of_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
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

int		get_radix(char *base, char c)
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

int		ft_atoi_base(char *str, char *base)
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
	while (ft_chk_char(" \n\t\v\f\r", *str))
		str++;
	while (ft_chk_char("+-", *str))
	{
		if ('-' == *str++)
			sign = sign * -1;
	}
	while ((tmp = get_radix(base, *str)) != -1)
	{
		res = res * radix;
		res = res + tmp;
		str++;
	}
	return (sign * res);
}
