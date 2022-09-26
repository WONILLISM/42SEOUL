/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:04:36 by wopark            #+#    #+#             */
/*   Updated: 2020/08/18 15:04:44 by wopark           ###   ########.fr       */
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

int		ft_find_space(char c)
{
	return (ft_chk_char(" \n\t\v\f\r", c));
}

int		ft_find_operator(char c)
{
	return (ft_chk_char("+-", c));
}

int		ft_atoi(char *str)
{
	int res;
	int sign;

	res = 0;
	sign = 1;
	while (ft_find_space(*str))
		str++;
	while (ft_find_operator(*str))
	{
		if ('-' == *str++)
			sign = sign * -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}
