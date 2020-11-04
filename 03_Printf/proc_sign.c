/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_sign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:20:48 by wopark            #+#    #+#             */
/*   Updated: 2020/11/04 18:20:49 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*set_sign(t_info *info, char *res)
{
	if (*res == '-')
	{
		info->sign = '-';
		res++;
	}
	else if (info->plus == 1)
		info->sign = '+';
	else if (info->space == 1)
		info->sign = ' ';
	return (res);
}

char	*proc_sign(t_info *info, char *container, int len)
{
	if (info->sign == '\0')
		return (container);
	if ((info->zero == 1 && info->precision == -1) || info->left == 1)
		container[0] = info->sign;
	else
		container[info->width - len - 1] = info->sign;
	return (container);
}
