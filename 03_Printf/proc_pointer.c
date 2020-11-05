/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:42:00 by wopark            #+#    #+#             */
/*   Updated: 2020/11/05 21:40:54 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*process_precision(t_info *info, char *c_prec, char *res)
{
	int	res_len;
	int	len;

	if (*res == '0' && info->precision == 0)
		res = "";
	if (!res && info->precision != 0)
		res = "0";
	res_len = ft_strlen(res);
	if (info->precision > res_len)
		len = info->precision + 2;
	else
		len = res_len + 2;
	if (!(c_prec = set_container(len,'0')))
		return (NULL);
	ft_memcpy(c_prec, "0x", 2);
	if (info->precision > (int)ft_strlen(res))
		ft_memcpy(&c_prec[len - res_len], res, len);
	else
		ft_memcpy(&c_prec[2], res, len - 2);
	return (c_prec);
}

static char	*process_width(t_info *info, char *c_width, char *res)
{
	int	len;

	len = ft_strlen(res);
	if (info->width <= len)
		return (res);
	if (!(c_width = set_container(info->width, info->padding)))
		return (NULL);
	if (info->left == 1)
		ft_memcpy(c_width, res, len);
	else
		ft_memcpy(&c_width[info->width - len], res, len);
	return (c_width);
}

static int	print_pointer(t_info *info, char *res)
{
	t_container *container;

	container = init_container();
	if (!(res = process_precision(info, container->precision, res))
	|| !(res = process_width(info, container->width, res)))
	{
		free(container);
		return (_ERROR);
	}
	info->n += ft_putstr(res);
	free_container(container);
	return (0);
}

int		process_pointer(va_list ap, t_info *info)
{
	char *res;

	res = ft_lltoa_base((long long int)va_arg(ap, long long), LOWER_HEX);
	return (print_pointer(info, res));
}
