/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 21:23:52 by wopark            #+#    #+#             */
/*   Updated: 2020/10/28 13:18:49 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		chk_format_spcf(const char *f, va_list ap, t_info *info)
{
	while (*f)
	{
		if (ft_memchr(CONVERSION, *f, ft_strlen(CONVERSION)))
		{

		}
		else if (ft_memchr(FLAG, *f, ft_strlen(FLAG)))
		{

		}
		else if (ft_memchr(LEN_MODIFIER, *f, ft_strlen(LEN_MODIFIER)))
		{

		}
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
			format += chk_format_spcf(format, ap, &info);
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
