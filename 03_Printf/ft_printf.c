/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 21:23:52 by wopark            #+#    #+#             */
/*   Updated: 2020/10/25 18:02:11 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_parser(const char *format, va_list ap)
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

		}
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = printf_parser(format, ap);
	va_end(ap);
	return (ret);
}
