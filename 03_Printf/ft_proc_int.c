/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:58:08 by wopark            #+#    #+#             */
/*   Updated: 2020/10/30 18:45:34 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_int(t_info *info, char *res)
{
	int	ret;

	info->hex = 0;
	ret = ft_strlen(res);
	ft_putstr_fd(res, 1);
	return (ret);
}

// static char	*process_width(t_info *info, char *res)
// {
// 	int len;

// 	len = ft_strlen(res);
// 	if (info->zero == 1 && info->precision == 0 && info->left == 0)
// 		info->padding = '0';
// 	if (info->sign && info->width == len)
// 		(info->width)++;
// 	return (0);
// }

// static char	*process_precision(t_info *info, char *res)
// {

// }

int			process_int(va_list ap, t_info *info)
{
	char	*res;

	if (info->plus == 1)
	{
		*res = info->width >= 0 ? '+' : '-';
		res++;
	}
	res = ft_itoa(((int)va_arg(ap, int)));
	return (print_int(info, res));
}
