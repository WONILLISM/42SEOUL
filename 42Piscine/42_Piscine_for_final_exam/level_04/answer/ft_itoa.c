/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 05:13:49 by jaleman           #+#    #+#             */
/*   Updated: 2020/09/17 09:42:11 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_itoa(int nbr)
{
	int		len;
	long	n_tmp;
	char	*str;

	if (nbr == -2147483648)
		return ("-2147483648");
	len = 0;
	n_tmp = nbr;
	while (n_tmp)
	{
		n_tmp /= 10;
		len += 1;
	}
	if (nbr < 0)
	{
		len += 1;
		nbr *= -1;
	}
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] ='\0';
	while (nbr)
	{
		str[len] = (n_tmp % 10) + '0';
		nbr /= 10;
	}
	printf("%s\n", str);
	return (str);
}

int		main(void)
{
	ft_itoa(199);
	return (0);
}