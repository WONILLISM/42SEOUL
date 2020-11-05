/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:42:01 by wopark            #+#    #+#             */
/*   Updated: 2020/11/05 21:33:29 by wopark           ###   ########.fr       */
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
	while (ft_strchr(FLAG, **format))
	{
		// printf("\n\n*format: %c \n\n", **format);
		// printf("######## %d %d %d ######\n", info->zero, info->precision, info->left);
		(**format == '-') ? info->left = 1 : 0;
		(**format == '+') ? info->plus = 1 : 0;
		(**format == ' ') ?info->space = 1 : 0;
		(**format == '0') ? info->zero = 1 : 0;
		(**format == '#') ? info->hash = 1 : 0;
		(*format)++;
	}

}

void	width_parser(const char **format, va_list ap, t_info *info)
{
	if (**format != '*' && !ft_strchr(DEMICAL, **format))
		return ;
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
		info->width = (info->width) * -1;
	}
}

void	precision_parser(const char **format, va_list ap, t_info *info)
{
	if (**format != '.')
		return ;
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
