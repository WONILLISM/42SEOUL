/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:06:00 by wopark            #+#    #+#             */
/*   Updated: 2020/08/18 15:06:21 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_nbr_to_base(int nbr, char *base, int radix)
{
	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
	}
	write(1, &base[nbr % radix], 1);, 1);
		}
		nbr = -nbr;
		write(1, "-", 1);
		ft_nbr_to_base(nbr / radix, base, radix);
	}
	else
	{
		if (nbr > radix - 1)
			ft_nbr_to_base(nbr / radix, base, radix);
	}
	write(1, &base[nbr % radix], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int radix;

	radix = is_valid_of_base(base);
	if (!base || radix <= 1)
		return ;
	ft_nbr_to_base(nbr, base, radix);
}
