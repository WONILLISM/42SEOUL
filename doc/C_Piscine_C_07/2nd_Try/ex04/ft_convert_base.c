/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 00:02:05 by wopark            #+#    #+#             */
/*   Updated: 2020/08/20 00:02:14 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

int		ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '\t' || base[i] == '\n' || base[i] == '\r'
				|| base[i] == '\v' || base[i] == '\f' || base[i] == ' ')
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int sign;
	int res;
	int bs_len;

	res = 0;
	sign = 1;
	i = 0;
	bs_len = ft_strlen(base);
	while (str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		sign = str[i] == '-' ? sign * -1 : sign;
		i++;
	}
	while (ft_in_base(str[i], base) != -1)
	{
		res = (res * bs_len) + (ft_in_base(str[i], base));
		i++;
	}
	return (res * sign);
}

void	ft_itoa_base(long int nbr, char *cnv_nbr, char *base, int ndx)
{
	int bs_len;

	bs_len = ft_strlen(base);
	cnv_nbr[0] = nbr < 0 ? '-' : cnv_nbr[0];
	nbr = nbr < 0 ? nbr * -1 : nbr;
	if (nbr >= bs_len)
	{
		ft_itoa_base((nbr / bs_len), cnv_nbr, base, ndx - 1);
		cnv_nbr[ndx] = base[nbr % bs_len];
	}
	else if (nbr < bs_len)
		cnv_nbr[ndx] = base[nbr % bs_len];
}
