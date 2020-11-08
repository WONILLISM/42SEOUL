/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 21:23:52 by wopark            #+#    #+#             */
/*   Updated: 2020/11/08 17:57:21 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	proc_write(const char *format, va_list ap, t_info *info)
{
	if (*format == 'd' || *format == 'i')
		return (process_int(ap, info));
	if (*format == 'c')
		return (process_char(ap, info));
	if (*format == 's')
		return (process_string(ap, info));
	if (*format == 'u')
		return (process_unsigned_int(ap, info));
	if (*format == 'x' || *format == 'X')
		return (process_hex(ap, info, *format));
	if (*format == 'p')
		return (process_pointer(ap, info));
	if (*format == '%')
		return (process_percent(info));
	if (*format == 'n')
		return (process_n(ap, info));
	else
		return (-1);
}

static void	init_info(t_info *info)
{
	info->left = -1;
	info->plus = -1;
	info->space = -1;
	info->zero = -1;
	info->hash = -1;

	info->width = -1;
	info->precision = -1;

	info->sign = '\0';
	info->padding = ' ';
}

int			ft_printf(const char *format, ...)
{
	t_info	info;
	va_list	ap;

	va_start(ap, format);
	info.n = 0;
	while (*format)
	{
		while (*format != '%' && *format)
			info.n += ft_putchar(*format++);
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
	return (info.n);
}
