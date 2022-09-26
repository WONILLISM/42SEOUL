/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 12:42:53 by wopark            #+#    #+#             */
/*   Updated: 2020/08/21 12:42:53 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_get_size(unsigned int num, int base, int *size)
{
	if (num >= (unsigned int)base)
	{
		ft_get_size(num / base, base, size);
		ft_get_size(num % base, base, size);
	}
	else
		*size = *size + 1;
}

char	*ft_convert_dec_to_base(int dec, char *base_char, int base_len)
{
	char			*convert_to_base;
	unsigned int	num;
	int				size;

	size = 0;
	num = dec;
	if (dec < 0)
	{
		size = 1;
		num *= -1;
	}
	ft_get_size(num, base_len, &size);
	if ((convert_to_base = (char *)malloc(sizeof(char) * size)) == 0)
		return (0);
	if (dec < 0)
		convert_to_base[0] = '-';
	convert_to_base[size] = '\0';
	while (size && !(size == 1 && dec < 0))
	{
		convert_to_base[--size] = base_char[num % base_len];
		num = num / base_len;
	}
	return (convert_to_base);
}
