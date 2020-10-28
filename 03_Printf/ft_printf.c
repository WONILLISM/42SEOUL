/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 21:23:52 by wopark            #+#    #+#             */
/*   Updated: 2020/10/28 20:55:14 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_parser(const char **format, t_info *info)
{
	while (ft_strchr(FLAG, **format))
	{
		if ()

		format++;
	}
}

int		printf_parser(const char *format, va_list ap)
{
	t_info	info;
	char	tmp;
	int		ret;

	while (*format)
	{
		while (*format != '%' && *format)
			ret += ft_putchar(*format++);
		if (*format == '%')
		{
			format++;
			ft_memset(&info, 0, sizeof(t_info));
			flags_parser(format, &info);
			width_parser(format, &info);
			precision_parser(format, &info);
			if (!ft_strchr(CONVERSION, *format))
				return (-1);
		}
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = printf_parser(format, ap);
	va_end(ap);
	return (ret);
}
