/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:42:01 by wopark            #+#    #+#             */
/*   Updated: 2020/10/31 20:37:17 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*proc_flag(t_info *info, char *res)
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

void	flags_parser(const char **format, t_info *info)
{
	if (**format == '0')
	{
		info->zero = 1;
		(*format)++;
	}
	if (**format == '.')
	{
		info->precision = 1;
		(*format)++;
	}
}

void	width_parser(const char **format, va_list ap, t_info *info)
{
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
