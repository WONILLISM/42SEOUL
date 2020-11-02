/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 21:23:52 by wopark            #+#    #+#             */
/*   Updated: 2020/11/02 21:48:00 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	proc_write(const char *format, va_list ap, t_info *info)
{
	if (*format == 'd' || *format == 'i')
		return (process_int(ap, info));
	else
		return (-1);
}

static void	init_info(t_info *info)
{
	info->hash = -1;
	info->hex = -1;
	info->left = -1;
	info->n = 0;
	info->padding = ' ';
	info->plus = -1;
	info->precision = -1;
	info->prec_sign = -1;
	info->sign = 0;
	info->space = -1;
	info->width = 0;
	info->zero = 0;
}

int			ft_printf(const char *format, ...)
{
	t_info	info;
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = 0;
	while (*format)
	{
		while (*format != '%' && *format)
			ret += ft_putchar(*format++);
		if (*format == '%')
		{
			format++;
			init_info(&info);
			flags_parser(&format, &info);
			width_parser(&format, ap, &info);
			precision_parser(&format, ap, &info);
			if (!ft_strchr(CONVERSION, *format)
			|| proc_write(format, ap, &info) == _ERROR)
				return (_ERROR);
			format++;
		}
	}
	va_end(ap);
	return (ret);
}
