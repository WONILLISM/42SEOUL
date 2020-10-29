/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:42:01 by wopark            #+#    #+#             */
/*   Updated: 2020/10/29 20:04:17 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_parser(const char **format, t_info *info)
{
	while (ft_strchr(FLAG, **format))
	{
		info->left = (**format == '-') ? 1 : 0;
		info->plus = (**format == '+') ? 1 : 0;
		info->space = (**format == ' ') ? 1 : 0;
		info->zero = (**format == '0') ? 1 : 0;
		info->hash = (**format == '#') ? 1 : 0;
		(*format)++;
	}
}

void	precision_parser(const char **format, va_list ap, t_info *info)
{
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			info->precision = va_arg(ap, int);
			(*format)++;
		}
		else if (ft_strchr(DEMICAL, **format))
		{
			info->precision = ft_atoi(*format);
			while (ft_strchr(DEMICAL, **format))
				(*format)++;
		}
		else
			info->precision = 0;
		if (info->precision < 0)
			info->precision = -1;
	}
}

void	width_parser(const char **format, va_list ap, t_info *info)
{
	if ((**format != '*') || !ft_strchr(DEMICAL, **format))
		return (_ERROR);
	if (**format == '*')
	{
		info->width = va_arg(ap, int);
		(*format)++;
	}
	else
	{
		info->width = ft_atoi(*format);
		while (ft_strchr(DEMICAL, **format))
			(*format)++;
	}
	if (info->width < 0)
	{
		info->left = 1;
		info->width = info->width * -1;
	}
}
