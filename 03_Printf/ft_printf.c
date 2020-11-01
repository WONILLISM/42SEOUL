/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 21:23:52 by wopark            #+#    #+#             */
/*   Updated: 2020/11/01 18:51:03 by wopark           ###   ########.fr       */
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
			ft_memset(&info, 0, sizeof(t_info));
			flags_parser(&format, &info);
			width_parser(&format, ap, &info);
			precision_parser(&format, ap, &info);
			if (!ft_strchr(CONVERSION, *format))
				return (_ERROR);
			if (proc_write(format, ap, &info) == _ERROR)
				return (_ERROR);
		}
	}
	va_end(ap);
	return (ret);
}
