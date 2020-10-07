/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:19:58 by wopark            #+#    #+#             */
/*   Updated: 2020/10/07 19:47:35 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	sign;
	long	res;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	sign = 1;
	res = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		if (sign == -1 && res > 2147483648)
			return (0);
		if (sign == 1 && res > 2147483647)
			return (-1);
		str++;
	}
	return (sign * res);
}
/*
**	line 30 : ft_isdigit(*str) 조건 추가
*/
