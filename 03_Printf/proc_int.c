/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:58:08 by wopark            #+#    #+#             */
/*   Updated: 2020/11/04 18:20:23 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*process_width(t_info *info, char *c_width, char *res)
{
	int	len;

	len = ft_strlen(res);
	if (info->sign == '\0' && info->width < len)
		return (res);
	if (info->zero == 1 && info->precision == -1 && info->left == 0)
		info->padding = '0';
	if (info->width < len)
		info->width = len;
	if (info->sign && info->width == len)
		(info->width)++;
	if (!(c_width = set_container(info->width, info->padding)))
		return (NULL);
	if (info->left == 1 && info->sign)
		ft_memcpy(c_width + 1, res, len);
	else if (info->left == 1)
		ft_memcpy(c_width, res, len);
	else
		ft_memcpy(&c_width[info->width - len], res, len + 1);
	return (proc_sign(info, c_width, len));
}

static char	*process_precision(t_info *info, char *c_prec,char *res)
{
	int	len;

	len = ft_strlen(res);
	if (res[0] == '0' && info->precision == 0)
		res = "";
	if (info->precision <= len)
		return (res);
	if (!(c_prec = set_container(info->precision, '0')))
		return (NULL);
	ft_memcpy(&c_prec[info->precision - len], res, ft_strlen(res));
	return (c_prec);
}

static int	print_int(t_info *info, char *res)
{
	t_container	*container;

	container = init_container();
	res = set_sign(info, res);
	if (!(res = process_precision(info, container->precision, res))
	|| !(res = process_width(info, container->width, res)))
	{
		free(container);
		return (_ERROR);
	}
	info->n += ft_putstr(res);
	free_container(container);
	return (info->n);
}

int			process_int(va_list ap, t_info *info)
{
	char	*res;

	res = ft_itoa((int)va_arg(ap, int));
	return (print_int(info, res));
}

/*
** %d, %i
** precision
** 1. precision > 들어온 정수값 길이(len) : precision - len 만큼 앞에 0을 채움
** 2.
*/
