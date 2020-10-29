/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 21:23:52 by wopark            #+#    #+#             */
/*   Updated: 2020/10/29 20:04:13 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*proc_flag(t_info *info, char *res)
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

static int	proc_result(const char *format, va_list ap, t_info *info)
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
			flags_parser(format, &info);
			width_parser(format, ap, &info);
			precision_parser(format, ap, &info);
			if (!ft_strchr(CONVERSION, *format))
				return (-1);

		}
	}
	va_end(ap);
	return (ret);
}
