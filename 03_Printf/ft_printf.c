/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 21:23:52 by wopark            #+#    #+#             */
/*   Updated: 2020/11/04 14:02:47 by wopark           ###   ########.fr       */
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
	else
		return (-1);
}

static void	init_info(t_info *info)
{
	info->left = -1;
	info->width = -1;
	info->precision = -1;
	info->zero = -1;
	info->plus = -1;
	info->space = -1;
	info->hex = -1;

	info->sign = '\0';
	info->padding = ' ';
}

void		print_info(t_info *info)
{
	printf("\n");
	printf("n : %d \n", info->n);
	printf("left : %d \n", info->left);
	printf("plus : %d \n", info->plus);
	printf("space : %d \n", info->space);
	printf("zero : %d \n", info->zero);
	printf("hash : %d \n", info->hash);
	printf("width : %d \n", info->width);
	printf("precision : %d \n", info->precision);
	printf("hex : %d \n", info->hex);
	printf("sign : %c \n", info->sign);
	printf("padding : %c \n", info->padding);
	printf("\n");
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
